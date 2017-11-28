//
// Created by Dylan Shane on 11/28/17.
//

#ifndef BOOKSTORE_BOOK_H
#define BOOKSTORE_BOOK_H


class book {

private:
    std::string title;
    int have;
    int want;
    //LinkedQueue people;
    int numPeopleWaiting;

public:

    /**
     * constructor
     */
    book();

    /**
     * destructor
     */
    ~book();

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
     * adds param (num) to books have value
     */
    addBooks(int num);

    /**
     * adds param (personToAdd) to LinkedQueue of people
     */
    addPerson(person personToAdd);

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

};


#endif //BOOKSTORE_BOOK_H
