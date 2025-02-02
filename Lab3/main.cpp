/*
* Name: Jacob Knoeppel     NetID: jck382
* Date: 09/16/2024
* Description: This program allow the user input a file name.
* It then reads the contents into a vector.
* It then takes the inputs in the vector and writes them into a csv file with properly placed commas
* It then loops and asks the users whether they want to quit or convert another file.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ifstream userFile;
    ofstream csvFile;
    vector<string> fileRead;
    string fileName;
    string fileOutput;
    string exitOption;
    int temp;

    cout << "Please enter the file name you wish to convert (with no extensions): ";
    cin >> fileName;

    // Loops the program untill the user decides to exit
    while(exitOption != "Quit" && exitOption != "quit")
    {
        //Resets exitOption to enable the user to input a new exit option at the end of the program
        exitOption = " ";

        userFile.open(fileName + ".txt");
        // Lets the user reinput the name of the file if they enter a non valid one
        while(!userFile.is_open())
        {
            cout << "The file name you have entered is invalid or the file has been not found, please try again\nPlease enter the file name you wish to convert(with no extensions): ";
            cin >> fileName;

            userFile.open(fileName + ".txt");
        }

        //Let the user know that the file has been opened.
        cout << "File opening" << endl;
        cout << "..." << endl;
        cout << "..." << endl;
        cout << "File opened" << endl;

        //Adds the contents of the file to a vector
        while(!userFile.eof())
        {
            getline(userFile, fileOutput);
            fileRead.push_back(fileOutput);
        }

        //Closes userFile as all content has been read into the vector
        userFile.close();

        // Informs the user that the csv file is being created
        cout << "Creating CSV file\n...\n...\nFile created" << endl;
        csvFile.open(fileName + ".csv");

        // Error checks the opening of the file
        if(!csvFile.is_open())
        {
            cout << "Error creating file. Exiting" << endl;
            return 1;
        }

        // Add the content within the vector to the .csv file with approiate commas when viewed in the text version
        for( int i = 0; i < int(fileRead.size()); i++)
        {
            if(fileRead.at(i) == "-1"){
                csvFile << endl;
                //Temp variable used to ensure correct comma placement
                temp = i;
            }
            // Temp variable applied to ensure correct comma placement
            else if(temp == i - 1)
            {
                csvFile << fileRead.at(i);
            }
            else if(i == 0)
            {
                csvFile << fileRead.at(i) << ",";
            }
            else
            {
                csvFile << "," << fileRead.at(i);
            }
        }

        // Closes the created file
        csvFile.close();

        // Loop to ensure the user inputs a valid entry
        while(exitOption != "Continue" && exitOption != "Quit" && exitOption != "continue" && exitOption != "quit")
        {
        //Asks the user whether they would like to convert more files
        cout << "If you wish to convert anymore files, please enter \"Continue\", else enter \"Quit\" to exit: ";
        cin >> exitOption;

            if(exitOption == "Continue" || exitOption == "continue"){
                cout << "Please enter the file name you wish to convert (with no extensions): ";
                cin >> fileName;
            }
            else if(exitOption != "Continue" && exitOption != "continue" && exitOption != "Quit" && exitOption != "quit"){
                cout << "Not an avaliable option, please try again:" << endl;
                cout << "If you wish to convert anymore files, please enter \"Continue\", else enter \"Quit\" to exit: ";
                cin >> exitOption;
            }
        }
    }
    return 0;
}
