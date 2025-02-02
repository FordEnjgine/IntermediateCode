#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // Arrays
    //
    // Called arrays in C++, not list (python)
    // Ordered strcuture that holds mutiple items
    // Built into C++ - no external library required
    // Can only hold one data type
    // Must have a set (static) predetermined size
    // (variable type) name[(size)]
    //
    // have indices
    // indexing starts at 0
    //
    // three methods of creation
    //
    // Method 1
    // Empty array --> No preset values
    // Preset size



    int empty[10];

    // Method 2
    // Some preset values
    // Preset size

    int somePreset[10] = {1,2,3,4,5};

    // Method 3
    // All preset values
    // Size is determined by number of values

    int preset[] = {0,1,2,3,4};

    // Size
    // No built in size function
    // keep track of the size as a programmer
    // or:

    int size = sizeof(preset)/sizeof(int);
    // int size = sizeof(preset)/sizeof(preset[0]);

    // sizeof() return size in bytes
    // by dividing by the data type of the array it gives you the size of the array (40 bytes (size of array)/ 4 bytes (size of an int)
    // KEEP TRACK OF SIZE YOURSELF

    //edit example
    preset[0] = 6;

    cout << preset << endl;

    // output loop

    for(int i = 0; i < 5; i++)
    {
        cout << preset[i] << endl;

    }
    cout << endl;

    // character arrays
    //
    // specfically for characters
    // Used over conventional array

    char dog1[] = {'M','a','g','g','i','e'};
    //Character specfic array
    char dog2[] = "Apollo Neal";

    cout << dog1 << endl;
    cout << dog2 << endl;

    cout << endl;

    //Vectors
    //
    // Dynamic array --> can hold a chaning number of items
    // Cannot hold diffrenet data types
    // Requires library: #include <vector> --> not built into C++
    // Works with namespace std
    // Vectors do not have indices
    //
    // vector<data type> variableName
    //
    // Vector Functions
    //
    // vector.function();
    //
    // push_back(item) --> adds to the current end of your vector, item being passed in should match vector type
    // pop_back() --> removes last item from the vector
    // size() --> returns an integer value corresponding to the size of the vector
    // insert(position, item) --> adds an item to the vector before the given position. the item in position will be moved
    // begin() --> returns position of first item as

    //Code examples
    // 2 methods of creation

    // Method 1
    // Empty

    vector<int> numbers;

    // Method 2
    // Preset values
    vector<string> names{"Maggie", "Apollo"};

    //output a vector
    //loop output

    for(int i = 0; i < names.size();i++)
    {
        // "Simulated" indices
        cout << names[i] << endl;

        // Vector specific way
        cout << names.at(i) << endl;

    }

    cout << endl;

    //adding
    names.push_back("Sandy");
    names.push_back("Callie");

    for(int i = 0; i < names.size();i++)
    {
        cout << names[i] << endl;
    }

    cout << endl;

    //inserts
    names.insert(names.begin()+0, "Nubs");
    names.insert(names.begin()+2, "Phil");

    for(int i = 0; i < names.size();i++)
    {
        cout << names[i] << endl;
    }

    cout << endl;

    //erase
    names.erase(names.begin()+3); //Deletes "Apollo"

    for(int i = 0; i < names.size();i++)
    {
        cout << names[i] << endl;
    }

    cout << endl;


    return 0;
}
