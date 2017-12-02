//
// Created by Tim on 11/29/2017.
//


#include "LinkedList.h"
#include "Book.h"


//O(1)
LinkedList::LinkedList(){
    front = nullptr;
    end = nullptr;
    numItems = 0;
}

//O(n)
LinkedList::LinkedList(const LinkedList& listToCopy) {
    //TODO
    /*if (listToCopy.front == nullptr){
        front = nullptr;
        end = nullptr;
        numItems = 0;
    } else {
        Book* currentNode = listToCopy.front;
        front = new LinkedNode(currentCopyNode->getItem());
        currentCopyNode = currentCopyNode->getNext();
        LinkedNode* currentNode = front;
        while (currentCopyNode != nullptr){
            LinkedNode* newNode = new LinkedNode(currentCopyNode->getItem());
            currentNode->setNext(newNode);
            currentCopyNode = currentCopyNode->getNext();
            currentNode = currentNode->getNext();
        }
        end = currentNode;
        numItems = listToCopy.numItems;
    }*/
}

//O(n)
LinkedList& LinkedList::operator=(const LinkedList& linkedListToCopy){
    //TODO
    /*if (this != &linkedListToCopy) {
        numItems = linkedListToCopy.numItems;
        if (numItems == 0){
            front = nullptr;
            end = nullptr;
        } else {
            this->clearList();
            LinkedNode* currentNode = new LinkedNode(linkedListToCopy.front->getItem());
            front = currentNode;
            LinkedNode* nodeToCopy = linkedListToCopy.front->getNext();
            while (nodeToCopy->getNext() != nullptr) {
                LinkedNode* copiedNode = new LinkedNode(nodeToCopy->getItem());
                currentNode->setNext(copiedNode);
                nodeToCopy = nodeToCopy->getNext();
                currentNode = currentNode->getNext();
            }
            LinkedNode* lastNode = new LinkedNode(nodeToCopy->getItem());
            currentNode->setNext(lastNode);
            end = lastNode;
        }
    }
    return *this;*/
}

//O(n)
LinkedList::~LinkedList() {
    //TODO
    /*LinkedNode* current = front;
    while (current != nullptr){
        LinkedNode* toDelete = current;
        current = current->getNext();
        delete toDelete;
    }*/
}


//O(1)
void LinkedList::insertAtEnd(Book* bookToAdd){
    if (front == nullptr){
        front = bookToAdd;
        end = bookToAdd;
    } else {
        end->setNext(bookToAdd);
        end = bookToAdd;
    }
    numItems++;
}

//O(1)
void LinkedList::insertAtFront(Book* bookToAdd){
    if (front == nullptr){
        front = bookToAdd;
        end = bookToAdd;
    } else {
        bookToAdd->setNext(front);
        front = bookToAdd;
    }
    numItems++;
}

//O(n)
void LinkedList::insertAt(Book* bookToAdd, int index) {
    if (index > numItems || index < 0) {
        throw std::out_of_range("Index out of range.");
    } else if (index == 0) {
        insertAtFront(bookToAdd);
    } else if (index == numItems) {
        insertAtEnd(bookToAdd);
    } else {
        int count = 0;
        Book* current = front;
        while (count != index - 1) {
            current = current->getNext();
            count++;
        }
        Book* nextBook = current->getNext();
        current->setNext(bookToAdd);
        bookToAdd->setNext(nextBook);
        numItems++;
    }
}

//O(n)
Book* LinkedList::getBookAt(int index){
    if (index > numItems - 1 || index < 0){
        throw std::out_of_range("<Your error message here>");
    } else {
        int currentIdx = 0;
        Book* current = front;
        while (currentIdx != index) {
            current = current->getNext();
            currentIdx++;
        }
        return current;
    }

}

//O(n)
bool LinkedList::removeValueAt(int index){
    if (index > numItems - 1 || index < 0){
        throw std::out_of_range("<Your error message here>");
    } else if (index == 0){
        Book* bookToDelete = front;
        std::string itemToReturn = bookToDelete->getName();
        front = bookToDelete->getNext();
        delete bookToDelete;
        numItems--;
        return true;
    }  else if (index == numItems - 1){
        Book* bookToDelete = end;
        Book* newEndBook = front;
        std::string itemToDelete = bookToDelete->getName();
        while (newEndBook->getNext() != bookToDelete){
            newEndBook = newEndBook->getNext();
        }
        end = newEndBook;
        delete bookToDelete;
        numItems--;
        return true;
    }else {
        int currIdx = 0;
        Book* bookBeforeDelete = front;
        Book* bookToBeDeleted = bookBeforeDelete->getNext();
        while (currIdx != index){
            bookToBeDeleted = bookToBeDeleted->getNext();
            bookBeforeDelete = bookBeforeDelete->getNext();
            currIdx++;
        }
        bookBeforeDelete->setNext(bookToBeDeleted->getNext());
        delete bookToBeDeleted;
        numItems--;
        return true;
    }
}

//O(1)
bool LinkedList::isEmpty(){
    return (numItems == 0);
}

//O(1)
int LinkedList::itemCount(){
    return numItems;
}

//O(n)
void LinkedList::clearList(){
    Book* currentBook = front;
    while (currentBook != nullptr){
        Book* bookToDelete = currentBook;
        currentBook = currentBook->getNext();
        delete bookToDelete;
    }
    front = nullptr;
    end = nullptr;
    numItems = 0;
}

//O(n)
std::string LinkedList::toString(){
    std::string returnString = "{";
    if (front == nullptr){
        return returnString + "}";
    }
    Book* currentBook = front;
    while (currentBook->getNext() != nullptr){
        returnString += currentBook->toString() + "\n";
        currentBook = currentBook->getNext();
    }
    return returnString + currentBook->toString() + "}";


}


//O(n)
int LinkedList::find(std::string titleToFind){
    Book* currentBook = front;
    int currentIdx = 0;
    while (currentBook != nullptr){
        if (currentBook->getName() == titleToFind){
            return currentIdx;
        }
        currentBook = currentBook->getNext();
        currentIdx++;
    }
    return -1;
}
