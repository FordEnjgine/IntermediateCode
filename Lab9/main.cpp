/*
Name: Jacob Knoeppel        NetID: jck382
Date: 11/19/24              Due Date: 11/21/24
Description: This program utilizes a recursive funtion to encode and decode a chiper
*/

#include <iostream>
#include <string>

using namespace std;

string caesarShift(string phrase, int position, bool encode);

int main()
{
    // welcome message
    cout << "Welcome to a recursive Caesar cipher simulator." << endl;

    string option;

    // menu loop
    while(1)
    {
        // menu setup
        cout << endl << "0. Exit" << endl;
        cout << "1. Encode a Message" << endl;
        cout << "2. Decode a Message" << endl;
        cout << "Enter your choice: ";
        cin >> option;

        // spacing
        cout << endl;

        // exit
        if(option == "0")
        {
            cout << "Good-bye!" << endl;
            break;
        }

        // encode
        else if(option == "1")
        {
            string word;
            cin.ignore(); // make sure getline works properly...

            cout << "Enter in a word/phase to encode: ";
            getline(cin, word);

            // encodes
            // calls function with bool --> true
            word = caesarShift(word, 0, true);

            // displays to the user
            cout << endl << "Your encoded message is: " << word << endl;
        }

        // decode
        else if(option == "2")
        {
            // variable creation
            string word;
            cin.ignore(); // make sure getline works properly...

            cout << "Enter in a word/phase to decode: ";
            getline(cin, word);

            // decode
            // calls function with bool --> false
            word = caesarShift(word, 0, false);

            // displays to the user
            cout << endl << "Your decoded message is: " << word << endl;
        }

        // wrong choice
        else
        {
            cout << "You entered an invalid option. Try again." << endl;
        }
    }

    return 0;
}

string caesarShift(string phrase, int position, bool encode)
{
    //Base Case
    if(position == int(phrase.size()))
    {
        return phrase;
    }

    if(encode)
    {
        // Inital Check for whether the character is a letter
        if((phrase[position] >= 65 && phrase[position] <= 90) ||  (phrase[position] >= 97 && phrase[position] <= 122))
        {
            //Check for whether the character + 5 is greater than 90 or 122
            if((phrase[position] >= 65 && phrase[position] + 5 <= 90) ||  (phrase[position] >= 97 && phrase[position] + 5 <= 122))
            {
                phrase[position] = char(phrase[position] + 5);
            }
            // Subtract 21 if character + 5 goes above the ASCII value for the alphabet
            else
            {
                phrase[position] = char(phrase[position] - 21);
            }
        }
    }
    else
    {
        if((phrase[position] >= 65 && phrase[position] <= 90) || (phrase[position] >= 97 && phrase[position] <= 122))
        {
            //Check for whether the character - 5 is less than 65 or 97
            if((phrase[position] - 5 >= 65 && phrase[position] <= 90) || (phrase[position] - 5 >= 97 && phrase[position] <= 122))
            {
                phrase[position] = char(phrase[position] - 5);
            }
            // Add 21 if chacter - 5 goes below the ASCII value for the alphabet
            else
            {
                phrase[position] = char(phrase[position] + 21);
            }
        }
    }

    // Phrase is set equal to the return of the next recusive call to ensure correct final return to user
    phrase = caesarShift(phrase, position + 1, encode);

    return phrase;
}
