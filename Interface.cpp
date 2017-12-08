//
// Created by Dylan Shane on 12/7/17.
//

#include "BookStore.h"
#include <iostream>
#include <fstream>
using namespace std;


int countLines(){
    ifstream ifs( "books.txt", ios::in );       // note no mode needed
    if ( ! ifs.is_open() ) {
        cout <<" Failed to open" << endl;
    }
    else {
        cout <<"Opened OK" << endl;
    }

    int number_of_lines = 0;
    std::string line;

    while (std::getline(ifs, line)) {
        ++number_of_lines;
    }
    ifs.close();
    return number_of_lines;
}



//reads in info from books.txt -> is set for the specific formating of books.txt
BookStore* buildStore(){

    int numLines = countLines();

    ifstream ifs( "books.txt", ios::in );       // note no mode needed
    if ( ! ifs.is_open() ) {
        cout <<" Failed to open" << endl;
    }
    else {
        cout <<"Opened OK" << endl;
    }
    //std::cout << "Number of lines in text file: " << number_of_lines;


    BookStore* items = new BookStore();
    //Book* toAdd;
    for(int x=0;x<numLines;x+=3){
        std::string name;
        std::getline(ifs,name);
        std::string have;
        std::getline(ifs,have);
        std::string want;
        std::getline(ifs,want);
        items->add(name,std::stoi(have),std::stoi(want));
    }
    ifs.close();
    return items;
}



void run(BookStore* store){

    //think we should make the BookStore costructor use on file io
    //BookStore* store = new BookStore();
    store->readInventory();

    bool close;
    while(!close){
        std::string userInput;
        std::cout<<"Enter a Command or 'H' For Help: "<<std::endl;
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

            std::cout<<"Enter the Title of the Book: "<<std::endl;
            std::cin>>title;
            std::cout<<"Enter the Have value: "<<std::endl;
            std::cin>>have;
            std::cout<<"Enter the Want value:"<<std::endl;
            std::cin>>want;

            store->add(title,have,want);

        }
        else if(userInput.find_first_of("M") == 0){
            std::string in = userInput;
            in.erase(0,3);
            int len = in.length();
            in.erase(len-1,len);

            int want = store->getBook(in)->getWant();
            int have = store->getBook(in)->getHave();

            std::cout<<"Current Want: " << want << " Current Have: "<<have<<std::endl;
            std::cout<<"Enter New Want Value: "<<std::endl;
            int nwant;
            std::cin>>nwant;

            store->getBook(in)->setWant(nwant);
        } else if (userInput == "S"){
            std::string title;
            std::cout<<"Enter the Title of the Book: "<<std::endl;
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