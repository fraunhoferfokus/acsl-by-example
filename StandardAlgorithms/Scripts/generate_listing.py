#!/usr/bin/env python3

def generate_prologue(fname):
	c = '\n'
	c += '\\begin{listing}[hbt]\n'
	c += '\\begin{minipage}{0.99\\textwidth}\n'
	c += '\\lstinputlisting[style=acsl-block, frame=single]{Source/' 
	c += fname
	c += '}\n'
	c += '\\end{minipage}\n'
	return c

def generate_epilogue():
	c = '\\end{listing}\n\n'
	c += '\\FloatBarrier\n'
	return c

