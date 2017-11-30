//
// Created by Tim on 11/29/2017.
//

#ifndef BOOKSTORE_LINKEDLIST_H
#define BOOKSTORE_LINKEDLIST_H

#include <string>
#include <stdexcept>
#include "LinkedNode.h"

    /** this was directly stolen from intLinkedList and some things will need to be changed
     * might be a good idea to template this for use in the inventory/waitlist
     */


class LinkedList {


private:
    LinkedNode *front;
    LinkedNode *end;

public:

//Creates an empty LinkedList
    LinkedList();

//copy constructor
//BIG-O: O(N)
    LinkedList(const LinkedList &toCopy);

//destructor
//BIG-O: O(N)
    ~LinkedList();

//assignment operator
//BIG-O: O(N)
    LinkedList &operator=(const LinkedList &toCopy);

/**
 * appends the new item to the end of the list
 * @param itemToAdd the item to add to the end of the array
 * @post the list has an additional value in it, at the end
 */
//BIG-O: O(1)
    void insertAtEnd(int itemToAdd);

/**
 * appends the new item to the beginning of the list
 * @param itemToAdd the item to add to the beginning of the list
 * @post the list has an additional value in it, at the beginning
 *    all other items are shifted down by one index
 */
//BIG-O: O(1)
    void insertAtFront(int itemToAdd);

/**
 * inserts the item into the list so that it can be found with get(index)
 * @param itemToAdd the item to add
 * @param index the location in which to insert this item
 * @post the list has an additional value in it at the specified index,
 *        all further values have been shifted down by one index
 * @throws out_of_range exception if index is invalid (< 0 or >currItemCount)
 */
//BIG-O: O(N)
    void insertAt(int itemToAdd, int index);

/**
 * gets a value from the list
 * @param index the location from which to get the value
 * @returns a copy of the item at index
 * @throws out_of_range exception if index is invalid
 */
//BIG-O: O(N)
    int getValueAt(int index);

/**
 * removes the item at index from the list, and returns a copy of that item
 * @param index the location from which to get the value
 * @post the item at index is removed from the list, everything else is shifted down one
 * @returns a copy of the item at index
 * @throws out_of_range exception if index is invalid
 */
//BIG-O: O(N)
    int removeValueAt(int index);

/**
 * checks if there are any valid items in the list
 * @returns true if there are no valid items in the list, false otherwise
 */
//BIG-O: O(1)
    bool isEmpty();

/**
 * returns a count of valid items currently in the list
 * @returns the number of valid items in the list
 */
//BIG-O: O(N)
    int itemCount();

/**
 * removes all valid items from the list
 * @post the list is completely clear of valid items
 */
//BIG-O: O(N)
    void clearList();

/**
 * gives a string representation of the current list
 * @returns a string representing the given list in the exact format shown below
 * {1, 2, 3, 4, 5}
 */
//BIG-O: O(N)
    std::string toString();

/**
 * finds the largest value in the array
 * @return the first index of the maximum value, or -1 if size < 1
 */
//BIG-O: O(N)
    int findMaxIndex();

/**
 * Searches an int array for a certain value
 * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
 */
//BIG-O: O(N)
    int find(int numToFind);

/**
 * Searches an int array for a certain value
 * @return the index of the last occurrence of numToFind if it is present, otherwise returns -1
 */
//BIG-O: O(N)
    int findLast(int numToFind);

/**
 * returns pointer to front
 */
//BIG-O: O(1)
    LinkedNode *getFront();

};



#endif //BOOKSTORE_LINKEDLIST_H
