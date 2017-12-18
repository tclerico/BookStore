#include <iostream>
#include "BookStore.h"
#include "LinkedQueue.h"

#include <fstream>
#include <string>
#include <cstdlib> // for exit()

//#include "Person.h"


void PersonTest(Person* testP){

    std::cout<<"TESTING GETTERS"<<std::endl;
    std::cout<<"PERSONS NAME: " << testP->getName() << std::endl;
    std::cout<<"PERSONS EMAIL: "<< testP->getEmail() <<std::endl;
    std::cout<<"PERSON PHONE #: "<< testP->getPhone() <<std::endl;
    std::cout<<"PERSONS PREFERENCE: "<<testP->getPref() <<std::endl;

    std::cout<<"\n Testing Setters"<<std::endl;
    testP->setName("Toby");
    std::cout<<"NEW NAME Should be Toby: "<<testP->getName()<<std::endl;
    testP->setEmail("dragon@mail");
    std::cout<<"NEW EMAIL: "<<testP->getEmail()<<std::endl;
    testP->setPhone("654-9872");
    std::cout<<"NEW Phone: "<<testP->getPhone()<<std::endl;
    testP->setPref("phone");
    std::cout<<"NEW PREF: "<<testP->getPref()<<std::endl;
}

void BookTester(Book* tb) {
    std::cout << "TESTING GETTERS" << std::endl;
    std::cout << "BOOK NAME: " << tb->getName() << std::endl;
    std::cout << "HAVE VALUE: " << tb->getHave() << std::endl;
    std::cout << "WANT VALIE: " << tb->getWant() << std::endl;

    std::cout << "\nTESTING ADD BOOKS:" << std::endl;

    std::cout << tb->toString() << std::endl;

    tb->addBooks(3);

    std::cout << tb->toString() << std::endl;

    std::cout << "\n--TESTING WAIT LIST--" << std::endl;

    /*std::cout<<"EMPTY WAIT LIST: "<<tb.hasWaitingList()<<std::endl;

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
    std::cout<<tb.removePerson()<<std::endl;*/
    bool passed = true;

    std::cout << "\nTESTING ADD: ";

    for (int i = 0; i < 5; i++) {
        tb->addPerson("person " + std::to_string(i), std::to_string(i) + "@mail", "123-456-7890", "phone");
    }

    if (tb->getNumPeople() != 5) {
        passed = false;
    }

    if (passed) {
        std::cout << "passed" << std::endl;
    } else {
        std::cout << "failed" << std::endl;
        passed = true;
    }

    std::cout << "\nTESTING REMOVE: ";

    for (int i = 0; i < 5; i++) {
        tb->removePerson();
    }

    if (tb->hasWaitingList()) {
        passed = false;
    }

    if (passed) {
        std::cout << "passed." << std::endl;
    } else {
        std::cout << "failed." << std::endl;
        passed = true;
    }
}

void bookStoreTester(BookStore* store) {
    using namespace std;
    std::cout<< store->list()<< std::endl;

    cout<<"TESTING SELL: A Darker Shade of Magic"<<endl;
    store->sell("A Darker Shade of Magic");
    cout<<"HAVE SHOULD EQUAL 4"<<endl;
    store->inquire("A Darker Shade of Magic");

    cout<<"\nTesting Add"<<endl;
    store->add("Test Book",56,2);
    store->inquire("Test Book");

    store->returnBooks();
    store->inquire("Test Book");

    store->order();
    store->delivery();


}



int main() {

    std::cout<<"::::::TESTING PERSON CLASS:::::::\n"<<std::endl;
    Person* testP = new Person("Tim","tclerico@ithaca","354-8976","email");
    PersonTest(testP);

    std::cout << "\n------------------" << std::endl;

    std::cout<<"\n::::::::TESTING BOOK CLASS:::::::::::\n"<<std::endl;
    Book* testBook = new Book("The Catcher in The Rye",5,5);
    BookTester(testBook);


    std::cout << "\n------------------" << std::endl;
    std::cout<<"\n::::::::TESTING BOOKSTORE:::::::::::\n"<<std::endl;
    BookStore* inventory = new BookStore();
    inventory->readInventory();
    bookStoreTester(inventory);

    return 0;
}