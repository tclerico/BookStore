//
// Created by Dylan Shane on 12/7/17.
//

#include "BookStore.h"
#include <iostream>
#include <fstream>
#include <string>
#include <locale>
using namespace std;



void run(){

    BookStore* store = new BookStore();
    store->readInventory();
    std::cout<<"Welcome to the Book Store\n" << std::endl;
    bool close = false;
    while(!close){
        std::string ui;
        std::cout<<"Enter a Command or 'H' For Help: ";
        getline(cin,ui);

        //if user enters anything after command eg. title then it will delete and take command.
        int len = ui.length();
        ui = ui.erase(1,len);
        //if input is lower case -> capitalize
        std::locale loc;
        std::string userInput = string(1,std::toupper(ui[0],loc));

        if(userInput == "H"){
            store->help();
        }
        else if(userInput == "I"){
            std::string title;
            std::cout<<"Please Enter The Book Title: ";
            getline(cin,title);
            store->inquire(title);
        }
        else if(userInput == "L"){
            std::cout << store->list() << std::endl;
        }
        else if(userInput == "A"){
            std::string title;
            std::string want;
            std::string have;

            //loop until correct values are entered
            bool correct = false;
            while(!correct) {
                std::cout << "Enter the Title of the Book: ";
                getline(cin, title);
                std::cout << "Enter the Have value: ";
                getline(cin, have);
                std::cout << "Enter the Want value: ";
                getline(cin, want);

                //try + catch to make sure the have and wants are numbers
                try {
                    int w = std::stoi(want);
                    int h = std::stoi(have);
                    correct=true;
                }catch (exception e){
                    std::cout<<"One or More Inputs Were Invalid, Try Again"<<std::endl;
                }

            }

            store->add(title,std::stoi(have),std::stoi(want));
            std::cout<<"Successfully Added Book"<<std::endl;

        }
        else if(userInput == "M"){
            std::string title;

            std::cout<<"Enter the Title of the Book: ";
            getline(cin,title);

            int want = store->getBook(title)->getWant();
            int have = store->getBook(title)->getHave();

            std::cout<<"Current Have: " << have << " Current Want: "<<want<<std::endl;

            string newWant;
            bool correct=false;
            while(!correct){
                std::cout<<"Enter New Want Value: ";
                getline(cin,newWant);

                try{
                    int w = std::stoi(newWant);
                    correct = true;
                }catch(exception e){
                    std::cout<<"Invalid Input, Try Again"<<std::endl;
                }
            }
            store->getBook(title)->setWant(std::stoi(newWant));
            std::cout<<"Value Successfully Changed"<<std::endl;

        } else if (userInput == "S"){
            std::string title;
            std::cout<<"Enter the Title of the Book: ";
            getline(cin,title);
            bool sold = store->sell(title); //calls function sell, function sells does all the job
            if (!sold){
                std::cout<<"We're currently out of stock with that book. Let's add you to the waiting list."<<std::endl;
                std::string name;
                std::string phone;
                std::string email;
                std::string pref;
                std::cout<<"Enter the customer's name: ";
                getline(cin,name);
                std::cout<<"Enter the customer's email: ";
                getline(cin,email);
                std::cout<<"Enter the customer's phone number: ";
                getline(cin,phone);
                std::cout<<"Enter customer's preferred means of contact: ";
                getline(cin,pref);
                store->getBook(title)->addPerson(name, email, phone, pref);
            } else {
                std::cout<<"Here's a copy of " << title << "."<<std::endl;
            }

        } else if (userInput == "O"){
            //TODO Order
            std::cout << "\nCreating purchase order..." << std::endl;
            store->order();
            std::cout << "Purchase order created.\n" << std::endl;
        } else if (userInput == "D"){
            //TODO Delivery
            std::cout << "\nDelivery received..." << std::endl;
            store->delivery();
            std::cout << "Delivery processed\n" << std::endl;
        } else if (userInput == "R"){
            //TODO Return
            std::cout << "\nWriting return invoice..." << std::endl;
            store->returnBooks();
            std::cout << "Return processed\n" << std::endl;
        } else if (userInput == "Q"){
            std::cout << "\nSaving inventory...." << std::endl;
            store->outputInventory();
            std::cout << "Thank you for visiting our Bookstore." << std::endl;
            close = true;

        } else {
            std::cout << "Invalid Command." << std::endl;
        }



    }

}

int main(){
    run();
}