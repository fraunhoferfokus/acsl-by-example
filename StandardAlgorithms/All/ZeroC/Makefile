
CXX=c++
CPPFLAGS= -I. -DICE_CPP11_MAPPING
CXXFLAGS= --std=c++14

all: Printer.cpp client server

Printer.cpp: Printer.ice
	slice2cpp $<

Printer_ice.py: Printer.ice
	slice2py $<


Printer.o: Printer.cpp

client: Client.o Printer.o 
	$(CXX) -o $@ $^ -lIce++11

server: Server.o Printer.o 
	$(CXX) -o $@ $^ -lIce++11

clean:
	@$(RM) *.orig
	@$(RM) *.o
	@$(RM) Printer.cpp
	@$(RM) Printer.h
	@$(RM) client
	@$(RM) server

ASTYLEOPTIONS += -A3
ASTYLEOPTIONS += --indent=spaces=4
ASTYLEOPTIONS += --indent-col1-comments
ASTYLEOPTIONS += --min-conditional-indent=0
ASTYLEOPTIONS += --lineend=linux
ASTYLEOPTIONS += --break-closing-braces
ASTYLEOPTIONS += --add-braces
ASTYLEOPTIONS += --pad-oper
ASTYLEOPTIONS += --pad-header

format: FORCE
	@astyle $(ASTYLEOPTIONS) *.cpp



FORCE:

