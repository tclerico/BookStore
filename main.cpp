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

void BookTester(Book tb){
    std::cout<<"TESTING GETTERS"<<std::endl;
    std::cout<<"BOOK NAME: "<<tb.getName()<<std::endl;
    std::cout<<"HAVE VALUE: "<<tb.getHave()<<std::endl;
    std::cout<<"WANT VALIE: "<<tb.getWant()<<std::endl;

    std::cout<<"\nTESTING WAIT LIST"<<std::endl;

    std::cout<<"EMPTY WAIT LIST: "<<tb.hasWaitingList()<<std::endl;

    std::cout<<"ADDING TO WAIT LIST (0 for empty 1 for non-empty"<<std::endl;
    tb.addPerson("tim","mail@mail","653-789","phone");

    std::cout<<"new wait list: "<<tb.hasWaitingList()<<std::endl;

    std::cout<<"ADDING TO WAIT LIST"<<std::endl;
    tb.addPerson("name","email","number","pref");

    std::cout<<"waitList: "<<tb.hasWaitingList()<<std::endl;

    std::cout<<"REMOVING FROM WAITLIST:"<<std::endl;

    std::string rm = tb.removePerson();
    std::cout<<rm<<std::endl;

    rm = tb.removePerson();
    std::cout<<rm<<std::endl;

    //NEED A CHECK IN REMOVE PERSON FOR EMPTY WAIT LIST
    std::cout<<tb.removePerson()<<std::endl;
}



int main() {

    std::cout<<"::::::TESTING PERSON CLASS:::::::\n"<<std::endl;
    Person testP = Person("Tim","tclerico@ithaca","354-8976","email");
    PersonTest(testP);


    std::cout<<"\n::::::::TESTING BOOK CLASS:::::::::::\n"<<std::endl;
    Book testBook = Book("The Catcher in The Rye",5,5);
    BookTester(testBook);


    std::cout << "------------------" << std::endl;
    BookStore* inventory = new BookStore();

    inventory->add("Harry Potter", 6, 4);
    inventory->add("Wuthering Heights", 6, 4);
    inventory->add("Pride and Prejudice", 6, 4);
    inventory->add("Gone With The Wind", 6, 4);
    inventory->add("Les Miserables", 6, 4);
    inventory->add("Hatchet", 3, 7);
    inventory->add("Animals", 6, 4);
    inventory->add("Romeo and Juliet", 6, 4);
    std::cout << inventory->printInventory() << std::endl;

    return 0;
}