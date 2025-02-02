#include <iostream>
#include <string>
#include <vector>

#include <rectangle.h>

using namespace std;


// CLASSES
//
// Class --> coding construct that defines a new user made data type that can form an object (OOP)
// Object --> grouping of data and operations that can be performed on that data, instance of a class
//      -Variables created from classes are objects
//
// Classes should not define data/functions for more than one concept --> Good: Rectangles / Bad: Rectangels and triangles
// Classes should represent a singular object
//
// Benifts of Classes:
//      -Function benefits are amplified --> Function benefits are dialed to 110%. Makes working on code easier as it is segmented
//      -Neater, more condensed, more organized
//      -Makes larger industry sized project better organized and streamlined
//
// Input/output statements are typically not used in classes
// --> functions should be as reusable as possible and  not using input/ouput aids in the purpose
//
//
// Inheritance -
// - Base class
//      - Has propeties that can apply to many classes
//      - The idea that the base class is broad
// - Derived class
//      - Adds specific functionality to a base class
//      - A derived class inherits members (data and functions) for a base class
//      - Derived classes extend teh functionality of a base class
//


int main()
{
    // Any data type that is built in is purple, created data types are pink
    vector<int> numbers;
    string tempString;

    Rectangle temp;
    Rectangle temp1;


    cout << "Zero contructor: " << endl;
    cout << "Before setters: " << endl;
    cout << "Your area is: "<< temp.area() << endl;
    cout << "Your perimeter is: " << temp.perimeter() << endl;


    cout << "After setters: " << endl;

    temp.setHeight(3);
    temp.setWidth(5);

    cout << "Getting height: " << temp.getHeight() << endl;
    cout << "Getting widht: " << temp.getWidth() << endl;

    cout << "Your area is: "<< temp.area() << endl;
    cout << "Your perimeter is: " << temp.perimeter() << endl;
    cout << endl;

    Rectangle random(4,5);

    cout << "Parameter contructor: " << endl;
    cout << "Before setters: " << endl;


    cout << "Getting height: " << random.getHeight() << endl;
    cout << "Getting widht: " << random.getWidth() << endl;

    cout << "Your area is: "<< random.area() << endl;
    cout << "Your perimeter is: " << random.perimeter() << endl;



    cout << "After setters: " << endl;

    random.setHeight(6);
    random.setWidth(9);

    cout << "Getting height: " << random.getHeight() << endl;
    cout << "Getting widht: " << random.getWidth() << endl;

    cout << "Your area is: "<< random.area() << endl;
    cout << "Your perimeter is: " << random.perimeter() << endl;
    cout << endl;


    vector <Rectangle> rectangles;
    rectangles.push_back(temp);
    rectangles.push_back(random);

    rectangles.push_back((Rectangle(1,2)));


    for(int i = 0; i < int(rectangles.size()); i++)
    {
        cout << "Width: " << rectangles[i].getWidth() <<endl;
        cout << "Height: " << rectangles[i].getHeight()  <<endl;
        cout << endl;
    }

    return 0;
}
