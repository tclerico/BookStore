//
// Created by Dylan Shane on 12/7/17.
//

#include "BookStore.h"
#include <iostream>

void run(){

    BookStore* store = new BookStore();
    store->readInventory();

    bool close;
    while(!close){
        std::string userInput;
        std::cout<<"Enter A Command or 'H' For Help: "<<std::endl;
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

            store->sell(); //calls function sell, function sells does all the job

        } else if (userInput == "O"){
            //TODO Order
        } else if (userInput == "D"){
            //TODO Delivery
        } else if (userInput == "R"){
            //TODO Return
        } else if (userInput == "Q"){
            std::cout << "Saving inventory...." << std::endl;
            store->outputInventory();
            std::cout << "Thank you for visitng our Bookstore." << std::endl;
            close = true;
        } else {
            std::cout << "Invalid Command." << std::endl;
        }



    }

}

int main(){
    run();
}