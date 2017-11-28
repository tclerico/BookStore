//
// Created by Dylan Shane on 11/28/17.
//

#include "book.h"

/**
 * constructor
 */
book::book(std::string titleIn, int haveIn, int wantIn){
    title = titleIn;
    have = haveIn;
    want = wantIn;
    numPeopleWaiting = 0;
    waitingList = nullptr;
}

/**
 * destructor
 */
book::~book(){
    //TODO
}

/**
 * gets the name of the book
 * @return book title
 */
std::string book::getName(){
    return title;
}

/**
 * gets the have value of the book
 * @return have value
 */
int book::getHave(){
    return have;
}

/**
 * gets the want value of the book
 * @return want value
 */
int book::getWant(){
    return want;
}

/**
 * adds param (num) to books have value
 */
book::addBooks(int num){
    have += num;
}

/**
 * adds param (personToAdd) to LinkedQueue of people
 */
book::addPerson(person personToAdd){
    //TODO
}

/**
 * removes the first person in the queue waiting for the book
 * @return the person's name
 */
std::string book::removePerson(){
    //TODO
}

/**
 * checks if there is a waiting list
 * @return true if there is a waiting list
 */
bool book::hasWaitingList(){
    return (numPeopleWaiting == 0);
}

/**
 * creates a string of the information for the book
 * @return string of book information
 */
std::string book::toString(){
    return title + " have: " + std::to_string(have) + " want: " + std::to_string(want) + " " + std::to_string(numPeopleWaiting) + " people waiting.";
}
