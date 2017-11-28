//
// Created by crist on 11/28/2017.
//

#ifndef BOOKSTORE_BOOKSTORE_H
#define BOOKSTORE_BOOKSTORE_H


#include "LinkedQueue.h"

class BookStore {


private:

    LinkedQueue* inventory; //linkedList of books


public:


    void  add(std::string title, int have, int want); //adds books to the inventory, it will prompt the user for the book's info.


    std::string printInventory();


};



#endif //BOOKSTORE_BOOKSTORE_H

