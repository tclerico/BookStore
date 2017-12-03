//
// Created by Tim on 11/28/2017.
//

#include <string>

#ifndef PERSON_H
#define PERSON_H

#endif //BOOKSTORE_PERSON_H

class Person{

private:

    //First and Last name of person
    std::string name;
    //persons email
    std::string email;
    //persons Phone Number
    std::string phone;
    //persons prefered means of contact.
    std::string prefer;

    Person* next;

public:

    //constructor
    Person(std::string name, std::string email, std::string phone, std::string prefer);


    //Getters and Setters
    void setName(std::string newName);
    void setEmail(std::string newEmail);
    void setPhone(std::string newPhone);
    void setPref(std::string newPref);

    std::string getName();
    std::string getEmail();
    std::string getPhone();
    std::string getPref();

    Person* getNext();
    void setNext(Person* newNext);


};







