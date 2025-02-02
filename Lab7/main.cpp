/*
Name: Jacob Knoeppel     NetID: jck382
Date: 11/5/24            Due Date: 11/8/24
Description:
This is a hexadecimal conversion program.
It utlizes a stack to enable correct calculation in the hexConversions function.
*/

#include <iostream>
#include <string>
#include <cmath>

#include "stack.h"

using namespace std;

string verifyValidHex(string hex);

int charToNum(Stack stack);
int hexConverions(string input);


int main()
{
    Stack temp;
    string userInput;

    cout << "Enter a word: ";
    getline(cin, userInput);
    cout << endl;

    // loops through the word, adding each character to the Stack
    for(int i = 0; i < userInput.size(); i++)
    {
        temp.add(userInput[i]);
    }

    // then ... loops through the Stack, outputing items as it removes from the Stack
    for(int i = 0; i < userInput.size(); i++)
    {
        cout << temp.remove();
    }
    cout << endl;

    /*
    string input;

    while(1)
    {
        input = " ";

        cout << "Please enter the hex decimal number you wish to convert: ";
        getline(cin, input);

        // runs verifyVaildHex to verify input - input is then set equal to return
        input = verifyValidHex(input);

        cout << endl;

        // outputs the users converted number
        cout << "Your converted number: " << hexConverions(input) << endl;

        cout << "Would you like to convert another number? (yes/no) ";
        getline(cin, input);

        // Loop to ensure corret continue/exit entry
        while(1)
        {
            if(input == "no")
            {
                cout << "Goodbye!" << endl;
                return 0;
            }
            else if(input == "yes")
            {
                break;
            }
            else
            {
                cout << "Invalid Input, please try again: ";
                getline(cin, input);
            }
        }

        cout << endl;

    }
*/
    return 0;
}

string verifyValidHex(string hex)
{
    // finds the index of the first character that doesn't match this set
    // if there's no character not in the set it returns -1
    int num = hex.find_first_not_of("0123456789ABCEDF");

    // runs while a char other than what we want is present
    while(num > -1)
    {
        // error message
        cout << endl << "Error. An invalid character was present in the hex number." << endl;
        cout << "Please try again with characters 0-9 and A-F only." << endl;

        // and new input
        cout << endl << "Enter in a hexadecimal number to convert: ";
        getline(cin, hex);

        // retests...
        num = hex.find_first_not_of("0123456789ABCEDF");
    }

    // returns validated number
    return hex;
}

int hexConverions(string input)
{
    Stack stack;
    int number;
    char nums;
    int hexNumber = 0;
    int num;

    //Adds the characters from the string to the stack
    for(int i = 0; i < int(input.size()); i++)
    {
        stack.add(input[i]);
    }

    for(int i = 0; i < int(input.size()); i++)
    {
        //calls the remove function and set the resulting return to nums
        nums = stack.remove();

        //converts the nums character to an int
        if(nums >= 48 && nums <= 57)
        {
            num = int(nums) - 48;
        }
        else
        {
            num = int(nums) - 55;
        }

        number = (pow(16, i) * num);

        // Adds number to hex number
        hexNumber = hexNumber + number;
    }

    return hexNumber;
}
