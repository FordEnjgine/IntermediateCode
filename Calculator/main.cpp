#include <iostream>
#include <string>

using namespace std;

int main()
{
    int input;
    int inputOne;
    int inputTwo;
    double answer;
    int loopVariable =0;

    cout <<"Welcome to this calculator! Please enter which of the following options you would like to select: \n1. Multiplication \n2. Division \n3.Addition \n4. Subtraction" << endl;

    while(loopVariable == 0){
        cin >> input;

        if(input == 1){
            cout << "Please enter your first number: " << endl;
            cin >> inputOne;
            cout << "Please enter your second number: " << endl;
            cin >> inputTwo;
            answer = (inputOne * inputTwo);
            cout <<"The answer to " << inputOne << " * " << inputTwo << " is " << answer << endl;
        }

    }
    return 0;
}
