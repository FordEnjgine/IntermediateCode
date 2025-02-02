#include <iostream>
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

    // given to students
    // NOT intended to be used independently
    // either: for reference or to use to aid other functions
    void pop();                 // removes from the end of the linked list

public:
    // constructor and destructor
    LinkedList();
    ~LinkedList();

    // given to students
    void display();             // displays the entire linked list
    void reverseDisplay();      // displays the entire linked list backwards

    // given to students
    // NOT intended to be used independently except for initial list setup
    // either: for reference or to use to aid other functions
    void append(int number);    // adds to the end of the linked list

    // you must create
    void insert(int number, int position);
    void remove(int position);
    void removeValue(int number);
};

#endif // LINKEDLIST_H
