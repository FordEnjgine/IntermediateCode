#include <iostream>

using namespace std;

#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H

class LinkedLists
{
private:

    struct Node
    {
        int data;
        Node *next;
        Node *prev;
    };


    int size;
    Node *head, *tail;


public:
    LinkedLists();
    ~LinkedLists();

    void display();

    //Dedicated to tail addition
    void append(int num);

    // Dedicated to tai removal
    void pop();
};

#endif // LINKEDLISTS_H
