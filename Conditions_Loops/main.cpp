#include <iostream>
#include <string>

using namespace std;

int main()
{
    int number;

    cout <<"Enter a number: ";
    cin >> number;

    /*
    //conditions
    //if/else if
    // if(condition) --> remember parentheses
    // { } --> surrounds the code that is being executed when the condition is true

    //compound condition
    // and --> &&
    // or --> ||

    //Chain if/ else if statements are generally most optimal. Fringe cases might benift from other strategies

    if(number > 0 && number <= 10)
    {
        cout <<"Your number was in the range of 1 - 10." << endl;
    }

    else if(number == 6)
    {
        cout <<"Your number was: " << number << endl;
    }

    else
    {

        cout <<"None of these things are true." << endl;
    }


    //Data type comparisons

    //Characters use the ASCII number for comparisions AND math
    // A is 65 in the ASCII table
    if('A' == 65)
    {
        cout << "This is equal"<< endl;
    }

    //This is valid
    cout << 'A' + 6 << endl; //Outputs 71
    cout << char('A' + 6) << endl; //Outputs capital G
    cout << char('X' + 7) << endl; //Outputs _

    */

    // Switch Statements
    // Also refered to at switch/case statement
    // This compares one variable against multiple VALUES
    // For eqaulity specifically
    // ONLY allows built-in data types
    // Is used over other conditions for optimization reasons - mainly only when comparing for eqaulity
    //
    // switch(variable)
    // built of cases for the comparsions
    // A new value --> new case
    // Default - Similar to else in conditons

    /*
    //This is incorrect
    // Once a case is triggered at true, it runs every case after that.
    switch(number)
    {
        case 5:
        cout << "Your number is 5" <<endl;

        case 8:
        cout << "Your number is 8" <<endl;

        case 11:
        cout << "Your number is 11" <<endl;

    }

    //This is correct. Add a break statment to break out of the function
    switch(number)
    {
    case 1:
    case 2:
    case 3:
    case 4:
        cout<<"Your number is in the range of 1- 4" << endl;
        break;
    case 5:
        cout << "Your number is 5" <<endl;
        break;

    case 8:
        cout << "Your number is 8" <<endl;
        break;

    case 11:
        cout << "Your number is 11" <<endl;
        break;

    case 32:
    case 45:
    case 902:
        cout<< "You entered  32, 45, or 902" << endl;
        break;

    default:
        cout<< "You did not enter a correct value" << endl;
    }
    */

    //For loops
    //Purely numerical based - counting loops (numerical)
    //REQUIRED to be integer
    //
    // for( A ; B ; C ){ }
    // A --> Starting point
    // The variable (counter) must be declared here or prior
    // Most commonly i
    //
    // B --> Ending point
    // This point must be achievable comparison
    //
    // C --> How the variable changes
    // The variable (I) MUST change for this to work
    // Good examples:
    // Adding 1 --> i = i + 1 / i += 1 / i++
    // Subtracting 1 --> i = i - 1 / i -= 1 / i--
    // Adding any value above 1 -> i = i + value / i += value
    // Subtracting any value above 1 --> i = i - value / i -= value
    // Bad examples:
    // i + 1 / i ++ 1 /

    /*
    // Example 1;
    for(int i=0; i < 10; i++)
    {
        cout << i << endl;
    }
    cout << endl;

    // Example 2;
    for(int i=0; i < number; i++)
    {
        cout << i << endl;
    }
    cout << endl;

    // Example 3:
    for(int i=10; i > 0; i--)
    {
        cout << i << endl;
    }
    cout << endl;

    // Example 4 (Does not work):
    for(int i = 0; i == 100; i++){
        cout << i << endl;
    }
    cout << endl;

    //Example 5 (Does not work - Infinite):
    for(int i = 0; i != 100; i+=3){
    cout << i << endl;
    }
    cout << endl;
    */

    // While Loops
    // conditional loops
    // while(conditon)

    //Infinite loop notes:
    // - not repeating to change the variable
    // - condition is not possible
    // - if you do not have a break condition

    string answer;

    cout << "Do you like cats?" << endl;
    cin >> answer;
    while(answer != "yes") // Condtion is not possible if condition is (answer != yes || answer != no)
    {
        cout << "Invalid answer, please try again:" << endl;
        cin >> answer;
    }

    //Nesting -
    //Pay attention to curly braces lining up with each structure that is nested having their own curly braces

    // Variable scope-
    // Variables DECLARED inside a structure can't be used outside that structure - they are local to the function
    // If a variable has to be used after the structures run time it should be intilaized outside the function
    // Anything with curly braces has scope

    return 0;
}
