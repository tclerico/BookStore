#include <iostream>
#include "BookStore.h"
#include "LinkedQueue.h"
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


    store->add("Harry Potter", 6, 4);
    store->add("Wuthering Heights", 2, 4);
    store->add("Pride and Prejudice", 3, 4);
    store->add("Gone With The Wind", 6, 1);
    store->add("Les Miserables", 2, 4);
    store->add("The Hate U Give", 3, 4);
    store->add("Voltaire", 6, 4);
    store->add("Hatchet", 3, 7);
    store->add("Animals", 6, 7);
    store->add("Milk and Honey", 6, 4);
    store->add("Romeo and Juliet", 6, 4);
    std::cout << store->list() << std::endl;
}



int main() {

    std::cout<<"::::::TESTING PERSON CLASS:::::::\n"<<std::endl;
    Person* testP = new     Person("Tim","tclerico@ithaca","354-8976","email");
    PersonTest(testP);

    std::cout << "\n------------------" << std::endl;

    std::cout<<"\n::::::::TESTING BOOK CLASS:::::::::::\n"<<std::endl;
    Book* testBook = new Book("The Catcher in The Rye",5,5);
    BookTester(testBook);


    std::cout << "\n------------------" << std::endl;
    std::cout<<"\n::::::::TESTING BOOKSTORE:::::::::::\n"<<std::endl;
    BookStore* inventory = new BookStore();
    bookStoreTester(inventory);

    std::cout<<"Sell testing"<<std::endl;
    inventory->sell("Gone With The Wind");

    Book* book = inventory->getBook("Gone With The Wind");

    if(book->getHave() == 5){
        std::cout<<"Passed: book sold";
    }

    inventory->sell("This Book Doesnt Exist");

    Book* test = inventory->getBook("This Book Doesnt Exist");

    std::cout<< test->toString() << std::endl;
    std::cout<<"new title waitlist: " << test->hasWaitingList()<<std::endl;



    return 0;
}