#!/usr/bin/env python3

from sys import argv, exit
from os.path import isdir, isfile, join, basename, dirname
import re
from normalize import escape, normalize

from generate_listing import generate_prologue, generate_epilogue

if len(argv) != 2:
    exit("Please, specify the argurment.\nUsage:  <name>".format(argv[0]))

name = argv[1]

logic_def = re.compile(
    r"""
\b
	(?:
		lemma|axiom(?:atic)?|
		predicate|inductive|type|
		logic[\wℤ𝔹\s\*]+
	)
\s*\b
	([a-zA-Z_]\w*)""", re.X)

re_axiom = re.compile(r"""axiom\s+([a-zA-Z_]\w*)""", re.X)
re_axiomatic = re.compile(r"""axiomatic\s+([a-zA-Z_]\w*)""", re.X)
re_inductive = re.compile(r"""inductive\s+([a-zA-Z_]\w*)""", re.X)
re_lemma = re.compile(r"""lemma\s+([a-zA-Z_]\w*)""", re.X)
re_predicate = re.compile(r"""predicate\s+([a-zA-Z_]\w*)""", re.X)
re_function = re.compile(r"""logic[\wℤ𝔹\s\*]+\s*\b([a-zA-Z_]\w*)""", re.X)


def find(file, pattern):
    with open(file, 'r') as fh:
        content = fh.read()
        return pattern.findall(content)


def fix_names(raw_names):
    c = ''
    for s in sorted(set(raw_names)):
        c += ' \\'
        c += normalize(s)
    return c


def generate_labels(fname, names):
    c = ''
    for s in names:
        c += '    \label{logic:'
        c += normalize(s)
        c += '}\n'

    file = open(fname, 'w')
    file.write(c)
    file.close()


def generate_index(fname, names):
    c = ''
    for s in names:
        command = escape(s)
        c += '    \index[acsl]{'
        c += command
        c += '@\\texttt{'
        c += command
        c += '}}\n'

    file = open(fname, 'w')
    file.write(c)
    file.close()


def generate_latex2acsl(fname, names):
    c = ''
    for s in names:
        c += normalize(s)
        c += ':'
        c += s
        c += '\n'

    file = open(fname, 'a+')
    file.write(c)
    file.close()


def generate_acsl(fname):
    dname = dirname(fname)
    bname = basename(fname)

    axiom = find(fname, re_axiom)
    axiomatic = find(fname, re_axiomatic)
    function = find(fname, re_function)
    inductive = find(fname, re_inductive)
    lemma = find(fname, re_lemma)
    predicate = find(fname, re_predicate)

    acsl = set()
    acsl = sorted(
        acsl.union(axiom, axiomatic, function, inductive, lemma, predicate))

    generate_labels(bname + '.labels.tex', acsl)
    generate_index(bname + '.index.tex', acsl)
    generate_latex2acsl('latex2acsl.txt', acsl)

    c = generate_prologue(bname)
    c += '\\caption{'
    if (len(axiomatic) == 1):
        c += 'The logic definition(s) '
        c += '\\' + normalize(axiomatic[0])
        c += '\n'
    elif (len(inductive) == 1):
        c += 'Inductive definition '
        c += '\\' + normalize(inductive[0])
        c += '\n'
    else:
        c += 'File \inl{' + bname + '}'
        c += '\\label{logic:' + bname + '}\n'

    c += '}\n'
    c += '\\input{Listings/' + bname + '.labels.tex}\n'
    c += generate_epilogue()
    c += '\n'
    c += '\\input{Listings/' + bname + '.index.tex}\n'

    return c


if __name__ == '__main__':
    print(generate_acsl(name))
