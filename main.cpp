#include <iostream>
#include "BookStore.h"
#include "LinkedQueue.h"
//#include "Person.h"


void PersonTest(Person testP){

    std::cout<<"TESTING GETTERS"<<std::endl;
    std::cout<<"PERSONS NAME: " << testP.getName() << std::endl;
    std::cout<<"PERSONS EMAIL: "<< testP.getEmail() <<std::endl;
    std::cout<<"PERSON PHONE #: "<< testP.getPhone() <<std::endl;
    std::cout<<"PERSONS PREFERENCE: "<<testP.getPref() <<std::endl;

    std::cout<<"\n Testing Setters"<<std::endl;
    testP.setName("Toby");
    std::cout<<"NEW NAME Should be Toby: "<<testP.getName()<<std::endl;
    testP.setEmail("dragon@mail");
    std::cout<<"NEW EMAIL: "<<testP.getEmail()<<std::endl;
    testP.setPhone("654-9872");
    std::cout<<"NEW Phone: "<<testP.getPhone()<<std::endl;
    testP.setPref("phone");
    std::cout<<"NEW PREF: "<<testP.getPref()<<std::endl;
}



int main() {

    std::cout<<"::::::TESTING PERSON CLASS:::::::\n"<<std::endl;
    Person testP = Person("Tim","tclerico@ithaca","354-8976","email");
    PersonTest(testP);



    return 0;
}