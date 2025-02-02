#include <string>

#ifndef SHIP_H
#define SHIP_H

using namespace std;

class Ship
{
    private:
        int lenght;
        string hitChar;

    public:
        Ship();
        Ship(int lenght);

        void updateShip(int hitLocation, string *ship);

        //Getters
        int getLenght();

};

#endif // SHIP_H
