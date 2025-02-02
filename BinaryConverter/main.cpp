/*
* Name: Jacob Knoeppel     NetID: jck382
* Date: 09/22/2024
* Description:
* Main function: Ask the user to input a number corresponding to an option
* testNumber(string item) function: This function test whether there are any non-number characters in the users inputed string.
* It returns 0 if the string is only numbers and 1 if there are non-number characters
* getNumber() function: This function uses testNumber and uses a loop the ensurese the user inputs a string that does not include non-number characters.
* It then converts the string to an integer and returns the integer
* convert(int number) function: This converts the number from getNumber() into a string that represnts the number in binary
* It implments the math library and appends "0" or "1" to a string depnding on the result of the lograthmic expression.
* It uses a for loop to continue operation until i = 0 is reached. It then returns a string that is output in main()
*/
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

string convert(int number);

// user input verification
int getNumber();
int testNumber(string item);

int main()
{
    string option;
    cout << "Welcome to decimal to binary conversion!" << endl;
    // menu loop
    while(1)
    {
        cout << endl << "Menu: " << endl;
        cout << "0. Exit" << endl;
        cout << "1. Test Number (Milestone 1 Testing)" << endl;
        cout << "2. Get Number (Milestone 2 Testing)" << endl;
        cout << "3. Convert A Number" << endl;
        cout << "Enter your menu option: ";
        getline(cin, option);
        // spacing
        cout << endl;
        // exit
        if(option == "0")
        {
            cout << "Good-bye!" << endl;
            break;
        }
        // test number
        else if(option == "1")
        {
            string item;
            cout << "Enter in a number: ";
            getline(cin, item);
            cout << endl << "Test Number value: " << testNumber(item) << endl;
        }
        // get number
        else if(option == "2")
        {
            int number = getNumber();
            cout << endl;
            // to show it's an integer...
            cout << "Your number in some math: " << endl;
            cout << number << " + 5 = " << number + 5 << endl;
            cout << number << " * 8 = " << number * 8 << endl;
        }
        // conversion
        else if(option == "3")
        {
            int number = getNumber();
            cout << endl << "Your number in binary is: " << convert(number) <<
                endl;
        }
        // incorrect menu option
        else
        {
            cout << "That's not a valid menu option. Try again." << endl << endl;
        }
    }
    return 0;
}

int getNumber()
{
    // Creates a user input string and creates a variable to hold the return value
    string userInput;
    int number;

    // Prompts the user to input a number and takes it in as a string
    cout << "Enter in a number: ";
    getline(cin, userInput);

    // Loops until the user inputs a string that contains only numbers
    while(testNumber(userInput) == 1){
        cout << "The number you have entered is invalid.\nPlease try again." << endl;
        cout << "Enter in a number: ";
        getline(cin, userInput);

    }

    //Converts the users string into an integer
    number = stoi(userInput);

    // Returns the user number as an int
    return number;

}


int testNumber(string item)
{
        //Loop through the string, a character array
        for(int i = 0; i < int(item.length()); i++)
        {
            // Returns 1 if the char at item[i] is not a digit
            if(!isdigit(item[i]))
            {
                return 1;
            }
        }
    return 0;
}


string convert(int number)
{
    string binaryNumber;

    if(number == 0)
    {
        return "0";
    }

    for(int i = log2(number); i >= 0; i--){
        // Appends 0 to binaryNumber if log2(number) != i
        if(int(log2(number)) != i){
            binaryNumber = binaryNumber + "0";
        }
        // Appends 1 to binaryNumber if log2(number) = i
        else{
            number = number - pow(2,int(log2(number)));
            binaryNumber = binaryNumber + "1";
        }
    }

    return binaryNumber;
}
