#include "linkedlists.h"

LinkedLists::LinkedLists()
{
    size = 0;
    head = nullptr;
    tail = nullptr;
}

// Destructor is very important to prevent memory leak
LinkedLists::~LinkedLists()
{
    if (size > 0)
    {
        Node *temp;

        while(head != nullptr)
        {
            temp = head->next;

            delete head;

            head = temp;
        }
    }
}

void LinkedLists::display()
{
    Node *temp = head;

    for(int i = 0; i < size; i++)
    {
        //Because temp is a pointer, arrow is required
        cout << temp->data <<endl;

        //Take temps and sets it equal to the next node in the sequence
        temp = temp->next;
    }

}

//Dedicated to tail addition
void LinkedLists::append(int num)
{
    if(size == 0)
    {
        head = new Node;

        head -> data = num;
        head -> next = nullptr;
        head -> prev = nullptr;

        tail = head;
    }

    else
    {
        Node *temp = new Node;

        // Struct
        temp->data = num;
        temp->next = nullptr;
        temp -> prev = tail;

        tail->next = temp;
        tail = temp;
    }

    size++;
}

// Dedicated to tail removal
void LinkedLists::pop()
{
    if(size == 1)
    {
        Node *temp = tail;

        head = nullptr;
        tail = nullptr;

        delete temp;
    }

    else
    {
        Node *temp = head;
        head = head-> next;
        head->next->prev = nullptr;

        delete temp;
    }

    size --;
}
