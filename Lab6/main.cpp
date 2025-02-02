#include <iostream>
#include <string>
#include "linkedlist.h"

// using statements
using std::string;
using std::getline;
using std::cout;
using std::cin;
using std::endl;

void initializeList(LinkedList &numbers);

int main()
{
    // creates a linked list
    // and sets it up with some numbers
    LinkedList numbers;
    initializeList(numbers);

    // welcome
    cout << "Welcome to the nusmber manager!" << endl << endl;

    string option;

    // menu!
    while(1)
    {
        cout << "Menu: " << endl;
        cout << "0. Exit" << endl;
        cout << "1. Display" << endl;
        cout << "2. Reverse Display" << endl;
        cout << "3. Insert Item" << endl;
        cout << "4. Remove Item" << endl;
        cout << "5. Remove Values" << endl;
        cout << "Enter your menu option: ";
        getline(cin, option);

        cout << endl;

        // exit
        if(option == "0")
        {
            cout << "Good-bye!" << endl;
            break;
        }

        // display
        else if(option == "1")
        {
            numbers.display();
        }

        // reverse display
        else if(option == "2")
        {
            numbers.reverseDisplay();
        }

        // insert
        else if(option == "3")
        {
            numbers.display();
            cout << endl;

            // receives position from the user
            int pos;

            cout << "What position would you like to insert to? ";
            cin >> pos;

            // receives the number to insert from the user
            int num;

            cout << "What number would you like to insert? ";
            cin >> num;

            numbers.insert(num, pos);

            // runs ignore command to setup for getline
            cin.ignore();
        }

        // remove item
        else if(option == "4")
        {
            numbers.display();
            cout << endl;

            // receives position from the user
            int pos;

            cout << "What position would you like to remove from? ";
            cin >> pos;

            numbers.remove(pos);

            // runs ignore command to setup for getline
            cin.ignore();
        }

        // remove value
        else if(option == "5")
        {
            numbers.display();
            cout << endl;

            // receives number from the user
            int num;

            cout << "What number would you to remove? ";
            cin >> num;

            numbers.removeValue(num);

            // runs ignore command to setup for getline
            cin.ignore();
        }

        // wrong menu option
        else
        {
            cout << "Invalid menu option. Try again." << endl;
        }

        cout << endl;
    }

    return 0;
}

void initializeList(LinkedList &numbers)
{
    numbers.append(8);
    numbers.append(7);
    numbers.append(4);
    numbers.append(6);
    numbers.append(1);
    numbers.append(8);
    numbers.append(4);
    numbers.append(3);
    numbers.append(8);
    numbers.append(8);
    numbers.append(5);
    numbers.append(4);
    numbers.append(8);
}
