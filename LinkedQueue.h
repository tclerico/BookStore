//
// Created by Toby Dragon on 10/22/17.
//

//un-template this and tailor it for person

#ifndef STACKSANDQUEUES_QUEUE_H
#define STACKSANDQUEUES_QUEUE_H

#include <string>
#include <stdexcept>
//#include "LinkedNode.h"
#include "Person.h"


/**
 * Represents a FIFO data structure (First In First Out). Picture a line
 * to wait for something (first person in is the first person out)
 */
class LinkedQueue {
private:
    Person* front;
    Person* end;


public:
    
    //Creates an empty queue
    LinkedQueue();

    //Copy Constructor
    LinkedQueue(const LinkedQueue& queueToCopy);

    //Destructor
    ~LinkedQueue();
    
    //adds an item to the end of the queue
    void enqueue(Person* item);

    //takes an item off the front of the queue and returns it
    //throws out_of_range exception if the queue is empty
    void dequeue();

    //returns true if the queue has no items, false otherwise
    bool isEmpty();

};

#endif //STACKSANDQUEUES_QUEUE_H
