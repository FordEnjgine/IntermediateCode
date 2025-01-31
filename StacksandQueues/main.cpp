#include <iostream>

using namespace std;

// Adding limitations to existing structures
// Princple of how to deal with data

//Data Structure Priniples
// - Most strucutres can insert and remove items regardles of the positing of the items - inserting or removing for the start, middle, and end
// - LIFO - last in, first out
// - FIFO - first in, first out
// - These princples limit where items can be added and removed from when dealing with structures - we are applying them to linked lists


// STACKS (LIFO)
// Items can be added and removed only from the beginning of the strucutre
// Comparable to a stack of dinner plates, you add and remove plates to/from the top of the stack
// The top of the stack is the beginning of the list
// Head -> top/beginning of stack

// Queues (FIFO)
// Items can only be removed from the head of the queue and can only be added to the tail of the queue
// Comparable to a line
// Beginning of the queue is the begiining of the list
// head -> beginning of queue
// tail -> end of queue

// Use cases - stacks
// Arithmetic
// -- Shunting yard algorithm
//
// Rolling back changes
// -- Undo/Redo buttons in editors
// -- Forward/Back buttons on browsers
//
// Function scheduling
// -- Recursive
//
// Binary to devimal conversion - generally many type of other conversions to
//
// Reversing data

// Lab -
// The majority of the lab is not making the stack, but using it

// Use cases - queues
//
// First come, first serve scheduling
// - Printers, CPU resources, disk storage, etc
// - Buffers (keyboards, controller input, etc)
//
// Implementation of priority queues
// - Dijkstra's shortest path
// - Prim's alogithm


int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
