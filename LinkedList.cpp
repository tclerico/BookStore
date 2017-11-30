//
// Created by Tim on 11/29/2017.
//


#include "LinkedList.h"

//creates an empty LinkedList
LinkedList::LinkedList() {
    front = nullptr;
    end = nullptr;
}

//Copy Constructor
LinkedList::LinkedList(const LinkedList& toCopy) {
    front = nullptr;
    end = nullptr;
    LinkedNode* ptr = toCopy.front;
    while(ptr!= nullptr){
        this->insertAtEnd(ptr->getItem());
        ptr = ptr->getNext();
    }
}

//Destructor
LinkedList::~LinkedList() {
    while(!isEmpty()){
        LinkedNode* ptr = front->getNext();
        delete front;
        front = ptr;
        ptr = nullptr;
    }
    end=nullptr;
}

//assignment operator
LinkedList& LinkedList::operator=(const LinkedList& toCopy){
    if (this!=&toCopy){
        while(!isEmpty()){
            LinkedNode* ptr = front->getNext();
            delete front;
            front = ptr;
            ptr = nullptr;
        }

        front = nullptr;
        end = nullptr;
        LinkedNode* ptr = toCopy.front;
        while(ptr!= nullptr){
            this->insertAtEnd(ptr->getItem());
            ptr = ptr->getNext();
        }

        return *this;

    }else{
        return *this;
    }
}


