/*
Name: Jacob Knoeppel       NetID: jck382
Date: 10/22/24    Due Date: Nov 1, 2024

Description: This program is the underlying class to the functioning of the linked list
It it includes mutiple funcitons:
-Append: Appends a value to the end of the list
-Pop: Deletes the last values of the list
-insert: Adds a node at a user selected index
-remove: removes a node at a user selected index
-removeValue: removes any node with a certian number value
*/

#include "linkedlist.h"

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

LinkedList::~LinkedList()
{
    if(size > 0)
    {
        Node *temp;

        while(head != nullptr)
        {
            // grabs the node after the head
            temp = head->next;

            // deletes the head
            delete head;

            // reassigns the head
            head = temp;
        }
    }
}

// given to students
void LinkedList::display()
{
    // error check:
    // checks if the current size is zero
    if(size == 0)
    {
        cout << "List was empty -- display failed!" << endl;
    }

    // starts temporary Node at the beginning (head)
    Node *temp = head;

    for(int i = 0; i < size; i++)
    {
        // displays information
        cout << i << ": " << temp->number << endl;

        // moves the temp node to the next node in the sequence
        temp = temp->next;
    }
}

void LinkedList::reverseDisplay()
{
    // error check:
    // checks if the current size is zero
    if(size == 0)
    {
        cout << "List was empty -- display failed!" << endl;
    }

    // starts temporary Node at the end (tail)
    Node *temp = tail;

    for(int i = (size - 1); i >= 0; i--)
    {
        // displays information
        cout << i << ": " << temp->number << endl;

        // moves the temp node to the previous node in the sequence
        temp = temp->prev;
    }
}

void LinkedList::append(int number)
{
    // if the list is currently empty
    if(size == 0)
    {
        // create a new node at the head
        // with the information brought in
        head = new Node(number);

        // assigns tail to the head
        tail = head;
    }

    // otherwise, if it's not empty
    else
    {
        // creates a new node
        // with the information brought in
        // points the prev pointer to the tail
        Node *temp = new Node(number, tail, nullptr);

        // point current tail to new node
        tail->next = temp;

        // make new node the new tail
        tail = temp;
    }

    size++;
}

void LinkedList::pop()
{
    // error check:
    // checks if the current size is zero
    if(size == 0)
    {
        cout << "List was empty -- pop failed!" << endl;
        return;
    }

    // if removing a node will empty the list
    if(size == 1)
    {
        // store current head
        Node *temp = head;

        // sanity check clear head and tail
        head = nullptr;
        tail = nullptr;

        // delete node
        delete temp;
    }

    // otherwise, if it won't empty the list...
    else
    {
        // grab the node before the tail
        Node *temp = tail->prev;

        // delete the current tail
        delete tail;

        // sanity check clear the next pointer
        // and assign the new tail
        tail = temp;
        tail->next = nullptr;
    }

    size--;
}

// **********************************************************************
// you must create

void LinkedList::insert(int number, int position)
{
    // Temporary nodes used for insertion
    Node *temp;
    Node *temp2;

    if(position < 0 || position > size+1)
    {
        cout << "This is not a valid positon!" << endl;
        return;
    }
    //Head insertion
    else if(position == 0)
    {
        temp = new Node(number);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    //Tail insertion
    else if(position == size - 1)
    {
        temp = new Node(number);
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
    // Middle Insertion
    else
    {
        temp = head;
            for(int i = 0; i < position - 1; i++)
            {
                temp = temp->next;
            }
            //Create New node for insertion
            temp2 = new Node(number);
            // Sets the pointers for the inserted node
            temp2->prev = temp;
            temp2->next = temp->next;
            temp->next = temp2;
            if(temp2->next->prev != nullptr)
            {
                temp2->next->prev = temp2;
            }
    }

    size++;
}

void LinkedList::remove(int position)
{
    // Temporary node used for removal
    Node *temp;

    if(position < 0 || position > size+1)
    {
        cout << "This is not a valid positon!" << endl;
        return;
    }
    //Head removal
    else if(position == 0)
    {
        temp = head->next;

        delete head;

        head = temp;
    }
    // Tail removal
    else if(position == size - 1)
    {
        temp = tail->prev;

        delete tail;

        temp -> next = nullptr;

        tail = temp;
    }
    // Middle deletion
    else
    {
        temp = head;
        for(int i = 0; i < position; i++)
        {
            temp = temp->next;
        }

        //Sets the next pointer of the node in front of the deleted node to the node following the deleted node.
        temp->prev->next = temp->next;
        //Sets the prev pointer of the node in behind the deleted node to the node in front of the deleted node.
        temp->next->prev = temp->prev;

        //Node deletion
        delete temp;

    }

    size--;
}

void LinkedList::removeValue(int number)
{
    Node *temp = head;
    int counter = 0;
    int numDeleted=0;

    // Increments a counter for each of the instances of a number, returns if counter == 0
        for(int i = 0; i < size - 1; i++)
        {
            if(temp->number == number)
            {
                counter++;
            }
        }
        if(counter == 0)
        {
            // Output error message if value does not exist in list and return
            cout << "This is not a value in the list!" << endl;
            return;
        }

    // Iterates according to the number of values wished to be removed
    while(counter != 0)
    {
        while(temp != nullptr)
            {
                if(temp->number != number)
                {
                    temp = temp->next;
                }
                else
                {
                    //Head deletion
                    if(temp == head)
                    {
                        temp = head->next;

                        delete head;

                        head = temp;
                    }
                    //Tail deletion
                    else if(temp == tail)
                    {
                        temp = tail->prev;

                        delete tail;

                        temp -> next = nullptr;

                        tail = temp;
                    }
                    //Middle deletion
                    else
                    {
                        temp->prev->next = temp->next;
                        temp->next->prev = temp->prev;

                        delete temp;
                    }
                    //Increment numDeleted to keep track of amount fo numbers deleted
                    numDeleted++;
                    break;
                }
            }
            // Reset temp to head to enable a next run through
            temp = head;
            // Decrement counter
            counter--;
    }
    // Correctly decrease size based on number of items deleted
    size -= numDeleted;
}

// **********************************************************************
