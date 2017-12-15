
A crude way to extract all names of predicates and logic functions.
It relies on the assumptions
- the names start with a capital letter
- the name do not contain numbers
- the names are longer than one character 

grep -o "[A-Z][A-z]*" *.spec | cut -d : -f 2 | sort | uniq | grep -v '^[A-Z]$'



To check that each file has all includes needed:

for i in *.h ; do echo +++++ $i +++++ ; cc -Wall -c -I.. $i ; done

