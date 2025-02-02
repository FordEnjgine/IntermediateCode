#include <iostream>
#include <string>

using namespace std;


// Recursion - function calling itself - stack behavior
// - way to repeatedly call code
// -- loop like - not a loop
//
// Base case - non-recusrive -- important for not having an infinite recursive loop
// How to call function again
//
// Pass as a parameter is required, this creates a copy - limitation
// In the spirt of looping, recusrion is not as good as normal loops
// Mutiple functions might be required for them to work like a single for loop

// Why recursion:
// Good for math functions - recurion plugs into math programs very easily
// If langauges do not have loops, recursion is required to emulate them
// It can save complicated nested loop/function calls

// Why not use recursion:
// If it can be done with a loop, USE the loop
// Stack overflow can occur - functions take up space in memory
// Stack overflow occurs becuase of to many funcation calls - tries to access memory that it does not have access to because it is not on the stack (segmentation fault)
// Passing by refrence for static variables helps with memory managment

void countDown(int num);

void countUp(int start, int end);

string verifyAnswers();

void palindrome(int num);


int main()
{
    for(int i = 0; i < 10000; i++)
        countDown(5);

    cout << endl;
    /*
    countUp(0,10);

    cout << endl;

    cout << endl;

    string answer = verifyAnswers();

    cout << "The final answer you gave is: " << answer << endl;


    cout << endl;

    palindrome(3);
    */

    return 0;
}



void countDown(int num)
{
    if(num > 0)
    {
        cout << num << "..." << endl;
        countDown(num-1);
    }

    // base case --> non recursive
    else
    {
        cout << "Go!" << endl;
    }
}

void countUp(int start, int end)
{
    if(start < end)
    {
        cout << start << endl;
        countUp(start+1, end);
    }

    /* base case - empty else because no base case is nessary for this function
    else
    {

    }
    */
}

void palindrome(int num)
{
    if(num > 0)
    {
        cout << num << endl;
        palindrome(num - 1);
        cout << num << endl;
    }
}

string verifyAnswers()
{
    string answer;
    cout << "Is the sky blue: ";
    cin >> answer;

    if(answer != "no" && answer != "yes")
    {
        cout << endl << "Error" << endl;
        // Gives the answer that broke out of the function - not random
        answer = verifyAnswers();
    }

    return answer;
}
