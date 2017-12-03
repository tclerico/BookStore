//
// Created by Toby Dragon on 10/17/17.
//
#include "LinkedNode.h"

//constructor
template <class T>
LinkedNode<T>::LinkedNode(T item){
    this->item = item;
    next = nullptr;
}
//copy constructo
template <class T>
LinkedNode<T>::LinkedNode(const LinkedNode& nodeToCopy){
    item = nodeToCopy.item;
    next = nullptr;
}
template <class T>
T LinkedNode<T>::getItem(){
    return item;
}
template <class T>
LinkedNode<T>* LinkedNode<T>::getNext(){
    return next;
}

template <class T>
void LinkedNode<T>::setItem(T newItem){
    item = newItem;
}
template <class T>
void LinkedNode<T>::setNext(LinkedNode* newNext){
    next = newNext;
}
