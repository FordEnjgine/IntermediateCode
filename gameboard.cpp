#include "gameboard.h"
#include <iostream>

Gameboard::Gameboard()
{
    //Intializes array
    for(int i = 0; i < 10; i++)
    {
        for(int k = 0; k < 10; k++)
        {
            playerBoard[i][k]= ' ';
            computerBoard[i][k] = ' ';
            userComputerBoard[i][k] = '?';
        }
    }

    counter = 0;
    userColumn = 0;
    shipSize = 0;
    orientation = ' ';

    //Randomizes the rand() seed
    srand(time(0));
}

bool Gameboard::hit(bool comp)
{
    if(comp)
    {
        if(playerBoard[row][userColumn] == (char)254u)
        {
            playerBoard[row][userColumn] = '1';
            return true;
        }
        else if(playerBoard[row][userColumn] == '1' || playerBoard[row][userColumn] == '0' )
        {
            return false;
        }
        else
        {
            playerBoard[row][userColumn] = '0';
            return false;
        }
    }
    else
    {
        if(computerBoard[row][userColumn - 1] == (char)254u)
        {
            userComputerBoard[row][userColumn] = '1';
            return true;
        }
        else if(computerBoard[row][userColumn - 1] == '1' || computerBoard[row][userColumn - 1] == '0' )
        {
            return false;
        }
        else
        {
            userComputerBoard[row][userColumn - 1] = '0';
            return false;
        }
    }

    return false;
}

bool Gameboard::rowValidation(string userRowString)
{
    if(userRowString.size() > 1)
    {
        return false;
    }

    char userRow = userRowString[0];

    if(userRow != 'A' && userRow != 'B' && userRow != 'C' && userRow != 'D' && userRow != 'E' && userRow != 'F' && userRow != 'G' && userRow != 'H' && userRow != 'I'  && userRow != 'J')
    {
        return false;
    }
    else
    {
        rowToInt(userRow);
        return true;
    }
}

void Gameboard::rowToInt(char userRow)
{
    switch(userRow)
    {
    case 'A':
        row = 0;
        break;
    case 'B':
        row = 1;
        break;
    case 'C':
        row = 2;
        break;
    case 'D':
        row = 3;
        break;
    case 'E':
        row = 4;
        break;
    case 'F':
        row = 5;
        break;
    case 'G':
        row = 6;
        break;
    case 'H':
        row = 7;
        break;
    case 'I':
        row = 8;
        break;
    case 'J':
        row = 9;
        break;
    }
}

void Gameboard::setRow(int row)
{
    this->row = row;
}

bool Gameboard::columnValidation(string userColumn)
{
    // Getline is in the class because it enables the funtion to work
    getline(cin, userColumn);

    if(userColumn.size() > 2)
    {
        return false;
    }
    else if(userColumn.size() == 1)
    {
        if(!isdigit(userColumn[0]))
        {
            return false;
        }
    }
    else
    {
        if(!isdigit(userColumn[0]))
        {
            return false;
        }
        if(!isdigit(userColumn[1]))
        {
            return false;
        }
    }

    if(columnToInt(userColumn) < 11 && columnToInt(userColumn) > 0)
    {
        // Utilizes the stoi function in columnToInt to set userColumn to the users desired number
        setUserColumn(columnToInt(userColumn));
        return true;
    }
    else
    {
        return false;
    }

}

int Gameboard::columnToInt(string userColumn)
{
    int temp = stoi(userColumn);
        return temp;
}

void Gameboard::shipLenght(string shipSelect)
{
        switch(shipSelect[counter])
        {
        case '1':
            shipSize = 5;
            break;
        case '2':
            shipSize = 4;
            break;
        case '3':
            shipSize = 3;
            break;
        case '4':
            shipSize = 3;
            break;
        case '5':
            shipSize = 2;
            break;
        }
}

bool Gameboard::userDirectionVal(string userOrientationString)
{
    if(userOrientationString.size() > 1)
    {
        return false;
    }

    char userOrientation = userOrientationString[0];

    if(userOrientation != 'L' && userOrientation != 'R' && userOrientation != 'D')
    {
        return false;
    }
    else
    {
        setOrientation(userOrientation);
        return true;
    }
}


bool Gameboard::placementValidation()
{
    bool temp = true;
    switch(orientation)
    {
        case 'D':
            if(row + shipSize > 10)
            {
                return false;
            }
            else
            {
                for(int i = 0; i < shipSize; i++)
                {
                    if(playerBoard[row + i][userColumn - 1] == (char)254u)
                    {
                        temp = false;
                    }
                }
            }

            return temp;

        case 'L':
            if((userColumn - shipSize) < 0)
            {
                return false;
            }
            else
            {
                for(int i = 0; i < shipSize; i++)
                {
                    if(playerBoard[row][userColumn - i - 1] == (char)254u)
                    {
                        temp = false;
                    }
                }
            }

            return temp;

        case 'R':
            if((userColumn + shipSize) > 10)
            {
                return false;
            }
            else
            {
                for(int i = 0; i < shipSize; i++)
                {
                    if(playerBoard[row][userColumn + i - 1] == (char)254u)
                    {
                        temp = false;
                    }
                }
            }

            return temp;
    }

        return false;
}

