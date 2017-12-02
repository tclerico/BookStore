//
// Created by crist on 11/28/2017.
//


#include "LinkedList.h"
#include "Book.h"
#include "BookStore.h"

BookStore::BookStore() {
    inventory = new LinkedList();
    numBooks = 0;
}

void BookStore::add(std::string title, int have, int want) {
    Book bookToAdd = new Book(title, have, want);
    inventory->
}