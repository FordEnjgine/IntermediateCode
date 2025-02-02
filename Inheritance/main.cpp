#include <iostream>

#include "rectangle.h"

using namespace std;

int main()
{
    Rectangle temp;
    cout << "The shape is a " << temp.getName() << "." << endl;
    cout << "It has " << temp.getSides() << " sides." << endl;

    return 0;
}
