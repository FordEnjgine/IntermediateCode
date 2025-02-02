/*
Name: Jacob Knoeppel     NetID: jck382
Date: 10/15/24           Due Date: 10/18/24

Description:
This program allows the user to create an array of a desired size
and then enter a coressponding number of animals via function enterAnimals().
It then allows the user to select from a menu:
If the user enters 0, the program exits
If the user enters 1, the program displays the animals in the array with the function displayAniamls().
If the user enters 2, the program allows the user to edit specific animals correlating with their selection using the function editAniamls().
If the user enters 3, the program allows the user to print their animals to a file using animalFile().

*/

#include <iostream>
#include <string>
#include <fstream>
#include "animal.h"

using namespace std;

// given to you:
void displayAnimals(Animal *animals, int size);

// ***************************************
// list your function declarations here!

void enterAnimals(Animal *animals, int size);
void editAnimals(Animal *animals, int size);
void animalFile(Animal *animals, int size);

// ***************************************

int main()
{
    // ***************************************
    // add code here to:
    // create the array and initialize it

    Animal *animals;
    int size;
    cout << "How many animals do you wish to enter? " << endl;
    cout << "Enter the number here: ";
    cin >> size;

    // Intializes the array to user entered size
    animals = new Animal[size];

    // function call to enable user to add their animals to the array
    enterAnimals(animals, size);

    // ***************************************


    // menu handling
    while(1)
    {
        string option;

        cout << endl << "Menu:" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Display animals" << endl;
        cout << "2. Edit animal" << endl;
        cout << "3. Write to file" << endl;
        cout << "Enter your option: ";
        cin >> option;

        cout << endl;

        // exit
        if(option == "0")
        {
            cout << "Good-bye!" << endl;
            break;
        }

        // display
        else if(option == "1")
        {
            displayAnimals(animals, size);
        }

        // edit
        else if(option == "2")
        {
            // Function Call to editAnimals to enable user editing
            editAnimals(animals,size);
        }

        // write
        else if(option == "3")
        {
            // Function Call to animalFile to enable to user to print their animals into a file
            animalFile(animals, size);
        }

        // wrong option
        else
        {
            cout << "That wasn't an option. Please try again." << endl;
        }
    }

    delete[] animals;

    return 0;
}

void displayAnimals(Animal *animals, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << "Animal " << i + 1 << ": " << endl;
        cout << "Name: " << animals[i].getName() << endl;
        cout << "Type: " << animals[i].getType() << endl;
        cout << "Age: " << animals[i].getAge() << endl;
        cout << "Weight: " << animals[i].getWeight() << endl;
        cout << endl;
    }
}

void enterAnimals(Animal *animals, int size)
{
    string name;
    string species;
    int age;
    float weight;

    // For loop enables user to input name, species, age, weight for the number of animals they have selected
    for(int i = 0; i < size; i++)
    {
        cout << "Enter Animal Name (no spaces!): ";
        cin >> name;
        cout << "Enter Animal Species: ";
        cin >> species;
        cout << "Enter Animal age: ";
        cin >> age;
        cout << "Enter Animal weight: ";
        cin >> weight;
        animals[i] = Animal(name, species, age, weight);
        cout << endl;
    }

}

// This allows the user to edit the age and weight of an animal
void editAnimals(Animal *animals, int size)
{
    // Variables to enable selection
    int selection = 0;
    int age;
    float weight;

    while(1)
    {
        if(selection <= size && selection > 0)
        {
            cout << "Enter in new age: ";
            cin >> age;
            cout << "Enter in new weight: ";
            cin >> weight;
            // selection - 1 is required to find the correct index in an array
            animals[selection - 1].setAge(age);
            animals[selection - 1].setWeight(weight);
            break;
        }
        // Error checking
        else if(selection > size || selection < 0)
        {
            cout << "The entry you have made is an invalid position, please try again: ";
            cin >> selection;
        }
        else
        {
            // For loop to print selection list
            for(int i = 0; i < size; i++)
            {
                // i+1 is required as loop starts at 0
                cout << "Aniaml #" << i+1 << ": " << animals[i].getName() << endl;
            }
            cout << "Please select which animal you would like to edit:";
            cin >> selection;
            cout << endl;
        }
    }
}

// This adds the animals information to a file
void animalFile(Animal *animals, int size)
{
    string fileName;
    ofstream outfile;

    cout << "Enter File name (with extension): ";
    cin >> fileName;
    // Opens file
    outfile.open(fileName);

    // for loop adds all information into file
    for(int i = 0; i < size; i++)
    {
        outfile << animals[i].getName() << " " << animals[i].getType() << " " << animals[i].getAge() << " " << animals[i].getWeight() << endl;
    }

    cout << "File Created.\nAnimals saved!" << endl;
}
