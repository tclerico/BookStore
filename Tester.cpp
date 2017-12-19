//
// Created by Dylan Shane on 12/18/17.
//

#include "Tester.h"
#include "Person.h"
#include "Book.h"
#include "BookStore.h"
#include <iostream>

using namespace std;

void Tester::PersonTest(){
    std::cout<<"::::::TESTING PERSON CLASS:::::::\n"<<std::endl;
    Person* testP = new Person("Tim","tclerico@ithaca","354-8976","email");


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

    std::cout << "\n------------------" << std::endl;
}

void Tester::BookTest() {
    std::cout<<"\n::::::::TESTING BOOK CLASS:::::::::::\n"<<std::endl;
    Book* tb = new Book("The Catcher in The Rye",5,5);

    std::cout << "TESTING GETTERS" << std::endl;
    std::cout << "BOOK NAME: " << tb->getName() << std::endl;
    std::cout << "HAVE VALUE: " << tb->getHave() << std::endl;
    std::cout << "WANT VALIE: " << tb->getWant() << std::endl;

    std::cout << "\nTESTING ADD BOOKS:" << std::endl;

    std::cout << tb->toString() << std::endl;

    tb->addBooks(3);

    std::cout << tb->toString() << std::endl;

    std::cout << "\n--TESTING WAIT LIST--" << std::endl;

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
    std::cout << "\n------------------" << std::endl;
}

void Tester::bookStoreTester() {
    std::cout<<"\n::::::::TESTING BOOKSTORE:::::::::::\n"<<std::endl;
    BookStore* store = new BookStore();
    store->readInventory();
    using namespace std;
    std::cout<< store->list()<< std::endl;

    cout<<"TESTING SELL: A Darker Shade of Magic"<<endl;
    int numbooks = store->getBook("A Darker Shade of Magic")->getHave();
    store->sell("A Darker Shade of Magic");
    cout<<"HAVE SHOULD EQUAL " << numbooks-1 << endl;
    store->inquire("A Darker Shade of Magic");

    cout<<"\nTesting Add"<<endl;
    store->add("Test Book",56,2);
    store->inquire("Test Book");

    cout<<"\nTesting Return"<<endl;
    store->returnBooks();
    cout<<"All books with want values less than have values should be equal now:"<<endl;
    cout << store->list() << endl;

    cout<<"\nTesting Modify"<<endl;
    store->modify("Test Book", 7);
    cout<<"WANT SHOULD EQUAL 7"<<endl;
    store->inquire("Test Book");

    cout<<"\nTesting Order and Delivery"<<endl;
    store->order();
    cout<<"All books should now have equal haves and wants (because we did a also did a return previously) :"<<endl;
    store->delivery();
    cout << store->list() << endl;
}
