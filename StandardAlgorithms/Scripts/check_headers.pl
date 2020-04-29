#!/usr/bin/env perl

# MIT License
# Copyright (c) 2019 Denis Efremov efremov@linux.com
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

use strict;
use warnings;

use re '/aa';

use File::Find;
use File::Basename;
use File::Spec::Functions qw(catfile splitpath catdir abs2rel);
use Cwd qw(abs_path cwd);
use Term::ANSIColor qw(:constants);
use Getopt::Long;

eval {
   require Graph::Directed;
};

if ($@) {
   die "The script requires Graph module to be installed.\n"   .
       "It can be installed in one of the following ways:\n"   .
       "1) On Fedora: sudo dnf install perl-Graph\n"           .
       "2) On Ubuntu/Debian: sudo apt install libgraph-perl\n" .
       "3) Other: cpan install Graph\n";
}

sub print_help ($)
{
   my ($err_code) = @_;

   print BOLD . basename(__FILE__) . RESET .
         " - Check headers usage in the project\n";
   print "Options: \n";
   print "-c|--c2h     - print map: c_file => [h_file1, ...]\n";
   print "-2|--h2c     - print map: h_file => [c_file1, ...]\n";
   print "--color=WHEN - colorize the output: always|never|auto (default: auto)\n";
   print "-v|--verbose - print all failed to find headers\n";
   print "-l|--license - print the license\n";
   print "-h|--help    - print this message\n";

   exit $err_code;
}

sub print_license ()
{
   open my $self, '<', $0;
   my @l;
   my $first = 0;
   while (<$self>) {
      chomp;
      unless ($first) {
         if ($_ =~ /\A\#.*?license/i) {
            push @l, $_;
            $first++;
         }
      } else {
         if ($_ =~ /\A\#/) {
            push @l, $_;
         } else {
            last;
         }
      }
   }
   close $self;
   print join("\n", map {s/\A#\h*+//r} @l) . "\n";
   exit 0;
}


my $help              = 0;
my $license           = 0;
my $color             = 'auto';
my $print_all_headers = 0;
my $print_h_to_c      = 0;
my $print_c_to_h      = 0;

GetOptions(
   "c|c2h"     => \$print_c_to_h,
   "2|h2c"     => \$print_h_to_c,
   "color=s"   => \$color,
   "v|verbose" => \$print_all_headers,
   "l|license" => \$license,
   "h|help"    => \$help
) or print_help(1);

if (@ARGV) {
   warn("Unknown arguments: " . join(", ", @ARGV), "\n");
   print_help(1);
}

unless ($color eq 'auto' || $color eq 'never' || $color eq 'always') {
   warn "Unknown value for color argument: $color\n";
   print_help(1);
}

print_license() if $license;
print_help(0) if $help;

if ($color eq 'auto') {
   if (-t STDOUT) {
      $color = 'always';
   } else {
      $color = 'never';
   }
}

if ($color eq 'never') {
   $ENV{'ANSI_COLORS_DISABLED'} = 'y';
} elsif ($color eq 'always') {
   delete $ENV{'ANSI_COLORS_DISABLED'};
}

sub read_file ($)
{
   my ($fname)  = @_;
   my @contents;

   if (open my $fh, '<', $fname) {
      @contents = <$fh>;
      close $fh or die "Can't close the file '$fname'.\n";
   } else {
      die "Can't open file '$fname' with error '$!'.\n";
   }

   return \@contents;
}

sub get_topdir
{
   my ($is_abs_path) = @_;
   my $dir = catdir(dirname(__FILE__), '..');
   return $is_abs_path ? abs_path($dir) : $dir;
}

sub print_map ($$)
{
   my ($title, $map) = @_;

   print BOLD . "Map: " . $title . RESET . "\n";
   foreach my $f (sort keys %$map) {
      print "\t" . BLUE . $f . RESET . " {\n";
      print "\t\t- " . YELLOW . join(RESET . "\n\t\t- " . YELLOW, @{$map->{$f}}) . RESET . "\n"
         if @{$map->{$f}};
      print "\t}\n";
   }
}


my $topdir   = get_topdir(1);
my $logicdir = catdir($topdir, 'Logic');
my $cwd      = cwd();
my %alldirs;
my %files;
find(sub {
      $files{abs_path($File::Find::name)} = {
         dir  => $File::Find::dir,
         name => abs2rel($File::Find::name, $topdir),
         file => read_file($File::Find::name)
      }
      if $_ =~ /\.(?:acsl|spec|h|c|cpp)\Z/;

      $alldirs{$File::Find::dir} = 1;
   },
   $topdir
);
my @alldirs = sort {length($a) <=> length($b)} keys %alldirs;

my $g = Graph::Directed->new();
my $err_code = 0;
foreach my $f (values %files) {
   $g->add_vertex($f->{name});

   foreach my $i (map {/\A\h*+#\h*+include\h*+([<"][^">]++)[">]/ ? $1 : ()} @{$f->{file}}) {
      my $br    = substr($i, 0, 1, '');
      my $is_h  = $i =~ m/\.(?:acsl|spec|h)$/;
      my $found = 0;
      foreach my $dir ($f->{dir}, $logicdir, @alldirs) {
         my $if = abs_path(catfile($dir, $i));
         if ($if && ( -f $if || -l $if ) && $files{$if}) {
            $g->add_edge($files{$if}{name}, $f->{name});
            $found = 1;
            last;
         }
      }
      if (!$found && ($is_h || $print_all_headers)) {
         my %filter = map {$_ => 1} ($print_all_headers ? () : qw(stdlib.h limits.h assert.h stdio.h));
         warn BOLD . "FAIL:" . RESET
            . " can't find include " . RED . $i . RESET
            . " from " . $f->{name} . "\n"
            unless $filter{$i};
         $err_code = 1;
      }
   }
   # Free memory
   delete $f->{file};
}

my %h_to_c;
my $cfile_re = qr/\.(?:c|cpp)\Z/;
foreach my $v ($g->vertices()) {
   next
      if $v =~ $cfile_re;

   $h_to_c{$v} = [sort grep {m/$cfile_re/} $g->all_successors($v)]
}

if ($print_h_to_c) {
   print_map("header file => [list of C files]", \%h_to_c);
}

if ($print_c_to_h) {
   my %c_to_h;
   # build a reverse map
   foreach my $h (keys %h_to_c) {
      foreach my $c (@{$h_to_c{$h}}) {
         push @{$c_to_h{$c}}, $h;
      }
   }

   # sort
   foreach my $h (keys %c_to_h) {
      $c_to_h{$h} = [sort @{$c_to_h{$h}}];
   }

   print_map("C file => [list of headers]", \%c_to_h);
}

my @isolated = sort grep {m/\.(?:acsl|spec|h)\Z/} $g->isolated_vertices();
if (@isolated) {
   print BOLD . "Isolated (no one uses them) header files: \n" . RESET;
   print "\t - " . RED . join(RESET . "\n\t - " . RED, @isolated) . RESET . "\n\n";
   $err_code = 2;
}

my %isolated_check = map {$_ => 1} @isolated;
my @not_included = sort grep {!@{$h_to_c{$_}} && !$isolated_check{$_}} keys %h_to_c;
if (@not_included) {
   print BOLD . "Not used by C files: \n" . RESET;
   print "\t - " . RED . join(RESET . "\n\t - " . RED, @not_included) . RESET . "\n\n";
   $err_code = 3;
}

exit $err_code;
