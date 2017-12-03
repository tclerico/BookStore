//
// Created by Dylan Shane on 11/28/17.
//

#include "Book.h"


/**
 * constructor
 */
Book::Book(std::string titleIn, int haveIn, int wantIn){
    title = titleIn;
    have = haveIn;
    want = wantIn;
    numPeopleWaiting = 0;
    waitingList = new LinkedQueue(); //should waitlist point to the begining of the queue?
    next = nullptr;
}

/**
 * destructor
 */
Book::~Book(){
    //TODO
}

//GETTERS

/**
 * gets the name of the book
 * @return book title
 */
std::string Book::getName(){
    return title;
}

/**
 * gets the have value of the book
 * @return have value
 */
int Book::getHave(){
    return have;
}

/**
 * gets the want value of the book
 * @return want value
 */
int Book::getWant(){
    return want;
}

//SETTERS




/**
 * adds param (num) to books have value
 */
void Book::addBooks(int num){
    have += num;
}

/**
 * adds param (personToAdd) to LinkedQueue of people
 */
//this function will need to prompt the user to enter all info about person being added
void Book::addPerson(std::string name,std::string email, std::string phone,std::string prefer){
    Person* personToAdd  = new Person(name,email,phone,prefer);
    if(waitingList==nullptr){
        waitingList = new LinkedQueue();
        waitingList->enqueue(personToAdd);
        numPeopleWaiting+=1;
    }else{
        waitingList->enqueue(personToAdd);
        numPeopleWaiting+=1;
    }
}

/**
 * removes the first person in the queue waiting for the book
 * @return the person's name
 */
std::string Book::removePerson(){
    if (hasWaitingList()) {
        std::string removed = waitingList->dequeue();
        numPeopleWaiting -= 1;
        return removed;
    } else {
        return "the queue is empty";
    }
}

/**
 * checks if there is a waiting list
 * @return true if there is a waiting list
 */
bool Book::hasWaitingList(){
    if (numPeopleWaiting == 0){
        return false;
    }else{
        return true;
    }
    //return (numPeopleWaiting == 0);
}

/**
 * creates a string of the information for the book
 * @return string of book information
 */
std::string Book::toString(){
    return title + " have: " + std::to_string(have) + " want: " + std::to_string(want) + " " + std::to_string(numPeopleWaiting) + " people waiting.";
}

Book* Book::getNext(){
    return next;
}

void Book::setNext(Book* newNext){
    next = newNext;
}
