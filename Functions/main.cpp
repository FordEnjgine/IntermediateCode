 #include <iostream>
#include <vector>

using namespace std;

// Functions
// Group of statements with a name that can be repeatedly called
//
// Parameter
// Variable declaration of a value to be passed to a function
// uses that name throughout the function body to utilize the parameter
// values from outsdie the function you want to use inside the function
// parametere != input statements inside the function
//
// Return value
// Item the function is returning to the place it was called
// Value from inside the fucntion you want to use outside of the funciton


// Function basics
// Two parts
//      Function definition/ decleration : Return type, name, parameter list
//      Function body : What is done when the function is called and is surrounded by curly braces

// It is nessary to declare a reutnr type ahead of time
// Possible return values: Standard built in data types, void( no return value), external data types (strings, vector, custom data types
//
// Parameters should have declared data types, determins the type of date that can solely be based to the parameter at that position
// Declared wihtin the parentheses following the function name.

// FUNCTION BENIFITS
// Reusability
// Readability
// Incremental development --> breaking problems into to smaller sub-problems
// Testing --> it is easier to test smaller section throughout code
// Reduces complexity of your main --> C++ and complied langauge specific

//Function Creation

//BEFORE vs AFTER
// Both work fine, neither is better optimized
//
// Before:
// -easiser
//      - Less hopping around (time)
//      - labeling (less moving parts, makes it eaiser to change return types, inputs, ETC)
// decentralizes the main function (downside)
//
// After:
// - must have matching function declearations
// - centralizes the main function
// - each function = one line description at the top
//      - often treated as a table of contents for the fucntions in your code
//      - makes it easier to see the labels and list of parameters


// Normal parameters
// pass by copy / pass by value
void changeNumber(int number);

int changeNumber_return(int number);

// Vector
// The way to change vectors is by using the & symbol and passing by refrence instead of returning
vector<int>  generateNumber();
void displayVector(vector<int> numbers);
void changeVector( vector<int> &numbers);

// Arrays in functions
// --> CANNOT return an array due to it not being a data type
// Array can be passed as a parameter
// Modifying arrays within in a function edits the values in the array, unlike vectors
void  displayArray(int numbers[], int size);
void changeArray(int numbers[], int size);

// Pass by refrence
// reference --> memory address
// --> &
// Cannot pass an array by reference
// Forces the computer to grab the memory locaiton so as not to create a copy which is the default way to pass variables
// This is useful when large variables would take up to much memory with created copies
// Better for memory usage in certian circumstances

// Cons:
// It is less efficient
// Can unintentionally alter a varliable if not care
//
// Rule of Thumb --> Do not use unless handling strings or vectors

void changeNumber_reference(int &number);

// Scope
//
// TRUE global (declared outside of the main)
// int five = 5;
// Global scope means that variables are avalible to many structures
// Globals should not be used as they can cause conflict within your program
// Reduces readbility of code
// Excpetions exist - take place in constants
// GLOBALS SHOULD NOT BE USED IN THIS CLASS!!!

// Local - only avaliable to a give structure

//Method 1
// Entire function is before the main
void sayHello(){
    cout << "Hello" << endl;
}

// Method 2
// Function decleration is before the main
// funtion decleration and body is after the main

int sum(int num1, int num2);

int main()
{
   // the main function has to be an int
   // return 0 is a way to state that the program has ended correctly
   // return 1 is a way to state that the program has ended unsuccessfully
   // optinal parameters for main (generally ommitted): int argc or char *argv[]
   //
   // Basic function calls

   /*
   sayHello();

    // Local only to main - num1 and num2 are passed as parameters
    int num1;
    int num2;
    int temp;

    cout << "Enter two integears to add: ";
    cin >> num1;
    cin >> num2;

    //Assigns temp with return value
    temp = sum(num1, num2);
    cout << "Solution: " << temp << endl;
    // or
    // Prints return value
    cout << "Solution: " << sum(num1, num2) << endl;
    */


   int number = 0;

   cout << "No return: " << endl;
   cout << "Number (before): " << number << endl;

   changeNumber(number);

   cout << "Number (after): " << number << endl;

   number = 0;
   cout << "Return: " << endl;
   cout << "Number (before): " << number << endl;

   number = changeNumber_return(number);

   cout << "Number (after): " << number << endl;

   number = 0;

   cout << "Via reference: " << endl;
   cout << "Number (before): " << number << endl;

   changeNumber_reference(number);

   cout << "Number (after): " << number << endl;


   vector<int> temp{4,5,6,7,8};

   cout<< "Before:" << endl;
   displayVector(temp);

   changeVector(temp);

   cout<< "After:" << endl;
   displayVector(temp);


   //Arrays
   cout << "Arrays:" << endl;

   int arrTemp[] = {4,5,6,7,8};
   cout << "Before:" << endl;
   displayArray(arrTemp, 5);

   changeArray(arrTemp, 5);

   cout << "After:" << endl;

   displayArray(arrTemp, 5);



    return 0;
}

int sum(int num1, int num2){
    return num1 + num2;
}

void changeNumber(int number){
    number = 1234;
}

int changeNumber_return(int number){
    number = 1234;
    return number;
}

void changeNumber_reference(int &number){
    number = 1234;
}

void displayVector( vector<int> numbers){
    for(int i = 0; i < numbers.size(); i++){
        cout<< numbers[i] << endl;
    }
    cout << endl;
}

void changeVector( vector<int> &numbers){
    for(int i = 0; i < numbers.size(); i++){
        numbers[i]++;
    }
}

void displayArray(int numbers[], int size){
    for(int i = 0; i < size; i++){
        cout<< numbers[i] << endl;
    }
    cout << endl;
}

void changeArray( int numbers[], int size){
    for(int i = 0; i < size; i++){
        numbers[i]++;
    }
}


