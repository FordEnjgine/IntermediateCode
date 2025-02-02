#include <string>
#include <cmath>

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

using namespace std;

class Gameboard
{
    private:
        char playerBoard[10][10];
        char computerBoard[10][10];
        char userComputerBoard[10][10];

        int userColumn;
        int shipSize;
        char orientation;
        int row;
        int counter;

    public:
        Gameboard();
        // User/Computer functions
        void printGameBoard();
        bool userShipPlacement(char userRow, int userColumn, int shipLenght, char orientationLD);
        bool playerShipHit();
        void shipLenght(string shipSelect);
        bool userDirectionVal(string userOrientationString);
        void rowToInt(char userRow);
        bool rowValidation(string userRowString);
        bool columnValidation(string userColumn);
        int columnToInt(string userColumn);
        void placement(bool comp);
        bool placementValidation();


        // Computer functions
        void computer();
        int randColumnRow();
        void computerPlacement();
        bool computerValidation();
        void computerShot();

        //Computer/User interactions
        bool hit(bool comp);

        // Setters
        void setUserColumn(int userColumn);
        void setOrientation(char Orientation);
        void setRow(int row);



};

#endif // GAMEBOARD_H
