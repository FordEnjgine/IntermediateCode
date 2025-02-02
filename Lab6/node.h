#ifndef NODE_H
#define NODE_H

class Node
{
public:
    int number;
    Node *prev;
    Node *next;

    // zero constructor
    Node()
    {
        number = 0;
        prev = nullptr;
        next = nullptr;
    };

    // takes in a number
    // assigns next and prev pointer to nullptr
    Node(int number)
    {
        this->number = number;
        prev = nullptr;
        next = nullptr;
    };

    // takes in a number
    // assigns next and prev pointer to parameter Nodes
    Node(int number, Node *prev, Node *next)
    {
        this->number = number;
        this->prev = prev;
        this->next = next;
    };
};

#endif // NODE_H
