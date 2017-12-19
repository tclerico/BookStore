//
// Created by Tim on 11/29/2017.
//

#ifndef BOOKSTORE_LINKEDLIST_H
#define BOOKSTORE_LINKEDLIST_H

#include <string>
#include <stdexcept>
#include "Book.h"
#include "Inventory.h"
    /** this was directly stolen from intLinkedList and some things will need to be changed
     * might be a good idea to template this for use in the inventory/waitlist
     */


class LinkedList : public Inventory {


private:
    Book *front;
    Book *end;
    int numItems;

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
 * appends the new item to the beginning of the list
 * @param itemToAdd the item to add to the beginning of the list
 * @post the list has an additional value in it, at the beginning
 *    all other items are shifted down by one index
 */
//BIG-O: O(1)
        void insertAtFront(Book* bookToAdd);

        void insert(Book* bookToAdd);

/**
 * gets a value from the list
 * @param index the location from which to get the value
 * @returns a copy of the item at index
 * @throws out_of_range exception if index is invalid
 */
//BIG-O: O(N)
        Book* getBookAt(int index);

/**
 * removes the item at index from the list, and returns a copy of that item
 * @param index the location from which to get the value
 * @post the item at index is removed from the list, everything else is shifted down one
 * @returns a copy of the item at index
 * @throws out_of_range exception if index is invalid
 */
//BIG-O: O(N)
        bool removeValueAt(int index);

/**
 * checks if there are any valid items in the list
 * @returns true if there are no valid items in the list, false otherwise
 */
//BIG-O: O(1)
        bool isEmpty();

        /**
         * gets the item count of the list
         * @return number of items in the list
         */
//O(1)
        int itemCount();

        /**
         * removes all valid items from the list
         * @post the list is completely clear of valid items
         */
//O(n)
        void clearList();

        /**
         * gives a string representation of the current list
         * @returns a string representing the given list in the exact format shown below
         * {1, 2, 3, 4, 5}
         */
//O(n)
        std::string toString();

        /**
         * Searches an int array for a certain value
         * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
         */
//O(n)
        int find(std::string titleToFind);

        /**
         * Sorts the linked structure
         */
        void sort();


    };




#endif //BOOKSTORE_LINKEDLIST_H
