#include "Tester.h"
#include "Interface.h"

void runTest(Tester* test){
    test->PersonTest();
    test->BookTest();
    test->bookStoreTester();
}

void runInterface(Interface* interface){
    interface->run();
}


int main() {

    //Tester* test = new Tester();
    //runTest(test);
    Interface* interface = new Interface();
    runInterface(interface);


    return 0;
}