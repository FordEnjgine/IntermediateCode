#include "rectangle.h"

// zero constructor --> zero values out;
Rectangle::Rectangle()
{
    width = 0;
    height = 0;
    color = "";

    //
    name = "Rectangle";
    sides = 4;
}
Rectangle::Rectangle(int width, int height)
{
    this->width = width;
    this->height = height;
}

int Rectangle::area()
{
    return width * height;
}

int Rectangle::perimeter()
{
    return (2 * width) + (2 * height);
}

// (this->) is only required when reffering to class variable, is a pointer
void Rectangle::setWidth(int width)
{
    this->width = width;
}

void Rectangle::setHeight(int setHeight)
{
    height = setHeight;
}

int Rectangle::getWidth()
{
    return width;
}

int Rectangle::getHeight ()
{
    return height;
}
