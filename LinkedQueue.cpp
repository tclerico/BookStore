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
    if (queueToCopy.front == nullptr){
        front = nullptr;
        end = nullptr;
        return;
    } else {
        LinkedNode* currentNode = queueToCopy.front;
        front = new LinkedNode(currentNode->getItem());
        LinkedNode* endNode = front;
        currentNode = currentNode->getNext();
        while (currentNode != nullptr) {
            std::string itemToAdd = currentNode->getItem();
            LinkedNode* newNode = new LinkedNode(itemToAdd);
            endNode->setNext(newNode);
            endNode = newNode;
            currentNode = currentNode->getNext();
        }
        end = endNode;
    }
    return;
}

//Destructor
LinkedQueue::~LinkedQueue(){
    while (front != nullptr){
        LinkedNode* temp = end;
        front = front->getNext();
        delete temp;
    }
}


//adds an item to the end of the queue
void LinkedQueue::enqueue(std::string item){
    LinkedNode* newNode = new LinkedNode(item);
    //if front is nullptr, end should be nullptr too
    if (front == nullptr){
        front = newNode;
        end = newNode;
    }
    else {
        end->setNext(newNode);
        end = newNode;
    }
}

//takes an item off the front of the queue and returns it
//throws out_of_range exception if the queue is empty
std::string LinkedQueue::dequeue(){
    //TODO, consider cases where:
    // the queue is empty
    // the queue has one item
    // the queue has many items
    if (isEmpty()){
        throw std::out_of_range("Error. Out of range.");
    } if (front == end){
        std::string returnItem = front->getItem();
        delete front;
        front = nullptr;
        end = nullptr;
        return returnItem;
    } else {
        LinkedNode *temp = front;
        front = front->getNext();
        std::string returnItem = temp->getItem();
        delete temp;
        return returnItem;
    }
}

//returns true if the queue has no items, false otherwise
bool LinkedQueue::isEmpty(){
    return front == nullptr;
}
