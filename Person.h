//
// Created by Tim on 11/28/2017.
//

#include <string>

#ifndef BOOKSTORE_PERSON_H
#define BOOKSTORE_PERSON_H

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

public:

    //constructor
    Person(std::string name, std::string email, std::string phone, std::string prefer);
    //copy constructor
    Person(const Person& personToCopy);

    //Getters and Setters
    std::string setName(std::string newName);
    std::string setEmail(std::string newEmail);
    std::string setPhone(std::string newPhone);
    std::string setPref(std::string newPref);

    std::string getName();
    std::string getEmail();
    std::string getPhone();
    std::string getPref();


};







