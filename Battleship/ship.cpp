#include "ship.h"

Ship::Ship() {}

Ship::Ship(int lenght)
{
    this->lenght = lenght;
    hitChar = "🔴";
}

void Ship::updateShip(int hitLocation, string *ship)
{
    for(int i = 0; i < lenght; i++)
    {
        if(i == hitLocation)
        {
            ship[i] = hitChar;
        }
    }
}


int Ship:: getLenght()
{
    return lenght;
}
