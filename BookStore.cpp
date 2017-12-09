//
// Created by crist on 11/28/2017.
//


#include "LinkedList.h"
#include "BookStore.h"
#include <fstream>
#include <cstdlib>
#include <iostream>

BookStore::BookStore() {
    inventory = new LinkedList();
    numBooks = 0;
    sorted = false;
}

void BookStore::add(std::string title, int have, int want) {
    int bookFound = inventory->find(title);
    if (bookFound == -1) {
        Book* bookToAdd = new Book(title, have, want);
        //inventory->insertAtFront(bookToAdd);
        inventory->insert(bookToAdd);
        numBooks++;
        outputInventory();
        //sorted = false;
    } else {
        std::cout << "That book already exists." << std::endl;
        std::cout << inventory->getBookAt(bookFound)->toString() << std::endl;
    }
}

std::string BookStore::list() {
    if (numBooks == 0){
        return "Our Inventory is empty.";
    } else {
        return inventory->toString();
        /*if (sorted){
            return inventory->toString();
        } else {
            //inventory->sort();
            //sorted = true;
            return inventory->toString();
        }*/
    }
}

Book* BookStore::getBook(std::string title){
    int found = inventory->find(title);
    if (found >= 0){
        return inventory->getBookAt(found);
    } else {
        return nullptr;
    }
}


bool BookStore::sell(std::string title){
    Book* bookToSell = getBook(title);
    if (bookToSell != nullptr && bookToSell->getHave() > 0){
        getBook(title)->sell();
        return true;
    } else {
        return false;
    }
}


void BookStore::readInventory() {
    std::ifstream myFile("books.txt");

    if (!myFile){
        std::cout << "Error. Could not find data." << std::endl;
        exit(1);
    }
    while (!myFile.eof()){
        std::string title;
        std::string want;
        std::string have;
        std::string waiting;
        getline(myFile, title);
        getline(myFile, want);
        getline(myFile, have);
        getline(myFile, waiting);

        //need these two lines on windows for the titles to be read in
        int len = title.length();
        title.erase(len-1,len);

        add(title, std::stoi(want), std::stoi(have));
        if (waiting == "yes"){
            //TODO
            std::string numWaiting;
            getline(myFile, numWaiting);
            int numPeople = std::stoi(numWaiting);
            for (int i = 0; i < numPeople; i++){
                std::string name;
                std::string phone;
                std::string email;
                std::string prefer;
                getline(myFile, name);
                getline(myFile, phone);
                getline(myFile, email);
                getline(myFile, prefer);
                getBook(title)->addPerson(name, email, phone, prefer);
            }
        }
    }
}

void BookStore::outputInventory() {
    std::ofstream outf;
    outf.open("books.txt");

    if (!outf){
        std::cout << "Error. Could not find data." << std::endl;
        exit(1);
    }

    for (int i = 0; i < inventory->itemCount(); i++) {
        Book *book = inventory->getBookAt(i);
        if (book->getWant() > 0) {
            outf << book->getName() << std::endl;
            outf << book->getHave() << std::endl;
            outf << book->getWant() << std::endl;
            if (book->hasWaitingList()) {
                outf << "yes"<< std::endl;;
                int numPeople = book->getNumPeople();
                outf << numPeople << std::endl;
                for (int j = 0; j < numPeople; j++) {
                    Person *person = book->removePerson();
                    outf << person->getName() << std::endl;
                    outf << person->getPhone() << std::endl;
                    outf << person->getEmail() << std::endl;
                    if (i == inventory->itemCount() - 1) {
                        outf << person->getPref();
                    } else {
                        outf << person->getPref() << std::endl;
                    }
                }
            } else {
                if (i == inventory->itemCount() - 1) {
                    outf << "no";
                } else {
                    outf << "no" << std::endl;
                }
            }
        }
    }
    outf.close();

}

//prints out all information about given title
void BookStore::inquire(std::string title){
    Book* inquiry = getBook(title);
    if(inquiry!=nullptr){
        std::cout<<inquiry->toString()<<std::endl;
    }else{
        std::cout<<"Title Does Not Exist"<<std::endl;
    }

}

void BookStore::help(){

    std::cout<<"\nH  - Provides a summary of all available commands"<<std::endl;
    std::cout<<"I  - Displays all information for a specified tittle"<<std::endl;
    std::cout<<"L  - List information for the entire inventory alphabetically"<<std::endl;
    std::cout<<"A  - Add a book to the inventory"<<std::endl;
    std::cout<<"M  - Modify the want value for the specified tittle"<<std::endl;
    std::cout<<"S  - Sell book"<<std::endl;
    std::cout<<"O  - Order books based on a file"<<std::endl;
    std::cout<<"D  - Delivery, updates books based on a file"<<std::endl;
    std::cout<<"R  - Return books"<<std::endl;
    std::cout<<"Q  - Quit  \n"<<std::endl;
}

void BookStore::modify(std::string title){
    //TODO
}

void BookStore::order(){
    //TODO
    std::ofstream outf("order.txt");

    if (!outf){
        std::cout << "Error. Could not find data." << std::endl;
        exit(1);
    }

    for (int i = 0; i < inventory->itemCount(); i++) {
        Book *book = inventory->getBookAt(i);
        int numToOrder = book->getWant() - book->getHave();
        if (numToOrder > 0) {
            outf << book->getName() << std::endl;
            if (i == inventory->itemCount() - 1) {
                outf << numToOrder;
            } else {
                outf << numToOrder << std::endl;
            }
        }
    }
}

void BookStore::delivery(){
    //TODO
    std::ifstream myFile("order.txt");

    if (!myFile){
        std::cout << "Error. Could not find data." << std::endl;
        exit(1);
    }
    while (!myFile.eof()){
        std::string title;
        std::string books;
        getline(myFile, title);
        getline(myFile, books);
        int bookIdx = inventory->find(title);
        int numOrdered = std::stoi(books);
        if (bookIdx >= 0){
            Book* book = inventory->getBookAt(bookIdx);
            if (book->hasWaitingList()){
                int numPeople = book->getNumPeople();
                while (numOrdered > 0 && book->hasWaitingList()){
                    Person* personSold = book->removePerson();
                    std::cout << title << ": " << personSold->toString() << std::endl;
                    numOrdered--;
                }
                if (numOrdered > 0){
                    book->setHave(numOrdered);
                }
            } else { // no waiting list
                book->setHave(book->getHave() + numOrdered);
            }
        } else { // book not found
            add(title, numOrdered, numOrdered); // should we ask for want value?
        }
    }
}

void BookStore::returnBooks(){
    //TODO
    std::ofstream outf("return.txt");

    if (!outf){
        std::cout << "Error. Could not find data." << std::endl;
        exit(1);
    }

    for (int i = 0; i < inventory->itemCount(); i++) {
        Book* book = inventory->getBookAt(i);
        if (book->getHave() > book->getWant()){
            outf << book->getName() << std::endl;
            if (i == inventory->itemCount() - 1){
                outf << (book->getHave() - book->getWant());
            } else {
                outf << (book->getHave() - book->getWant()) << std::endl;
            }
            book->setHave(book->getWant());
        }
    }

}


