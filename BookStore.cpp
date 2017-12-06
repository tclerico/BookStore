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

std::string BookStore::list() {
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


void BookStore::sell(std::string title){


    //we have to create a UI this is how we'll sell books

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
                //after the exception being caught, recall function sell(title)
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


}

void BookStore::readInventory() {
    ifstream inf("books.txt");

    if (!inf){
        std::cout << "Error. Could not find data." << std::endl;
        exit(1);
    }
    while (inf){
        std::string title;
        std::string want;
        std::string have;
        std::string waiting;
        getline(inf, title);
        getline(inf, want);
        getline(inf, have);
        getline(inf, waiting);
        add(title, std::stoi(want), std::stoi(have));
        if (waiting == "yes"){
            //TODO
            std::string numWaiting;
            getline(inf, numWaiting);
            int numPeople = std::stoi(numWaiting);
            for (int i = 0; i < numPeople; i++){
                std::string name;
                std::string phone;
                std::string email;
                std::string prefer;
                getline(inf, name);
                getline(inf, phone);
                getline(inf, email);
                getline(inf, prefer);
                getBook(title)->addPerson(name, email, phone, prefer);
            }
        }




    }
}

void BookStore::outputInventory() {
    ofstream outf("books.txt");

    if (!outf){
        std::cout << "Error. Could not find data." << std::endl;
        exit(1);
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

