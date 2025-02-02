#include "stack.h"


Stack::Stack()
{
    size = 0;
    head = nullptr;
    tail = nullptr;
}

Stack::~Stack()
{
    if(size > 0)
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
}

void Stack::add(char item)
{
    // head = tail when size = 0
    if(size == 0)
    {
        head = new Node(item, nullptr);
        tail = head;
    }
    // Head = a new node which points to the previous head
    else
    {
        Node *temp = new Node(item, nullptr);

        temp->next = head;
        head = temp;
    }
    size++;
}

char Stack::remove()
{
    char tempChar;
    Node *temp;

    // If size is 1, head and tail are set to nullptr
    if(size == 1)
    {
        tempChar = head->data;

        temp = head;

        head = nullptr;
        tail = nullptr;

        delete temp;
    }
    // if size is greater than 1, head->next = new head;
    else
    {
        tempChar = head->data;

        temp = head->next;

        delete head;

        head = temp;
    }

    size--;
    return tempChar;
}
