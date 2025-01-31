#ifndef NODE_H
#define NODE_H

class Node
{
public:
    int data;
    // This is point one node to another node
    Node *next;

    //Zero Constructor
    Node()
    {
        data = 0;
        next = nullptr;
    };

    // tail add
    // Next pointer in a tail allways points to null
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    };

    //middle insertion
    Node(int data, Node *nextNode)
    {
        this->data = data;
        next = nextNode;
    };
};

#endif // NODE_H
