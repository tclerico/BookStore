//
// Created by crist on 11/28/2017.
//


#include "LinkedList.h"
#include "BookStore.h"

#include <iostream>

BookStore::BookStore() {
    inventory = new LinkedList();
    numBooks = 0;
    sorted = false;
}

void BookStore::add(std::string title, int have, int want) {
    Book* bookToAdd = new Book(title, have, want);
    int bookFound = inventory->find(title);
    if (bookFound == -1) {
        inventory->insertAtFront(bookToAdd);
        //inventory->insertAt(bookToAdd);
        numBooks++;
        sorted = false;
    } else {
        std::cout << "That book already exists." << std::endl;
        std::cout << inventory->getBookAt(bookFound)->toString() << std::endl;
    }
}

std::string BookStore::printInventory() {
    if (numBooks == 0){
        return "Our Inventory is empty.";
    } else {
        if (sorted){
            return inventory->toString();
        } else {
            inventory->sort();
            sorted = true;
            return inventory->toString();
        }
    }
}

//MAKE THIS WORK FOR WHEN THE BOOK ISNT IN THE INVENTORY
//can you use a throw for that?
Book* BookStore::getBook(std::string title){
    int found = inventory->find(title);
    if (found >= 0){
        return inventory->getBookAt(found);
    } else {
        return nullptr;
    }
}