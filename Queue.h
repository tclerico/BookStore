//
// Created by Dylan Shane on 12/5/17.
//

#ifndef BOOKSTORE_QUEUE_H
#define BOOKSTORE_QUEUE_H

#include "Person.h"
#include <stdexcept>

class Queue {
public:

    virtual void enqueue(Person* item)=0;

    //takes an item off the front of the queue and returns it
    //throws out_of_range exception if the queue is empty
    virtual std::string dequeue()=0;

    //returns true if the queue has no items, false otherwise
    virtual bool isEmpty()=0;





};

#endif //BOOKSTORE_QUEUE_H
