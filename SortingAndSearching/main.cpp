#include <iostream>

using namespace std;

// Two searching alorgthims
// 3 diffrenet sorting alrogithms
//
// Linear search
// Goes throught each indidivaul list items to check if tha itme is in the strucuture
// Time complexity: O(N)
// Works on sorted and unsorted lists
// Best case: items is found in the first check
// Simplest case
// Is this my item? no, move one | yes, return index
// If not found, return -1

// Binary Search
//
// Divide and counquers searching - checks the mid point and determines where to search next based on that midpoint
// Runtine O(log N) - better than linear time
// Only works on SORTED lists
//
// Establish high point, mid points, mid point
// High = size -1
// Low = 0
// Search ends when Low >= high
// Mid = High + low / 2
// Is mid == key?
// No, check if mid point value is > or < than mid point
// If mid point is >, set new high point @ mid point -1
// If mid point is <, set new low point @ mid point + 1

// Searching -
// Stops at first item of instance



// Sorting
//
// Monday: Not all types of sorting today
// Bubble is bad
// Selection and insertion are better

// Ordering
// Ascending and descending - flipping comparsions can often easily change this
//
// Bubble Sort
// Moves through the list, swaping two items if the first item is greater then the second item
// O(N^2)
// Basic algorithim
//
// Selection Sort
// Builds a sorted and unsoeted portion -- moves the smallest itemn to the end of the sorted portion
// O(N^2)
// Act as though there is a sorted partition at the beginning
// You find the smallest item
// You move it to the end of the sorted partition

// Insertion Sort -- very diffrenet from selection
// Still maintain the idea of sorted and unsorted paritition
// Grabs the first item at the beginning of the unsorted partition
// You place all items other than the first in the correct place, hence insertion sort

//Quicksort
// Runtime: O(N Log N)
// Divide and conquer algorithm using recursion - not nessarily perfect halfs
// The partition function determinces how it then recursivly calls quicksort - longer than the quick sort function
// Chooses a pivot point and moves all numbers less than the pivot and number greater than the pivot after it
// Recursively calls the sort on the new, loosely sort paritions
// Initally called with 0 and size -1;
//
// Parition fucntion
// Start: Sets high and low points
// Mid point is set with low + (high - low)/2
// The middle point is the pivot point
// Then starts at the low point -> start of the comparison
// Then get to a point that is larger than pivot - loop ends here
// Then similar thing happens in reverse, starting at high --> something is less than pivot is what you are looking for. Decrement high for each value less than pivot
// Compares low to high --> when low >= high --> exit function when this is true
// Swaps updated low and high untill low >= high
// Returns

// Mergesort
// Divide and Conquer
// Divides the list recursively in half untill it gets to one item in each half
// Merges the havles while maintaing ordering untill the list is fully sorted
// Uses i, j,k --> low, mid and high bassically
// Finds the mid point of the list, calls merge sort on the two halfs

// Merge Function:
// Things are represented as a right and left half
// Goal of merge sort --> creating a smaller sub list that is the lenght of both halves
// Secondary list --> constantly adding items from both halves of the merge
// Overwrites what is intially in
// Clean up - merge checks whether all numbers have been put in the sorted partition
// Deletes merge numbers array at the end, to prevent memory leak

// Heap sort
// Trees -> Every list can be represented as a tree -> each segement can only have two connected things and goes left to right
// Max heap -> at every item in a tree, everything under it should be less
// Untlizes heapify
// Largest items gets moved to the front of all exisiting items




int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
