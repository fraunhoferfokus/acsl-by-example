
#script needs the algorithm name as input and will create a basic folder structure. That means ist will create the parent folder and inside it will create the *.spec- *.c-, *.h-, *_test.cpp-, *.impl and the Makefile. The parent folder will be created in the curent directory
#version 0.1


name=${1##*/}
#add algorithm to filelist.path
printf "${name}\n" >> filelist.path
mkdir $name
cd $name

#fill files with basic structure
####################################

#fill the *c file
printf "#include \"${name}.h\"\n#include \"${name}.impl\"\n" > ${name}.c

#fill the *.h file
printf "/*\n" >> ${name}.h
printf "For more information about the equal algorithm see\n" >> ${name}.h
printf "http://www.sgi.com/tech/stl/${name}.html\n*/\n" >> ${name}.h
printf "\n#ifndef _${name}_h\n#define _${name}_h\n\n" >> ${name}.h
printf "#ifdef __cplusplus\nextern \"C\"\n" >> ${name}.h
printf "{\n#endif\n\n" >> ${name}.h

#includes


printf "#include \"typedefs.h\"\n\n" >> ${name}.h
printf "#include \"${name}.spec\"\n\n" >> ${name}.h
printf "#ifdef __cplusplus\n}\n#endif\n\n#endif\n\n" >> ${name}.h

#fill *.spec
printf "// insert your specification here\n\n" >> ${name}.spec

#fill *.impl
printf "// insert your implemantation  here\n\n" >> ${name}.impl

#fill *_test.cpp
printf "/*includes*/\n#include \"${name}.h\"\n\n" >> ${name}_test.cpp
printf "#include <cassert>\n\n" >> ${name}_test.cpp
printf "#include <algorithm>\n\n" >> ${name}_test.cpp
printf "#include <iostream>\n\n" >> ${name}_test.cpp
printf "#include <vector>\n\n" >> ${name}_test.cpp
printf "int main(int argc, char** argv)\n" >> ${name}_test.cpp
printf "{\n\n" >> ${name}_test.cpp
printf "  std::cout << \"\\\tsuccessful execution of \" << argv[0] << \"\\\n\";\n" >> ${name}_test.cpp

printf "  return 0;\n}//main\n\n" >> ${name}_test.cpp

#write Makefile
printf "\nFILE=${name}\n\ninclude ../../Makefile.template\n\n" >> Makefile

