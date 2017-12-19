#include "Tester.h"
#include "Interface.h"

void runTest(){
    Tester* test = new Tester();
    test->PersonTest();
    test->BookTest();
    test->bookStoreTester();
}

void runInterface(){
    Interface* interface = new Interface();
    interface->run();
}


int main() {
    //Uncomment either the tester the interface to run
    runTest();
    //runInterface();


    return 0;
}