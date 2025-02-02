#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    // Files must be put in the correct location
    // Can access files to read and write during C++ program
    // Can read write and append to files
    // Read --> file must previously exist
    // Write/append --> file will be created if it dosen't exist

    // File reading
    // Data type --> ifstream
    // input file stream
    /*
    ifstream infile;
    string filename;

    cout << "Enter a file name: ";
    cin >> filename;

    // File opening
    infile.open(filename);

    // file verification
    while(!(infile.is_open()))
    {
        cout << "Error opening" << endl;
        cout << "Enter a file name: ";
        cin >> filename;

        // File opening
        infile.open(filename);
    }

    cout << endl << "File opened." << endl;
    /*
    //single item/line reading
    //2 methods
    // --> cin
    // --> getline

    string item;
    //cin >> item;
    //infile >> item;

    //cout << "Cin reading: " << item << endl;

    // getline
    // getline(cin, item);

    getline(infile, item);
    cout << "Getline reading: " << item << endl;
    */
    /*
    method 1
    cin
    using eof flag
    eof --> end  of file

    while(!(infile.eof()))
    {
        infile >> item;

        if(!infile.fail()){
            cout << item << endl;
        }
    }
    */

    /*
     * method 2
     * getline
     *

    while(getline(infile, item)){
        cout << item << endl;
    }

    //method 3
    //cin
    //inspured by method 2
    //
    // useful for formatted files
    // where you input mltiple item across datatypes in one sweep

    string name, species;
    int age;

    while( infile >> name >> age >> species){
        cout << "Name: " << name << endl;
        cout << "Age : " << age << "\tSpecies: " << species << endl;
    }
    */

    // File writing
    // data type--> ofstream
    /*
    ofstream outfile;
    string input;

    outfile.open("testing.txt");

    if(!outfile.is_open()){
        cout << "Error creating file. Exiting" << endl;
        return 1;
    }

    // single item writing
    // must maunnally add white space

    outfile << "Hello World" << endl;

    for(int i = 0; i < 10; i++){
        outfile << i << endl;
    }

    cout << "This program inserts text into a .txt file.\nType quit to exit." << endl;
    while(input != "quit"){
        cout << "Please enter the string you wish to insert into the .txt file: ";
        getline(cin, input);
        if(input == "quit"){
            return 1;
        }
        outfile << input << endl;
    }
    */
    // File appending
    // data type--> ofstream
    // Will add to file contents

    ofstream outfile;
    string input;

    outfile.open("testing.txt", ios::app);

    if(!outfile.is_open()){
        cout << "Error creating file. Exiting" << endl;
        return 1;
    }

    // single item writing
    // must maunnally add white space

    outfile << "Hello World" << endl;

    for(int i = 0; i < 10; i++){
        outfile << i << endl;
    }

    /*
    cout << "This program inserts text into a .txt file.\nType quit to exit." << endl;
    while(input != "quit"){
        cout << "Please enter the string you wish to insert into the .txt file: ";
        getline(cin, input);
        if(input == "quit"){
            return 1;
        }
        outfile << input << endl;
    }
    */
    // file closing
    //infile.close();
    outfile.close();

    return 0;
}
















