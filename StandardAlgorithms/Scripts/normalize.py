#!/usr/bin/env python3


# remove underscore since latex does not allow them in command names
def normalize(name):
    return name.replace('_', '')


# escape underscores in name to be usable in latex
def escape(name):
    return name.replace('_', '\\_')
