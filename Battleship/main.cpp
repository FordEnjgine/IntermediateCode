#include <iostream>
#include <string>
#include <algorithm>
#include "gameboard.h"

using namespace std;

//Returns a string with the users input
string userInput();
// Validates the users input
bool verifyInput(string userInput);
// Helper function for display
string shipType(char shipNumber);



int main()
{
    Gameboard board;
    string shipSelect;
    string direction;
    string userRow;
    string userColumn;
    string roundRecap;
    int computerCounter = 17;
    int playerCounter = 17;

    bool gameOver = false;

    string temp;

    cout << "Welcome to Battle Ship!" << endl;
    cout << "After you select your first ship, the game board will be displayed." << endl;
    cout << "The default placement of ships is so that the entered row corresponds to the upper most sqaure occupied by the ship." << endl;
    cout << "Keep this in mind when placing your ships." << endl;
    cout << endl;

    shipSelect = userInput();

    cout << "Displaying intial board:" << endl;
    board.printGameBoard();

    for(int i = 0; i < int(shipSelect.length()); i++)
    {
        while(1)
        {
            cout << "Now Placing ship # " << shipSelect[i] << " of type " << shipType(shipSelect[i]) << "!" << endl;
            cout << "Please enter your desired row for the ship: ";
            getline(cin, userRow);

            //Ensures correct comparison by making string uppercase
            transform(userRow.begin(), userRow.end(), userRow.begin(), ::toupper);

            while(!board.rowValidation(userRow))
            {
                cout << "Invalid row! Please try again! " << endl;
                cout << "Make new selection here: ";
                getline(cin, userRow);
                transform(userRow.begin(), userRow.end(), userRow.begin(), ::toupper);
            }

            cout << "Please enter the column in which you wish to place the ship: ";

            while(!board.columnValidation(userColumn))
            {
                cout << "Invalid column! Please try again! " << endl;
                cout << "Make new selection here: ";
            }

            cout << "Would you like the ship to be orientated twoards the left or the right vertically by entering L or R or D: ";
            getline(cin, direction);

            transform(direction.begin(), direction.end(), direction.begin(), ::toupper);

            while(!board.userDirectionVal(direction))
            {
                cout << "Invalid orientation! Please try again! " << endl;
                cout << "Make new selection here: ";
                getline(cin, direction);
                transform(direction.begin(), direction.end(), direction.begin(), ::toupper);
            }

            board.shipLenght(shipSelect);

            if(board.placementValidation())
            {
                board.placement(false);
                break;
            }
            else
            {
                cout << "Not a valid board placement, please try again! " << endl;
            }
        }

        board.printGameBoard();
    }

    board.computer();

    while(!gameOver)
    {
        roundRecap = "";

        /*
        cout << "Please enter your desired row to target: ";
        getline(cin, userRow);

        //Ensures correct comparsions by making the string uppercase
        transform(userRow.begin(), userRow.end(), userRow.begin(), ::toupper);

        while(!board.rowValidation(userRow))
        {
            cout << "Invalid row! Please try again! " << endl;
            cout << "Make new selection here: ";
            getline(cin, userRow);
            transform(userRow.begin(), userRow.end(), userRow.begin(), ::toupper);
        }

        cout << "Please enter the column that you wish to target: ";

        while(!board.columnValidation(userColumn))
        {
            cout << "Invalid column! Please try again! " << endl;
            cout << "Make new selection here: ";
        }

        if(board.hit(false))
        {
            roundRecap =  roundRecap + "You hit the opponents ship!\n";
            playerCounter--;
        }
        else
        {
            roundRecap =  roundRecap + "You missed!\n";
        }

        cout << "Opponents turn! " << endl;
        board.computerShot();

        if(board.hit(true))
        {
            roundRecap =  roundRecap + "Opponent hit your ship!\n";
            computerCounter--;
        }
        else
        {
            roundRecap =  roundRecap + "Oppenent Missed\n";
        }

        */

    // Loop for testing the function without having to complete entire game - uncomment to test

        for(int i = 0; i <= 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                board.setRow(i);
                board.setUserColumn(j);

                if(board.hit(false))
                    {
                        playerCounter--;
                        cout << "Player Counter reduced" << endl;
                        cout << "Value: " << playerCounter << endl;
                    }

                board.computerShot();
                    cout << "Computer Shot" << endl;

                if(board.hit(true))
                {
                    computerCounter--;
                    cout << "Computer counter reduced" << endl;
                    cout << "Value: " << computerCounter << endl;
                }

                if(playerCounter < 0 || computerCounter < 0)
                {
                    break;
                }
            }
            board.printGameBoard();

            if(playerCounter < 0 || computerCounter < 0)
            {
                break;
            }
        }


        if(playerCounter <= 0 || computerCounter <= 0)
        {
            gameOver = true;
            board.printGameBoard();
            cout << roundRecap << endl;
        }
        else
        {
            board.printGameBoard();
            cout << roundRecap << endl;
            cout << "Your turn again!" << endl;
        }
    }

    if(computerCounter == 0)
    {
        cout << "You lose!" << endl;
    }
    else
    {
        cout << "You WIN!" << endl;
    }

    return 0;
}

string userInput()
{
    string shipSelect = " ";

        cout << "Please select the order in which you would to place your ships (seperated by spaces): " << endl;
        cout << "1. Carrier (5 spaces) " << endl;
        cout << "2. Battleship (4 spaces) " << endl;
        cout << "3. Crusier (3 spaces) " << endl;
        cout << "4. Submarine (3 spaces) " << endl;
        cout << "5. Patrol (2 spaces) " << endl;
        cout << "Make selection here: ";
        getline(cin, shipSelect);


        while(!verifyInput(shipSelect))
        {
            cout << "Invalid Input, please try again!" << endl;
            cout << "Enter new input here: ";
            getline(cin, shipSelect);
        }

        return shipSelect;
}

bool verifyInput(string shipSelect)
{
    bool duplicate = false;

    if(shipSelect.size() != 5)
    {
        return false;
    }

    for(int i = 0; i < int(shipSelect.size()) - 1; i++)
    {
        if(shipSelect[i] >= 54)
        {
            return false;
        }
    }


    for(int i = 0; i < int(shipSelect.size()) - 1; i++)
    {
        char temp = shipSelect[i];
        duplicate = false;

        if(temp == shipSelect[i+1])
            duplicate = true;

        if(duplicate == true)
            return false;
    }

    for(int i = 0; i < int(shipSelect.size()); i++)
    {
        if(!isdigit(shipSelect[i]))
            return false;
    }

    return true;
}

string shipType(char shipNumber)
{
    switch(shipNumber)
    {
        case '1':
            return "Carrier (5 Spaces)";
        case '2':
            return "Battleship (4 spaces)";
        case '3':
            return "Crusier (3 spaces)";
        case '4':
            return "Submarine (3 spaces)";
        case '5':
            return "Patrol (2 spaces)";
    }

        return " ";
}
