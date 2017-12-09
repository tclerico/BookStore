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
        sorted = false;
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


bool BookStore::sell(std::string title){
    Book* bookToSell = getBook(title);
    if (bookToSell != nullptr && bookToSell->getHave() > 0){
        getBook(title)->sell();
        return true;
    } else {
        return false;
    }
}

    /*//we have to create a UI this is how we'll sell books
    std::string title;
    std::cout<<"Enter title book: "<<std::endl;
    std::cin>>title;

    Book* bookToSell = getBook(title);

    if(bookToSell != nullptr && bookToSell->getHave() > 0){

        std::string response;
        std::cout<<"Would You like to buy " + bookToSell->getName() + " Y/N:    "<<std::endl;
        std::cin >> response;
        try{
            if(response == "Y" ){
                bookToSell->sell();
                std::cout<<"Thanks for your purchase"<<std::endl;
            }else if(response == "N"){
                std::cout<<"Thanks for your interest"<<std::endl;
            }else {
                //throw
            }
        }catch (std::invalid_argument exception){

            //if problem call function sell again
                sell();

        }

    } else{

        std::cout<<"Book Not Available";
        //get want value for new book
        int want;
        std::cout<<"Title will be added please enter want value: ";
        std::cin >> want;
        //add book to inventory with have=0
        add(title,0,want);


        //get customers info for waitinglist
        std::string name;
        std::string phone;
        std::string email;
        std::string pref;
        std::cout<<"Enter the customer's name: ";
        std::cin >> name;
        std::cout<<"Enter the customer's email: ";
        std::cin >> email;
        std::cout<<"Enter the customer's phone number: ";
        std::cin >> phone;
        std::cout<<"Enter customer's prefered means of contact: ";
        std::cin >> pref;

        //add person to the waiting list for the new book
        getBook(title)->addPerson(name,email,phone,pref);

    }


}*/

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
    std::ofstream outf("books.txt");

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
    //TODO
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

}

void returnBooks(){
    //TODO
}


