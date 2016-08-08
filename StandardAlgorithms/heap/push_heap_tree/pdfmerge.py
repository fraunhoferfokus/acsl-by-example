from subprocess import call, check_output
import string

print "\nInput:"
dotfiles = check_output(["ls", "./dotheaps/"])
print dotfiles

dotlist = dotfiles.split("\n")

for dotname in dotlist:
	pdfname = dotname[:-3]
	pdfname += "pdf"
	call(["dot", "-Tpdf", "./dotheaps/"+dotname, "-o", "./pdfheaps/"+pdfname])

print "\nOutput:"
print check_output(["ls", "./pdfheaps/"])

print "\nMerged file:\nheapsteps.pdf"
call(["pdfsam-console", "-d", "./pdfheaps/", "-o", "./heapsteps.pdf", "concat"])
