#include <string>

using std::string;

#ifndef SHAPE_H
#define SHAPE_H

class Shape
{       
    // public --> to the class and that items that are derrived - items extending your base class
    // private --> to the items calling the class
    protected:
        string name;
        int sides;

    public:
        Shape();

        // getters -->
        int getSides();
        string getName();

};

#endif // SHAPE_H
