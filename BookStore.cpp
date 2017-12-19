//
// Created by crist on 11/28/2017.
//


#include "LinkedInventory.h"
#include "BookStore.h"
#include <fstream>
#include <iostream>

BookStore::BookStore() {
    inventory = new LinkedList();
    numBooks = 0;
}


/**
 * Adds a book to the inventory in alphabetical order
 * @param title - the title of the book to be added
 * @param have - the have value of the book to be added
 * @param want - the want value of the book to be added
 */
void BookStore::add(std::string title, int have, int want) {
    int bookFound = inventory->find(title);
    if (bookFound == -1) {
        Book* bookToAdd = new Book(title, have, want);
        inventory->insert(bookToAdd);
        numBooks++;
    } else {
        std::cout << "That book already exists." << std::endl;
        std::cout << inventory->getBookAt(bookFound)->toString() << std::endl;
    }
}

/**
 * Creates a string of all the books in the inventory
 * @return a string of all the books in the inventory
 */
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

/**
 * Gets a finds a book by searching by title
 * @param title - title of book to return
 * @return the book requested or a nullptr if it's not found
 */
Book* BookStore::getBook(std::string title){
    int found = inventory->find(title);
    if (found >= 0){
        return inventory->getBookAt(found);
    } else {
        return nullptr;
    }
}

/**
 * Decrements from a book's have value
 * @param title - title of book to be sold.
 * @return boolean - true if the book was sold, false if it was not found
 */
bool BookStore::sell(std::string title){
    Book* bookToSell = getBook(title);
    if (bookToSell != nullptr && bookToSell->getHave() > 0){
        getBook(title)->sell();
        return true;
    } else if (bookToSell == nullptr) {
        Book* newBook = new Book(title, 0, 5);
        inventory->insert(newBook);
        return false;
    } else {
        return false;
    }
}

/**
 * Reads in a text file to create the inventory of books
 */
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

        //these two lines neccessary for first run on windows
        //int len = title.length();
        //title = title.erase(len-1,len);

        add(title, std::stoi(want), std::stoi(have));
        if (waiting == "yes"){
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

/**
 * Saves the inventory to a file
 */
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

/**
 * Creates a string of a requested books information
 * @param title - title of book being requested
 * @return information of the book or a message saying it wasn't found
 */
std::string BookStore::inquire(std::string title){
    Book* inquiry = getBook(title);
    if(inquiry!=nullptr){
        return inquiry->toString();
    }else{
        return "Title Does Not Exist";
    }

}

/**
 * Prints out all of the commands and a brief description of what they do
 */
void BookStore::help(){

    std::cout<<"\nH  - Provides a summary of all available commands"<<std::endl;
    std::cout<<"I  - Displays all information for a specified tittle"<<std::endl;
    std::cout<<"L  - List information for the entire inventory alphabetically"<<std::endl;
    std::cout<<"A  - Add a book to the inventory"<<std::endl;
    std::cout<<"M  - Modify the want value for the specified tittle"<<std::endl;
    std::cout<<"S  - Sell book"<<std::endl;
    std::cout<<"O  - Order books based on a current inventory"<<std::endl;
    std::cout<<"D  - Delivery, updates books based on an order invoice"<<std::endl;
    std::cout<<"R  - Return books"<<std::endl;
    std::cout<<"Q  - Quit  \n"<<std::endl;
}

/**
 * Writes a purchase order based on the have/want values of the current inventory
 */
void BookStore::order(){

    std::ofstream outf("order.txt");

    if (!outf){
        std::cout << "Error. Could not find data." << std::endl;
        exit(1);
    }

    for (int i = 0; i < inventory->itemCount(); i++) {
        Book *book = inventory->getBookAt(i);
        int numToOrder = book->getNumPeople() + book->getWant() - book->getHave();
        if (numToOrder > 0) {
            outf << book->getName() << std::endl;
            outf << numToOrder << std::endl;
        }
    }
}

/**
 * Reads in an purchase order and modifies the inventory accordingly
 */
void BookStore::delivery(){

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
        if (title != "" && books != "" ) {
            int bookIdx = inventory->find(title);
            int numOrdered = std::stoi(books);
            if (bookIdx >= 0) {
                Book *book = inventory->getBookAt(bookIdx);
                if (book->hasWaitingList()) {
                    int numPeople = book->getNumPeople();
                    while (numOrdered > 0 && book->hasWaitingList()) {
                        Person *personSold = book->removePerson();
                        std::cout << title << ": " << personSold->toString() << std::endl;
                        numOrdered--;
                    }
                    if (numOrdered > 0) {
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
}

/**
 * Changes the want value of a book
 * @param title - title of book to be modified
 * @param newWant - desired new want value
 */
void BookStore::modify(std::string title, int newWant){
    Book* bookToChange = this->getBook(title);
    bookToChange->setWant(newWant);
}

/**
 * Writes out a return invoice based on each book in the inventory's have/want value
 */
void BookStore::returnBooks(){

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


