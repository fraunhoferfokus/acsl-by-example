#include <Ice/Ice.h>
#include <Printer.h>

using namespace Demo;

class PrinterI : public Printer
{
public:
    virtual void printString(std::string s, const Ice::Current&) override
    {
        std::cout << s << std::endl;
    }
};


int
main(int argc, char* argv[])
{
    try {
        Ice::CommunicatorHolder ich(argc, argv);
        auto adapter = ich->createObjectAdapterWithEndpoints("SimplePrinterAdapter", "default -p 10000");
        auto servant = std::make_shared<PrinterI>();
        adapter->add(servant, Ice::stringToIdentity("SimplePrinter"));
        adapter->activate();
        ich->waitForShutdown();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}

