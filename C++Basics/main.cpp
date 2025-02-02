#include <iostream>
#include <string>


using namespace std;

//using std::cout;

int main()
{
    cout << "Hello World!" << endl;

    //std library set (namespace)

    //output
    //cout --> console output
    // << output << --> point to the left
    // have << output << for every item you are going to print

    string animal = "dog";

    // \n is the newline character
    cout << animal << "\n" << endl;

    //input
    //two ways to do it
    // --> cin (iostream)
    // --> getline (string)

    int number;
    string name;

    //method 1
    //cin
    // >> --> pointing right
    // cin >> variable >>;
    //
    // cin can store any data type (that has a programmed method)
    // All inbuilt data types can be stored but it can store other data types
    // Limitations stops at the first whitespace (ANY whitespace such as tab or space). It stops before it proccess the whitespace character.

    cout <<"Enter a number: ";
    cin >> number;

    cout <<"Your number is: " << number << endl;

    cout<< endl << "Please enter your name: ";
    cin >> name;

    cout <<"Your name is: " << name << endl;

    cin.ignore();

    //Only used between last cin and first getline()
    //Only applies if you mix them
    //cin.ignore();

    // Method 2
    // uses getline
    // getline( input stream, variable)
    // input stream --> cin
    //
    // Upside: Stops at the first instance of a newline
    // Downside: Can only store strings

    cout<< endl << "Please enter your name: ";
    //cin >> name;
    getline(cin, name);

     cout <<"Your name is: " << name << endl;

        return 0;
    }

