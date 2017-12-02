//
// Created by Dylan Shane on 11/28/17.
//

#include "Book.h"
//#include "Person.h"

/**
 * constructor
 */
Book::Book(std::string titleIn, int haveIn, int wantIn){
    title = titleIn;
    have = haveIn;
    want = wantIn;
    numPeopleWaiting = 0;
    waitingList = nullptr;
}

/**
 * destructor
 */
Book::~Book(){
    //TODO
}

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

/**
 * adds param (num) to books have value
 */
void Book::addBooks(int num){
    have += num;
}

/**
 * adds param (personToAdd) to LinkedQueue of people
 */
void Book::addPerson(std::string name,std::string email, std::string phone,std::string prefer){
    //TODO
}

/**
 * removes the first person in the queue waiting for the book
 * @return the person's name
 */
std::string Book::removePerson(){
    //TODO
}

/**
 * checks if there is a waiting list
 * @return true if there is a waiting list
 */
bool Book::hasWaitingList(){
    return (numPeopleWaiting == 0);
}

/**
 * creates a string of the information for the book
 * @return string of book information
 */
std::string Book::toString(){
    return title + " have: " + std::to_string(have) + " want: " + std::to_string(want) + " " + std::to_string(numPeopleWaiting) + " people waiting.";
}
