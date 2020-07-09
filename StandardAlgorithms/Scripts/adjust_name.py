#!/usr/bin/env python3

from sys import argv, exit
from normalize import normalize

if len(argv) != 2:
    exit("Please, specify the argurment.\nUsage:  <name>".format(argv[0]))

name = argv[1]


def adjust_name(input):
    name = normalize(input)
    for s in ['copy', 'count', 'fill', 'iota', 'rotate']:
        if s == name:
            name = s + 'i'
    name = name.replace('2', 'ii')
    name = name.replace('3', 'iii')
    name = name.replace('4', 'iv')
    name = name.replace('5', 'v')
    return name


if __name__ == '__main__':
    print(adjust_name(name))
