//
// Created by crist on 11/28/2017.
//

#ifndef BOOKSTORE_BOOKSTORE_H
#define BOOKSTORE_BOOKSTORE_H


#include "LinkedList.h"

class BookStore {


private:

    LinkedList* inventory; //linkedList of books
    int numBooks;


public:

    BookStore();

    ~BookStore();

    void add(std::string title, int have, int want); //adds books to the inventory, it will prompt the user for the book's info.

    Book* getBook(std::string title);

    std::string printInventory();


};



#endif //BOOKSTORE_BOOKSTORE_H

