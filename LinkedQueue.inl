//
// Created by Toby Dragon on 10/24/17.
//
#include "LinkedQueue.h"


//Creates an empty queue


template <class T>

LinkedQueue<T>::LinkedQueue(){
    front = nullptr;
    end = nullptr;
}

//Copy Constructor
LinkedQueue<T>::LinkedQueue(const LinkedQueue& queueToCopy){
    front = nullptr;
    end = nullptr;
    LinkedNode* ptr = queueToCopy.front;
    while(ptr!= nullptr){
        this->enqueue(ptr->getItem());
        ptr = ptr->getNext();
    }
}

//Destructor
LinkedQueue<T>::~LinkedQueue(){
    while (front != nullptr){
        LinkedNode* temp = end;
        front = front->getNext();
        delete temp;
    }
}


//adds an item to the end of the queue
template <class T>
void LinkedQueue<T>::enqueue(T item){
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

template <class T>
 T LinkedQueue<T>::dequeue(){
    //TODO, consider cases where:
    // the queue is empty
    // the queue has one item
    // the queue has many items
    if (isEmpty()){
        throw std::out_of_range("Error. Out of range.");
    } if (front == end){
        T returnItem = front->getItem();
        delete front;
        front = nullptr;
        end = nullptr;
        return returnItem;
    } else {
        LinkedNode *temp = front;
        front = front->getNext();
        T returnItem = temp->getItem();
        delete temp;
        return returnItem;
    }
}

//returns true if the queue has no items, false otherwise
bool LinkedQueue<T>::isEmpty(){
    return front == nullptr;
}