//appends new item to the end of the list
void LinkedList::insertAtEnd(int itemToAdd){
    LinkedNode* newNode = new LinkedNode(itemToAdd);
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

//appends new item to the front of the list
void LinkedList::insertAtFront(int itemToAdd) {
    LinkedNode* newItem = new LinkedNode(itemToAdd);
    LinkedNode* ptr = front;
    front = newItem;
    newItem->setNext(ptr);
}

//Insert the item into the list
void LinkedList::insertAt(int itemToAdd, int index) {
    if(index>this->itemCount() || index<0){
        throw std:: out_of_range("INDEX IS OUT OF RANGE");
    }else {
        if(index==this->itemCount()){
            LinkedNode* before = front;
            LinkedNode* newItem = new LinkedNode(itemToAdd);
            for(int x=0;x<index-1;x++){
                before=before->getNext();
            }
            before->setNext(newItem);
            end = newItem;
        }else if(index==0){
            LinkedNode* after = front;
            LinkedNode* newItem = new LinkedNode(itemToAdd);
            front = newItem;
            newItem->setNext(after);
        }else {
            LinkedNode *before = front;
            LinkedNode *after = front->getNext();
            LinkedNode *newItem = new LinkedNode(itemToAdd);
            for (int x = 0; x < index - 1; x++) {
                before = before->getNext();
                after = after->getNext();
            }
            before->setNext(newItem);
            newItem->setNext(after);
        }
    }
}

//returns value from given index
int LinkedList::getValueAt(int index) {
    if(index>this->itemCount()-1 || index<0){
        throw std:: out_of_range("INVALID INDEX");
    }else {
        int item;
        LinkedNode *ptr = front;
        for (int x = 0; x < index; x++) {
            ptr = ptr->getNext();
        }
        item = ptr->getItem();
        return item;
    }
}

//removes the item at the index
//returns copy of item
int LinkedList::removeValueAt(int index){
    if(index>this->itemCount()-1 || index<0){
        throw std:: out_of_range("INVALID INDEX");
    }
    else {
        //need to make sure not at end or front of list
        int num = itemCount();

        //if only one item in list
        if(num==1){
            int item = front->getItem();
            delete front;
            front = nullptr;
            end = nullptr;
            return item;
        }

            //if index is last item
        else if (index == num - 1) {
            LinkedNode *before = front;
            for (int x = 0; x < index - 1; x++) {
                before = before->getNext();
            }
            int item = before->getNext()->getItem();
            delete before->getNext();
            before->setNext(nullptr);
            end = before;
            return item;
        }
            //if index is first
        else if (index == 0) {
            LinkedNode* ptr = front->getNext();
            int item = front->getItem();
            delete front;
            front = ptr;
            ptr = nullptr;
            return item;
        }

            //if in middle of list
        else {
            LinkedNode *before = front;
            LinkedNode *after = front;
            for (int x = 0; x < index + 1; x++) {
                after = after->getNext();
            }
            for (int x = 0; x < index - 1; x++) {
                before = before->getNext();
            }
            int item = before->getNext()->getItem();
            before->getNext()->setNext(nullptr);
            delete before->getNext();
            before->setNext(after);
            return item;
        }
    }
}

/**
     * checks if there are any valid items in the list
     * @returns true if there are no valid items in the list, false otherwise
     */
bool LinkedList::isEmpty(){
    return front==nullptr;
}

/**
     * returns a count of valid items currently in the list
     * @returns the number of valid items in the list
     */
int LinkedList::itemCount(){
    if(isEmpty()){
        return 0;
    }else {
        LinkedNode *ptr = front;
        int count = 0;
        while (ptr != nullptr) {
            ptr = ptr->getNext();
            count++;
        }
        return count;
    }
}

/**
     * removes all valid items from the list
     * @post the list is completely clear of valid items
     */
void LinkedList::clearList(){
    if(front==nullptr && end==nullptr){
        std:: out_of_range("List Is Already Empty");
    }
    else{
        while(front!= nullptr){
            LinkedNode* ptr = front->getNext();
            //LinkedNode* pls = front;
            int item = front->getItem();
            delete front;
            front = ptr;
            //ptr = ptr->getNext();
        }
        end = nullptr;
    }
}

/**
     * gives a string representation of the current list
     * @returns a string representing the given list in the exact format shown below
     * {1, 2, 3, 4, 5}
     */
std::string LinkedList::toString(){
    std::string STR = "{";
    LinkedNode* ptr = front;
    if(ptr==nullptr){
        STR = STR + "}";
        return STR;
    }else {
        while (ptr != nullptr) {
            if(ptr->getNext()==nullptr){
                STR = STR + std::to_string(ptr->getItem());
                ptr = ptr->getNext();
            }else {
                STR = STR + std::to_string(ptr->getItem()) + ", ";
                ptr = ptr->getNext();
            }
        }
        STR = STR + "}";
        return STR;
    }

}

/**
     * finds the largest value in the array
     * @return the first index of the maximum value, or -1 if size < 1
     */
int LinkedList::findMaxIndex() {
    LinkedNode* ptr = front;
    if(ptr==nullptr){
        return -1;
    }else{
        int index=0;
        int maxIndex = 0;
        int max = ptr->getItem();
        while(ptr!=nullptr){
            if(max<ptr->getItem()){
                max = ptr->getItem();
                maxIndex=index;
            }
            ptr = ptr->getNext();
            index++;

        }
        return maxIndex;
    }

}

/**
     * Searches an int array for a certain value
     * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
     */
int LinkedList::find(int numToFind){
    LinkedNode* ptr = front;
    if(ptr==nullptr){
        return -1;
    }else{
        int x=0;
        while(ptr!=nullptr){
            if (numToFind == ptr->getItem()){
                return x;
            }else {
                ptr = ptr->getNext();
                x++;
            }
        }
        return -1;
    }
}

/**
     * Searches an int array for a certain value
     * @return the index of the last occurrence of numToFind if it is present, otherwise returns -1
     */
int LinkedList::findLast(int numToFind){
    LinkedNode* ptr = front;
    if(ptr == nullptr){
        return -1;
    }else{
        int index = 0;
        int pos=-1;
        while(ptr!=nullptr){
            if(numToFind==ptr->getItem()){
                pos=index;
                ptr=ptr->getNext();
                index++;
            }else{
                ptr=ptr->getNext();
                index++;
            }
        }
        return pos;
    }
}

LinkedNode* LinkedList::getFront(){
    return this->front;
}