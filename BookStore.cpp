//
// Created by crist on 11/28/2017.
//


#include "LinkedList.h"
#include "BookStore.h"
#include <iostream>

BookStore::BookStore() {
    inventory = new LinkedList();
    numBooks = 0;
}

void BookStore::add(std::string title, int have, int want) {
    Book* bookToAdd = new Book(title, have, want);
    int bookFound = inventory->find(title);
    if (bookFound == -1) {
        inventory->insertAtFront(bookToAdd);
        numBooks++;
    } else {
        std::cout << "That book already exists." << std::endl;
        std::cout << inventory->getBookAt(bookFound)->toString() << std::endl;
    }
}

std::string BookStore::printInventory() {
    if (numBooks == 0){
        return "Our Inventory is empty.";
    } else {
        for(int i = 0; i < numBooks; i++){
            return inventory->toString();
        }
    }
}