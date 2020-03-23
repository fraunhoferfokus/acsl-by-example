# We do not want to create reports for unique_copy, because it does not contain a contract. 
# The test cases still should work for this case. 
# So while we can't put unique_copy in the filelist.path file, we need to use this workaround.

SPECIAL_CASES = unique_copy

# Adds unique_copy/unique_copy.o to the GROUP_OBJECTS
GROUP_OBJECTS = $(join $(addsuffix /,$(SPECIAL_CASES)),$(addsuffix .o,$(SPECIAL_CASES))) 

# Use the double colon to add this line to the overall test target
test:: lib
	$(MAKE) test -sC $(SPECIAL_CASES)
	
# Cleanup for unique_copy
clean::
	$(MAKE) clean -sC $(SPECIAL_CASES) 
include ../group.mk

#DEPENDENCIES += unique_copy/depend.mk
#GROUP_SOURCES += unique_copy/unique_copy.c

#unique/unique_copy.o:
#	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o unique_copy/unique_copy.o unique_copy/unique_copy.c

