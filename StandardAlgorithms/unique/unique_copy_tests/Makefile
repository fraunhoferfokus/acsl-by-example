
# note that .c files are soft-linked to .cpp file
# this is for easier fromatting in the latex sources

CPPFLAGS += -DUNIQUE_COPY_GENERIC
CXXFLAGS += -std=c++17 -O3 -Wall -Wextra -Werror -pedantic

test: iotest_Indexed iotest_vector\
      unique_copy_basic_test unique_copy_compare_test unique_copy_partition_test
	@./unique_copy_basic_test test-data-basic.txt
	@./unique_copy_compare_test test-data-compare.txt
	@./unique_copy_partition_test test-data-basic.txt

iotest_vector:
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $@.cpp

iotest_Indexed:
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $@.cpp

unique_copy_basic_test: 
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $@.cpp

unique_copy_compare_test: 
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $@.cpp

unique_copy_partition_test: 
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $@.cpp

verify:
	@echo "nothing to verify in $(PWD)"

clean:
	@$(RM) iotest_vector
	@$(RM) iotest_Indexed
	@$(RM) unique_copy_basic_test
	@$(RM) unique_copy_compare_test
	@$(RM) unique_copy_partition_test
	@$(RM) *.o
	@$(RM) *.orig


ASTYLEOPTIONS += -A3
ASTYLEOPTIONS += --indent=spaces=2
ASTYLEOPTIONS += --indent-col1-comments
ASTYLEOPTIONS += --min-conditional-indent=0
ASTYLEOPTIONS += --lineend=linux
ASTYLEOPTIONS += --break-closing-braces
ASTYLEOPTIONS += --add-braces
ASTYLEOPTIONS += --pad-oper
ASTYLEOPTIONS += --pad-header

format: FORCE
	@astyle $(ASTYLEOPTIONS) *.h *.cpp *.c


FORCE:

