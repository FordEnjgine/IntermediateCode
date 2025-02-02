/*
Name: Jacob Knoeppel    NetID: jck382
Date: 11/12/24          Due Date: 11/14/24
Description: Linked List class containing:
Binary Search: Searches a list and returns the first index of that number
reverse sort: Sorts the list in descending order
Remove values: Utilizes Binary Serach to remove all node with data that matchs the number the user wishes to remove;
*/
#include "linkedlist.h"

// constructor and destructor (given to you)
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

// display and add functions (given to you)
void LinkedList::display()
{
    // starts temporary Node at the beginning (head)
    Node *temp = head;

    while(temp != nullptr)
    {
        // displays information
        cout << temp->number << endl;

        // moves the temp node to the next node in the sequence
        temp = temp->next;
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
        Node *temp = new Node(number);

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
        Node *temp = head;

        while(temp->next->next != nullptr)
        {
            temp = temp->next;
        }

        // delete the current tail
        delete tail;

        // sanity check clear the next pointer
        // and assign the new tail
        tail = temp;
        tail->next = nullptr;
    }

    size--;
}

// this shows selection sort
// as applied to linked lists
void LinkedList::sort()
{
    // example shows: selection sort
    for(int i = 0; i < size - 1; i++)
    {
        int smallIndex = i;

        for(int j = i + 1; j < size; j++)
        {
            // gets node at j
            Node *jItem = head;
            for(int k = 0; k < j; k++)
            {
                jItem = jItem->next;
            }

            // gets node at smallIndex
            Node *smallIndexItem = head;
            for(int k = 0; k < smallIndex; k++)
            {
                smallIndexItem = smallIndexItem->next;
            }

            // runs comparison
            if(jItem->number < smallIndexItem->number)
            {
                smallIndex = j;
            }
        }

        // grabs node at index i
        Node *current = head;
        for(int k = 0; k < i; k++)
        {
            current = current->next;
        }

        // grabs node at index smallIndex
        Node *small = head;
        for(int k = 0; k < smallIndex; k++)
        {
            small = small->next;
        }

        // grabs the information at the current node
        // stores it
        int tempNumber = current->number;

        // swaps current data to small data
        current->number = small->number;

        // overwrites small data to the stored data
        // (what used to be in current)
        small->number = tempNumber;
    }
}

// an example of a shuffle algorithm
void LinkedList::shuffle()
{
    // seeds random number
    srand(time(NULL));

    for(int i = 0; i < size; i++)
    {
        int num = rand() % size;

        // swaps current "index" with random "index"

        // gets node at current position
        Node *current = head;
        for(int j = 0; j < i; j++)
        {
            current = current->next;
        }

        // gets node at random position
        Node *random = head;
        for(int j = 0; j < num; j++)
        {
            random = random->next;
        }

        // stores the current Node's information
        int tempNumber = current->number;

        // reassigns the random Node's information to the current
        current->number = random->number;

        // and the stored current information to the random Node
        random->number = tempNumber;
    }
}


// ****************************************************************
// ** you should make **
// ****************************************************************

// any links to resources to make it work:
// https://www.tutorialspoint.com/binary-search-on-singly-linked-list-in-cplusplus
// This resource helped outline how to setup high, low, and mid to the correct values after each iteration
int LinkedList::binarySearch(int number)
{
    int low = 0;
    int high = size-1;
    int mid;

        while(low <= high)
        {
            mid = (high + low) / 2;
            Node *temp = head;
            int data = temp->number;

            for(int i = 0; i < mid; i++)
            {
                temp = temp->next;
                data = temp->number;
            }

            if(data == number)
            {
                return mid;
            }

            if(data < number)
            {
                low = mid +1;
            }
            else
            {
                high = mid - 1;
            }
        }
    return -1;
}


// algorithm of choice:
// any links to resources to make it work: https://www.geeksforgeeks.org/bubble-sort-for-linked-list-by-swapping-nodes/
// This website supplied the alorgithim for this sort.
void LinkedList::reverseSort()
{
    Node *temp = head;
    bool swapped;
    int itr = 0;

    int len = 0 ;
    while(temp!= nullptr)
    {
        len++;
        temp=temp->next ;
    }

    // Bubble sort
    while(itr < len)
    {
        Node *travNode = head;
        Node *prevNode = head;
        swapped = false;

        while(travNode->next)
        {
            Node *ptr = travNode->next;
            if(travNode->number < ptr->number)
            {
                swapped = true;
                    if(travNode == head)
                    {
                        travNode->next = ptr->next;
                        ptr->next = travNode;
                        prevNode = ptr;
                        head = prevNode;
                    }
                    else
                    {
                        travNode->next = ptr->next;
                        ptr->next = travNode;
                        prevNode->next = ptr;
                        prevNode = ptr;
                    }
                    continue;
            }
            prevNode = travNode;
            travNode = travNode->next;
        }

        if(!swapped)
        {
            break;
        }
        ++itr;
    }
}

void LinkedList::removeValues(int number)
{
    int index = 0;
    Node *temp;
    Node *prev;

    // Checks the list for the value - prints an error statment and returns if no instance is found
    while(binarySearch(number) < 0)
    {
        cout << endl;
        cout << "Not in the list!" << endl;
        return;
    }


    while(1)
    {
        index = binarySearch(number);

        // Exits loop once index = -1
        if(index < 0)
        {
            cout << "Remove Done" << endl;
            return;
        }

        // Head removal;
        if(index == 0)
        {
            temp = head;
            head = head->next;
            delete temp;
            size--;
        }
        //Tail removal;
        else if(index == size -1)
        {
            pop();
        }
        // Middle removal
        else if(index > 0)
        {
            prev = head;
            for(int i = 0; i < index - 1; i++)
            {
                prev = prev ->next;
            }

            temp = prev->next;

            prev->next = temp->next;

            delete temp;

            size--;
        }
    }
}


// ****************************************************************
// ****************************************************************


// HONORS / BONUS credit
// optional unless you're honors
// if not implementing, just leave them here
void LinkedList::differentSort()
{

}
