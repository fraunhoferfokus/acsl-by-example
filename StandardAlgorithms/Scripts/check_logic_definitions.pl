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

use warnings;
use strict;

use File::Basename;
use File::Spec::Functions qw(catdir abs2rel);
use Cwd qw(abs_path);
use File::Find;
use Term::ANSIColor qw(:constants);
use Getopt::Long;

sub print_help ($)
{
   my ($err_code) = @_;

   print BOLD . basename(__FILE__) . RESET .
         " - Check ACSL logic definitions (from Logic dir) usage\n";
   print "Options: \n";
   print "-s|--show-usage - show files and lines where definition are used (default: no)\n";
   print "-a|--abs-paths  - use absolute paths in output (default: no)\n";
   print "--color=WHEN    - colorize the output: always|never|auto (default: auto)\n";
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
my $show_usage    = 0;
my $color         = 'auto';
my $show_help     = 0;
my $show_license  = 0;

GetOptions(
   "s|show-usage" => \$show_usage,
   "a|abs-paths"  => \$use_abs_paths,
   "color=s"      => \$color,
   "l|license"    => \$show_license,
   "h|help"       => \$show_help
) or die("Error in command line arguments\n");

if (@ARGV) {
   warn "Unknown arguments: " . join(', ', @ARGV) . "\n";
   print_help(1);
}

unless ($color eq 'auto' || $color eq 'never' || $color eq 'always') {
   warn "Unknown value for color argument: $color\n";
   print_help(1);
}

print_license() if $show_license;
print_help(0)   if $show_help;

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

   return wantarray ? @contents : join('', @contents);
}

sub get_topdir
{
   my ($is_abs_path) = @_;
   my $dir = catdir(dirname(__FILE__), '..');
   return $is_abs_path ? abs_path($dir) : $dir;
}

my $varname_re    = qr/[a-zA-Z_]\w*+/;
my $logic_defn_re = qr/\b
   (?:predicate|inductive|type|logic[\wℤ𝔹\s\*]+)
   \s++(?<name>${varname_re})                   # id
   (?:\s*+\{[\s,\w]++\})?                       # label
   (?:\s*+\([\s,\w*]++\))?                      # args
   (?:\s*+reads\s*+                             # reads
       $varname_re\s*+\[[^\]]++\]
       (\s*+,\s*+$varname_re\s*+\[[^\]]++\])*+)?
   (?:\s*+
      (?:;                                      # end
         |
         (?:=\s*+(?:                            # body
            (?:[^\\;]*+\\(?:forall|exists|let)[^;]++;)*+
               [^;]++))\s*+;
         |
         (?:{([^{}]*+(?:(?R)[^{}]*)*+)})        # inductive predicate
      )
   )
/x;

sub get_acsl_defs ($)
{
   my ($file) = @_;
   my $code = read_file $file;
   my @ids;
   while ($code =~ m/$logic_defn_re/g) {
      push @ids, $+{name};
   }
   return @ids;
}

sub trim ($)
{
   return $_[0] =~ s/\A\h++|\h++\Z//gr;
}

sub map_lnr2off ($)
{
   my ($str) = @_;

   my @o = (0);
   my $i = 0;
   while (($i = index($str, "\n", $i)) != -1) {
      push @o, $i;
      ++$i;
   }

   return \@o;
}

sub off2lnr ($$)
{
   my ($map, $offset) = @_;

   my $l = 0;
   my $h = $#$map;
   while ($h - $l > 1) {
      my $n = ($l + $h) >> 1;
      if ($map->[$n] <= $offset) {
         $l = $n;
         $h = $n if $map->[$l] == $offset;
      } else {
         $h = $n;
      }
   }

   return $h;
}

sub get_line ($$;$) {
   my ($text, $start_offset, $end_offset) = @_;
   $end_offset = $start_offset unless $start_offset;

   my $line_begin    = rindex($text, "\n", $start_offset) + 1;
   my $line_end      = index($text, "\n", $end_offset);
   my $line          = substr($text, $line_begin, $line_end - $line_begin);

   return $line;
};


# Gather Definitions
my @logic_files;
find(sub {
      push @logic_files, $File::Find::name;
   }, catdir(get_topdir(1), 'Logic'));

my %defs;
foreach my $file (@logic_files) {
   $defs{$_} = $file foreach get_acsl_defs $file;
}

my @check_files;
find(sub {
      push @check_files, $File::Find::name
         if m/\.(?:acsl|spec|h|cpp|c)$/;
   }, get_topdir(1));

my $detect_ids = '(?:' . join('|', sort keys %defs) . ')';
$detect_ids = qr/$detect_ids/;
my $find_usage = qr/
   \#\h*+include\h*+["<]${detect_ids}\.\w+[">](*SKIP)(*FAIL)
   |
   (?<defn>$logic_defn_re)
   |
   \b(?<name>${detect_ids})\b
/x;
my %usage = map {$_ => {}} keys %defs;
foreach my $file (@check_files) {
   my $contents = read_file $file;
   my $map;
   while ($contents =~ m/$find_usage/g) {
      my $id            = $+{name};
      my ($begin, $end) = ($-[0], $+[0]);
      $map = map_lnr2off $contents unless $map;

      # Check definitions separatedly
      if (exists $+{defn}) {
         my $defn = $+{defn};
         while ($defn =~ m/\b(?<name>${detect_ids})\b/g) {
            my $nid = $+{name};
            next if $nid eq $id;

            my ($nbegin, $nend) = ($begin + $-[0], $begin + $+[0]);
            my $line_nr = off2lnr $map, $nbegin;
            $usage{$nid}{$file}{$line_nr} = trim(get_line($contents, $nbegin, $nend));
         }
      } else {
         my $line_nr = off2lnr $map, $begin;

         $usage{$id}{$file}{$line_nr} = trim(get_line($contents, $begin, $end));
      }
   }
}

sub print_usage ($$;$)
{
   my ($usage, $use_abs_paths, $keys) = @_;

   $keys = [keys %$usage]
      unless $keys && @$keys;

   foreach my $defn (sort @$keys) {
      print GREEN . ${defn} . RESET . " {\n";
      foreach my $file (sort keys %{$usage->{$defn}}) {
         my $path = $use_abs_paths ? $file : abs2rel($file);
         print BLUE . "\t${path}" . RESET . " {\n";
         foreach my $line (sort {$a <=> $b} keys %{$usage->{$defn}{$file}}) {
            print YELLOW . "\t\t${line}:" . RESET . " $usage->{$defn}{$file}{$line}\n";
         }
         print "\t}\n"
      }
      print "}\n";
   }
   print "\n";
}

if ($show_usage) {
   print BOLD . "Logic definitions usage:\n" . RESET;
   print_usage(\%usage, $use_abs_paths);
}

my @only_inside_logic = sort grep {
   my @files = keys %{$usage{$_}};
   my $all   = @files ? 1 : 0;
   foreach my $f (@files) {
      if ($f !~ m/\bLogic\b/) {
         $all = 0;
         last;
      }
   }
   $all;
} keys %usage;
if (@only_inside_logic) {
   print BOLD . "These definitions are internal to Logic folder:\n" . RESET;
   print_usage(\%usage, $use_abs_paths, \@only_inside_logic);
}

my @no_use = sort grep {!%{$usage{$_}}} keys %usage;
print BOLD . "Unused ACSL definitions:" . RESET;
if (@no_use) {
   print "\n - " . RED . join(RESET . "\n - " . RED, @no_use) . RESET . "\n";
   exit 2;
} else {
   print GREEN . " (nothing)\n" . RESET;
}
