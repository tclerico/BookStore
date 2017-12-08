//
// Created by Dylan Shane on 12/7/17.
//

#include "BookStore.h"
#include <iostream>
#include <fstream>
using namespace std;

BookStore* buildStore(){

    ifstream ifs( "books.txt", ios::in );       // note no mode needed
    if ( ! ifs.is_open() ) {
        cout <<" Failed to open" << endl;
    }
    else {
        cout <<"Opened OK" << endl;
    }

    BookStore* inventory = new BookStore();
    int count = 0;
    Book* toAdd;
    while (ifs)
    {
        // read stuff from the file into a string and print it
        std::string strInput;
        getline(ifs,strInput);
        if(count%3 == 0){
            toAdd = new Book(strInput,0,0);
        }
        else if(count%2 == 0){
            toAdd->setHave(std::stoi(strInput));
        }
        else{
            toAdd->setWant(std::stoi(strInput));
        }
        //cout << strInput << endl;
    }
    return inventory;
}



void run(BookStore* store){

    //think we should make the BookStore costructor use on file io
    //BookStore* store = new BookStore();
    store->readInventory();

    bool close = false;
    while(!close){
        std::string userInput;
        std::cout<<"Enter a Command or 'H' For Help: ";
        std::cin >> userInput;
        if(userInput == "H"){
            //TODO
            store->help();
        }
        else if(userInput == "I"){
            std::string title;
            std::cout<<"Please Enter The Book Title: ";
            std::cin >> title;
            store->inquire(title);
        }
        else if(userInput == "L"){
            std::cout << store->list() << std::endl;
        }
        else if(userInput == "A"){
            std::string title;
            int want;
            int have;

            std::cout<<"Enter the Title of the Book: ";
            std::cin>>title;
            std::cout<<"Enter the Have value: ";
            std::cin>>have;
            std::cout<<"Enter the Want value:";
            std::cin>>want;

            store->add(title,have,want);

        }
        else if(userInput == "M"){
            std::string title;

            std::cout<<"Enter the Title of the Book: ";
            std::cin>>title;

            int want = store->getBook(title)->getWant();
            int have = store->getBook(title)->getHave();

            std::cout<<"Current Want: " << want << " Current Have: "<<have<<std::endl;
            std::cout<<"Enter New Want Value: ";
            int newWant;
            std::cin>>newWant;

            store->getBook(title)->setWant(newWant);
        } else if (userInput == "S"){
            std::string title;
            std::cout<<"Enter the Title of the Book: ";
            std::cin>>title;
            bool sold = store->sell(title); //calls function sell, function sells does all the job
            if (!sold){
                std::cout<<"We're currently out of stock with that book. Let's add you to the waiting list."<<std::endl;
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
                std::cout<<"Enter customer's preferred means of contact: ";
                std::cin >> pref;
                store->getBook(title)->addPerson(name, email, phone, pref);
            } else {
                std::cout<<"Here's a copy of " << title << "."<<std::endl;
            }
        } else if (userInput == "O"){
            //TODO Order
        } else if (userInput == "D"){
            //TODO Delivery
        } else if (userInput == "R"){
            //TODO Return
        } else if (userInput == "Q"){
            std::cout << "Saving inventory...." << std::endl;
            store->outputInventory();
            std::cout << "Thank you for visiting our Bookstore." << std::endl;
            close = true;
        } else {
            std::cout << "Invalid Command." << std::endl;
        }



    }

}

int main(){
    BookStore* nStore = buildStore();
    run(nStore);
}