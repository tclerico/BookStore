//
// Created by crist on 11/28/2017.
//

#ifndef BOOKSTORE_BOOKSTORE_H
#define BOOKSTORE_BOOKSTORE_H


#include "LinkedInventory.h"

class BookStore {


private:
    Inventory* inventory; //linkedList of books
    int numBooks;
    bool sorted;


public:

    BookStore();

    ~BookStore();

    void readInventory();

    void outputInventory();

    void inquire(std::string title);

    std::string list();

    void add(std::string title, int have, int want); //adds books to the inventory, it will prompt the user for the book's info.

    bool sell(std::string title);

    void modify(std::string title, int numBooks);

    void order();

    void delivery();

    void returnBooks();

    Book* getBook(std::string title);


    //void run();

    void help();

};



#endif //BOOKSTORE_BOOKSTORE_H

