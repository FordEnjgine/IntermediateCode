#include <iostream>

#include "linkedlists.h"

using namespace std;

// This content is important to understand
// This is difficult content, ask if any question arise
//
// We conver examples of linked list functions on Monday

// Linked Lists:
// - Most basic type of data structures --> entry level
// - not rules for adding and removing items
// - a list that utilizes pointers to indicate which item in the sequence comes next
// - Not actually a structure that has code to handle operations for you
// -- Must be built from scratch

// Common Terms
// - Node: Item in a linked list
// -- Commonly formed as a "struct" Or a small data class
// -- allows for a data type of its own
// -- struct -> shortene form of a class that only contains data
// -- data class -> continas data and usually only constructors and/or getters and setters
// - Head - the front of the list - required otherwise a memory leak occurs
// - Tail - the end of a list -- not required

// Singly Linked List
// - A list witn one single pointer linking the next item of the list
// - data can be of whatever data type the node strucutre dictates
// If the linked list only has one item, the head and tail point to the same thing

// Struct
// Usaully meant to be an abbreviated form of a data type
// Only limited to variables

// Double Linked List
// Three variables - one for data, one for forward node, one for back node
// Head previous pointer will alawys point to nullptr
//

int main()
{
    LinkedLists nums;

    nums.append(8);
    nums.append(0);
    nums.append(4);

    nums.display();
    cout << endl;

    nums.pop();

    nums.display();





    return 0;
}
