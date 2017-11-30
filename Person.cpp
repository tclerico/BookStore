//
// Created by Tim on 11/28/2017.
//

#include "Person.h"
#include <iostream>

using namespace std;

//constructor
Person::Person(std::string name, std::string email, std::string phone, std::string prefer){
    this->name = name;
    this->email = email;
    this->phone = phone;
    this->prefer = prefer;
}


//getters
std::string Person::getName(){
    return this->name;
};

std::string Person::getEmail(){
    return this->email;
}

std::string Person::getPhone() {
    return this->phone;
}

std::string Person::getPref(){
    return this->prefer;
}

//setters
void Person::setName(std::string newName){
    this->name = newName;
}

void Person::setEmail(std::string newEmail) {
    this->email = newEmail;
}

void Person::setPhone(std::string newPhone) {
    this->phone = newPhone;
}

void Person::setPref(std::string newPref) {
    this->prefer = newPref;
}