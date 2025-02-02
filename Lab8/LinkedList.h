#include <iostream>

// random number
// used for: shuffle
#include <ctime>
#include <cstdlib>

// Node structure
#include "node.h"

using std::cout;
using std::endl;

#ifndef LINKEDLIST_H
#define LINKEDLIST_H


class LinkedList
{
private:
    Node *head, *tail;
    int size;

public:
    // constructor and destructor (given to you)
    LinkedList();
    ~LinkedList();

    // display, add, and pop functions (given to you)
    void display();
    void append(int number);
    void pop();

    // given to you
    // shows: selection sort
    void sort();

    // given to you
    // shuffle!
    void shuffle();

    // **** you should complete these ****
    // all of these should work on a TITLE of the book basis
    int binarySearch(int number);
    void reverseSort();     // DIFFERENT sorting algorithm of your choice
        // (cannot be the same as the one shown)
        // (CANNOT be a built-in sort)
    void removeValues(int number);


    // HONORS / BONUS credit
    // optional unless you're honors
    // if not implementing, just leave it here
    void differentSort();    // DIFFERENT sorting algorithm of your choice
};

#endif // LINKEDLIST_H
