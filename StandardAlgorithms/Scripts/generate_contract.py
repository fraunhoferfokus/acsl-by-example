#!/usr/bin/env python3

from sys import argv, exit
from normalize import escape
from adjust_name import adjust_name
from generate_listing import generate_prologue, generate_epilogue

if len(argv) != 2:
    exit("Please, specify the argurment.\nUsage:  <name>".format(argv[0]))

name = argv[1]


def generate_contract(fname):
    name = adjust_name(fname.replace('.h', ''))
    c = generate_prologue(fname)
    c += '\\caption{\label{lst:'
    c += name
    c += ':spec} Formal specification of \\'
    c += name
    c += '}\n'
    c += generate_epilogue()

    # index entry
    command = escape(fname.replace('.h', ''))
    c += '    \index[examples]{'
    c += command
    c += '@\\texttt{'
    c += command
    c += '}}\n'

    return c


if __name__ == '__main__':
    print(generate_contract(name))
