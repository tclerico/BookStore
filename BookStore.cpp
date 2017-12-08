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


void BookStore::sell(){


    //we have to create a UI this is how we'll sell books
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


}

void BookStore::readInventory() {
    std::ifstream myFile("/Users/dshane/Documents/Dylan\\ Homework/COLLEGE/Junior\\ Year/Comp220/Project/BookStore/books.txt");

    /*if (!myFile){
        std::cout << "Error. Could not find data." << std::endl;
        exit(1);
    }*/
    while (myFile.is_open()){
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

    std::cout<<"H  - Provides a summary of all available commands"<<std::endl;
    std::cout<<"I  - Displays all information for a specified tittle"<<std::endl;
    std::cout<<"L  -List information for the entire inventory alphabetically"<<std::endl;
    std::cout<<"A  -Add a book to the inventory"<<std::endl;
    std::cout<<"M  -Modify the want value for the specified tittle"<<std::endl;
    std::cout<<"S  -Sell book"<<std::endl;
    std::cout<<"O  -Order books based on a file"<<std::endl;
    std::cout<<"D  -Delivery, updates books based on a file"<<std::endl;
    std::cout<<"R  -Return books"<<std::endl;
    std::cout<<"Q  -Quit  "<<std::endl;
}

void modify(std::string title){
    //TODO
}

void sell(std::string title){
    //TODO
}

void order(){
    //TODO
}

void delivery(){
    //TODO
}

void returnBooks(){
    //TODO
}

/*void BookStore::run(){
    //Call readinventory function

    bool close;
    while(!close){
        std::string ui;
        std::cout<<"Enter A Command or 'H' For Help: "<<std::endl;
        std::cin >> ui;
        if(ui == "H"){
            //TODO
            help();
        }
        else if(ui == "I"){
            std::string title;
            std::cout<<"Please Enter The Book Title: ";
            std::cin >> title;
            inquire(title);
        }
        else if(ui == "L"){
            list();
        }
        else if(ui.find_first_of("A") == 0){
            std::string in = ui;
            in.erase(0,3);
            int len = in.length();
            in.erase(len-1,len);
            int want;
            int have;

            std::cout<<"Enter the Have value: "<<std::endl;
            std::cin>>have;
            std::cout<<"Enter the Want value:"<<std::endl;
            std::cin>>want;

            add(in,have,want);

        }
        else if(ui.find_first_of("M") == 0){
            std::string in = ui;
            in.erase(0,3);
            int len = in.length();
            in.erase(len-1,len);

            int want = getBook(in)->getWant();
            int have = getBook(in)->getHave();

            std::cout<<"Current Want: " << want << " Current Have: "<<have<<std::endl;
            std::cout<<"Enter New Want Value: "<<std::endl;
            int nwant;
            std::cin>>nwant;

            getBook(in)->setWant(nwant);
        }



    }
}*/