// User/Computer Ship Placement
void Gameboard::placement(bool comp)
{
    switch(orientation)
    {
    case 'D':
        for(int i = 0; i < shipSize; i++)
        {
            if(comp)
            {
                computerBoard[row + i][userColumn] = (char)254u;
            }
            else
            {
                playerBoard[row + i][userColumn - 1] = (char)254u;
            }
        }
        break;

    case 'L':
        for(int i = 0; i < shipSize; i++)
        {
            if(comp)
            {
                computerBoard[row][userColumn - i] = (char)254u;
            }
            else
            {
                playerBoard[row][userColumn - i - 1] = (char)254u;
            }
        }
        break;

    case 'R':
        for(int i = 0; i < shipSize; i++)
        {
            if(comp)
            {
                computerBoard[row][userColumn + i] = (char)254u;
            }
            else
            {
                playerBoard[row][userColumn + i - 1] = (char)254u;
            }
        }
        break;
    }
    //Increase counter once placement is complete to set correct ship size of next ship
    counter++;
}

void Gameboard::printGameBoard()
{

    // Computer Gameboard

    cout << "\t\t COMPUTER BOARD" << endl;
    cout << endl;

    for(int i = 0; i < 10; i++)
    {
        if (i == 0)
        {
            cout << "  | ";
            for(int o = 0; o < 10; o++)
            {
                cout << o + 1<< " | ";
            }
            cout << endl;
            for(int j = 0; j < 44; j++)
            {
                cout << "-";
            }
        }
    cout << endl;
        for(int k = 0; k < 10; k++)
        {
            if( k == 0)
            {
                cout << char(65+i) <<" | " << userComputerBoard[i][k] << " | ";
            }
            else if(k != 9)
            {
                cout << userComputerBoard[i][k] << " | ";
            }
            else
            {
                cout << " " << userComputerBoard[i][k] << " | ";
            }
        }
        cout << "\n";
    }


    cout << endl;
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 44; j++)
        {
            cout << (char)254u;
        }
        cout << endl;
    }
    cout << endl;


    // Player Board Gameboard

    cout << "\t\t PLAYER BOARD" << endl;
    cout << endl;

    for(int i = 0; i < 10; i++)
    {
        if (i == 0)
        {
            cout << "  | ";
            for(int o = 0; o < 10; o++)
            {
                cout << o + 1<< " | ";
            }
            cout << endl;
            for(int j = 0; j < 44; j++)
            {
                cout << "-";
            }
        }
        cout << endl;
        for(int k = 0; k < 10; k++)
        {
            if( k == 0)
            {
                cout << char(65+i) <<" | " << playerBoard[i][k] << " | ";
            }
            else if(k != 9)
            {
                cout << playerBoard[i][k] << " | ";
            }
            else
            {
                cout << playerBoard[i][k] << " | ";
            }
        }
        cout << "\n";
    }
}

void Gameboard::setOrientation(char userDirection)
{
    this->orientation = userDirection;
}

void Gameboard::setUserColumn(int userColumn)
{
    this->userColumn = userColumn;
}

int Gameboard::randColumnRow()
{
    int temp = rand() % 9;
    return temp;
}

// Uses rand to randomly shoot
void Gameboard::computerShot()
{
    row = rand() % 9;
    userColumn = rand() % 9;
}

void Gameboard::computer()
{
    int temp;
    counter = 0;
    string shipSelect = "12345";
    int row;
    int userColumn;

// For loop to ensure all 5 ships are placed
    for(int i = 0; i < 5; i++)
    {
        row = randColumnRow();
        setRow(row);
        userColumn = randColumnRow();
        setUserColumn(userColumn);
        shipLenght(shipSelect);

        temp = rand() % 3 + 1;

        switch(temp)
        {
        case 1:
            setOrientation('D');
            break;
        case 2:
            setOrientation('L');
            break;
        case 3:
            setOrientation('R');
            break;
        }

        // While loop to ensure valid computer placement
        while(!computerValidation())
        {
            row = randColumnRow();
            setRow(row);
            userColumn = randColumnRow();
            setUserColumn(userColumn);

            temp = rand() % 3 + 1;

            switch(temp)
            {
            case 1:
                setOrientation('D');
                break;
            case 2:
                setOrientation('L');
                break;
            case 3:
                setOrientation('R');
                break;
            }
        }

        placement(true);

    }
}

bool Gameboard::computerValidation()
{
    bool temp = true;
    switch(orientation)
    {
    case 'D':
        if(row + shipSize > 10)
        {
            return false;
        }
        else
        {
            for(int i = 0; i < shipSize; i++)
            {
                if(computerBoard[row + i][userColumn] == (char)254u)
                {
                    temp = false;
                }
            }
        }

        return temp;

    case 'L':
        if((userColumn - shipSize) < 0)
        {
            return false;
        }
        else
        {
            for(int i = 0; i < shipSize; i++)
            {
                if(computerBoard[row][userColumn - i] == (char)254u)
                {
                    temp = false;
                }
            }
        }

        return temp;

    case 'R':
        if((userColumn + shipSize) > 10)
        {
            return false;
        }
        else
        {
            for(int i = 0; i < shipSize; i++)
            {
                if(computerBoard[row][userColumn + i] == (char)254u)
                {
                    temp = false;
                }
            }
        }

        return temp;
    }

    return false;
}
