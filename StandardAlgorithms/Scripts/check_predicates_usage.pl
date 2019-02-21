#!/usr/bin/env perl

# MIT License
# Copyright (c) 2019 Denis Efremov denis.efremov@fokus.fraunhofer.de
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

use warnings;
use strict;

use File::Basename;
use File::Spec::Functions qw(catdir abs2rel);
use Cwd qw(abs_path);
use File::Find;
use Term::ANSIColor qw(:constants);

sub print_help ($)
{
   my ($err_code) = @_;

   print BOLD . basename(__FILE__) . RESET .
         " - Check ACSL logic definitions used in topdir project\n";
   print "Options: \n";
   print "-s|--show-usage - show files and lines where definition used (default: no)\n";
   print "-a|--abs-paths  - use absolute paths in output (default: no)\n";
   print "-n|--no-errcode - don't fail with error code (defalt: no)\n";
   print "-l|--license    - print the license\n";
   print "-h|--help       - print this message\n";

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

my $use_abs_paths = 0;
my $no_errcode    = 0;
my $show_usage    = 0;
my $show_help     = 0;
my $show_license  = 0;

my %v = map {$_ => 1} @ARGV;
if ($v{'-s'} || $v{'--show-usage'}) {
   $show_usage    = 1;
}
if ($v{'-a'} || $v{'--abs-paths'}) {
   $use_abs_paths = 1;
}
if ($v{'-n'} || $v{'--no-errcode'}) {
   $no_errcode    = 1;
}
if ($v{'-l'} || $v{'--license'}) {
   $show_license  = 1;
}
if ($v{'-h'} || $v{'--help'}) {
   $show_help     = 1;
}
delete @v{qw(-s --show-usage -a --abs-paths -n --no-errcode -l --license -h --help)};

if (%v) {
   print "Unknown arguments: " . join(', ', sort keys %v) . "\n";
   print_help(1);
}

print_license() if $show_license;
print_help(0)   if $show_help;

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

   return wantarray ? @contents : join('', @contents);
}

sub get_topdir
{
   my ($is_abs_path) = @_;
   my $dir = catdir(dirname(__FILE__), '..');
   return $is_abs_path ? abs_path($dir) : $dir;
}

my $varname = qr/[a-zA-Z_]\w*+/;
sub get_acsl_defs ($)
{
   my ($file) = @_;

   my $code = read_file $file;
   my @ids = $code =~ m/\b(?|
                           (?:predicate\s++($varname))|
                           (?:inductive\s++($varname))|
                           (?:type\s++($varname))|
                           (?:logic[\wℤ𝔹\s\*]+\b($varname)\s*+[(={])
                        )/gx;
   return @ids;
}

sub trim ($)
{
   return $_[0] =~ s/\A\h++|\h++\Z//gr;
}

my @logic_files;
find(sub {
      push @logic_files, $File::Find::name
         if m/\.[ch]/;
   }, catdir(get_topdir(1), 'Logic'));

my %defs;
foreach my $file (@logic_files) {
   $defs{$_} = $file foreach get_acsl_defs $file;
}

my @check_files;
find(sub {
      push @check_files, $File::Find::name
         if m/\.[ch]$/ && $File::Find::dir !~ m/Logic/;
   }, get_topdir(1));

my $detect = '\b(?:' . join('|', sort keys %defs) . ')\b';
$detect = qr/$detect/;
my %usage;
foreach my $file (@check_files) {
   my @contents = read_file $file;
   while (my ($ln, $line) = each @contents) {
      chomp $line;
      while ($line =~ m/$detect/gp) {
         $usage{${^MATCH}}{$file}{$ln + 1} = trim $line
            unless $line =~ m/\A\h*+#\h*+include\h*+["<]\w++\.\w++[>"]\h*+\Z/;
      }
   }
}

if ($show_usage) {
   print BOLD . "Logic definitions usage:\n" . RESET;
   foreach my $defn (sort keys %usage) {
      print GREEN . ${defn} . RESET . " {\n";
      foreach my $file (sort keys %{$usage{$defn}}) {
         my $path = $use_abs_paths ? $file : abs2rel($file);
         print BLUE . "\t${path}" . RESET . " {\n";
         foreach my $line (sort {$a <=> $b} keys %{$usage{$defn}{$file}}) {
            print YELLOW . "\t\t${line}:" . RESET . " $usage{$defn}{$file}{$line}\n";
         }
         print "\t}\n"
      }
      print "}\n";
   }
   print "\n";
}

my @no_use = sort grep {!%{$usage{$_}}} keys %usage;
print BOLD . "Unused ACSL definitions:" . RESET;
if (@no_use) {
   print "\n - " . RED . join(RESET . "\n - " . RED, @no_use) . RESET . "\n";
   exit 2 unless $no_errcode;
} else {
   print GREEN . " (nothing)\n" . RESET;
}
