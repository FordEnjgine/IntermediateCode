#include <iostream>
#include <vector>
#include <string>

using namespace std;

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
private:
    int width, height;
    string color;
public:
    Rectangle(); //Zero constructor
    Rectangle(int width, int height);

    int area();
    int perimeter();
    //Getters
    int getWidth();
    int getHeight();
    //Setters
    void setWidth(int width);
    void setHeight(int setHeight);
};

#endif // RECTANGLE_H
