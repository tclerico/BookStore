//
// Created by Dylan Shane on 12/5/17.
//

#ifndef BOOKSTORE_INVENTORY_H
#define BOOKSTORE_INVENTORY_H


class Inventory{
public:
    virtual void insertAtFront(Book* bookToAdd)=0;

    virtual void insert(Book* bookToAdd)=0;

/**
 * gets a value from the list
 * @param index the location from which to get the value
 * @returns a copy of the item at index
 * @throws out_of_range exception if index is invalid
 */
//BIG-O: O(N)
    virtual Book* getBookAt(int index)=0;

/**
 * removes the item at index from the list, and returns a copy of that item
 * @param index the location from which to get the value
 * @post the item at index is removed from the list, everything else is shifted down one
 * @returns a copy of the item at index
 * @throws out_of_range exception if index is invalid
 */
//BIG-O: O(N)
    //bool removeValueAt(int index); do we need to remove books?

/**
 * checks if there are any valid items in the list
 * @returns true if there are no valid items in the list, false otherwise
 */
//BIG-O: O(1)
    virtual bool isEmpty()=0;

    /**
     * gets the item count of the list
     * @return number of items in the list
     */
//O(1)
    virtual int itemCount()=0;

    /**
     * removes all valid items from the list
     * @post the list is completely clear of valid items
     */
//O(n)
    virtual void clearList()=0;

    /**
     * gives a string representation of the current list
     * @returns a string representing the given list in the exact format shown below
     * {1, 2, 3, 4, 5}
     */
//O(n)
    virtual std::string toString()=0;

    /**
     * Searches an int array for a certain value
     * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
     */
//O(n)
    virtual int find(std::string titleToFind)=0;

    /**
     * Sorts the linked structure
     */
    virtual void sort()=0;




};



#endif //BOOKSTORE_INVENTORY_H
