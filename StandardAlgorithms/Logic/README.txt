Every ACSL predicate, logic function and lemma of the project is defined in
this directory; nothing is defined in an algorithm header.


Extracting all names of predicates, logic functions and lemmas
--------------------------------------------------------------

A crude way, relying on the naming convention
- the names start with a capital letter
- the names do not contain digits
- the names are longer than one character

    sed -e '/^#/d' *.acsl | grep -o "[A-Z][A-z]*" | sort -u | grep -v '^[A-Z]$'

The leading sed drops the preprocessor lines; without it the include guards
would be reported as names.  Note that [A-z] also matches the underscore,
which is what lets a lemma name such as Count_Union through.


Checking that each file has all the includes it needs
-----------------------------------------------------

Each file must be usable on its own.  A C compiler cannot check this, since
the annotations sit inside comments, so let Frama-C parse a translation unit
that includes nothing but the file under test:

    for f in *.acsl ; do
      echo "#include \"$f\"" > probe.c
      frama-c -cpp-extra-args="-I. -I.. -I../Stack -I../MinMax" probe.c \
        > /dev/null 2>&1 || echo "not self-contained: $f"
    done
    rm -f probe.c

A file that fails here still works in the build whenever every one of its
users happens to include the missing header first -- which is exactly what
makes the omission easy to miss.
