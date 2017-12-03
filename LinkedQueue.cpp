//
// Created by Toby Dragon on 10/24/17.
//
#include "LinkedQueue.h"


//Creates an empty queue


LinkedQueue::LinkedQueue(){
    front = nullptr;
    end = nullptr;
}

//Copy Constructor
LinkedQueue::LinkedQueue(const LinkedQueue& queueToCopy){
    front = nullptr;
    end = nullptr;
    Person* ptr = queueToCopy.front;
    while(ptr!= nullptr){
        this->enqueue(ptr);
        ptr = ptr->getNext();
    }
}

//Destructor
LinkedQueue::~LinkedQueue(){
    while (front != nullptr){
        Person* temp = end;
        front = front->getNext();
        delete temp;
    }
}


//adds an item to the end of the queue
void LinkedQueue::enqueue(Person* item){
    Person* newPerson = new Person(item->getName(),item->getPhone(),item->getEmail(),item->getPref());
    //if front is nullptr, end should be nullptr too
    if (front == nullptr){
        front = newPerson;
        end = newPerson;
    }
    else {
        end->setNext(newPerson);
        end = newPerson;
    }
}

//takes an item off the front of the queue and returns it
//throws out_of_range exception if the queue is empty


 void LinkedQueue::dequeue(){
    //TODO, consider cases where:
    // the queue is empty
    // the queue has one item
    // the queue has many items
    if (isEmpty()){
        throw std::out_of_range("Error. Out of range.");
    } if (front == end){
        delete front;
        front = nullptr;
        end = nullptr;
    } else {
        Person* temp = front;
        front = front->getNext();
        delete temp;
    }
}

//returns true if the queue has no items, false otherwise
bool LinkedQueue::isEmpty(){
    return front == nullptr;
}
