//
// Created by Dylan Shane on 11/28/17.
//

#ifndef BOOKSTORE_BOOK_H
#define BOOKSTORE_BOOK_H

#include <string>
#include "LinkedQueue.h"


class Book {

private:
    std::string title;
    int have;
    int want;
    LinkedQueue* waitingList;
    int numPeopleWaiting;
    Book* next;

public:

    /**
     * constructor
     */
    Book(std::string titleIn, int haveIn, int wantIn);

    /**
     * destructor
     */
    ~Book();

    /**
     * gets the name of the book
     * @return book title
     */
    std::string getName();

    /**
     * gets the have value of the book
     * @return have value
     */
    int getHave();

    /**
     * gets the want value of the book
     * @return want value
     */
    int getWant();

    /**
     * gets the number of people waiting
     * @return num people waiting
     */
    int getNumPeople();

    /**
     * adds param (num) to books have value
     */
    void addBooks(int num);

    /**
     * adds param (personToAdd) to LinkedQueue (waitlist) of people
     */
    void addPerson(std::string name,std::string email, std::string phone,std::string prefer);

    /**
     * removes the first person in the queue waiting for the book
     * @return the person's name
     */
    std::string removePerson();

    /**
     * checks if there is a waiting list
     * @return true if there is a waiting list
     */
    bool hasWaitingList();

    /**
     * creates a string of the information for the book
     * @return string of book information
     */
    std::string toString();

    Book* getNext();

    void setNext(Book* newNext);

};


#endif //BOOKSTORE_BOOK_H
