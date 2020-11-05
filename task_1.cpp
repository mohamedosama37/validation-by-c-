#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <iterator>
#include <fstream>
using namespace std;

// Function to find the permutations
void findPermutations(vector<string> &modules, int n)
{
    // string to store the modules to be send to csv file//
    string Stored_array = "";
    //id to store the test id//
    unsigned int ID = 0;
    //to open the csv file //
    std::ofstream myfile;
    myfile.open("Possible_Out.csv", std::ofstream::out | std::ofstream::trunc);
    // Sort the given array
    sort(modules.begin(), modules.end());

    // Find all possible permutations
    cout << "Possible permutations are:\n";
    myfile << "Possible permutations are:\n";
    do
    {
        cout << "Test Case ";
        cout << ID << " ";
        Stored_array.append("Test Case ");
        Stored_array.append(to_string(ID));
        // loop to c out the modules to the gui and to be stored at the string to be send to csv//
        for (int i = 0; i < n; i++)
        {
            cout << modules[i] << "  ";
            Stored_array.append(",");
            Stored_array.append(modules[i]);
        }
        //send the string of module to csv file//
        myfile << Stored_array;
        Stored_array = "";
        cout << endl;
        myfile << endl;
        ID++;
        // while to loop again with different order//
    } while (next_permutation(modules.begin(), modules.end()));
    //close the file//
    myfile.close();
}

// Driver code
int main()
{
    //value to save the number of modules the user will enter//
    int numbers;
    string name;
    char c;

    vector<string> modules;

    cout << "This program is used to automate the generation of all possible combination " << endl;
    cout << "This program is generic to run with any number of components" << endl;

    cout << "Enter number of components" << endl;
    cin >> numbers;
    //theprogram will loop until the user enter all the modules and the module string will be stored  at vector module every loop//
    for (int i = 0; i < numbers; i++)
    {
        cout << "Enter the module" << endl;
        cin >> name;
        modules.push_back(name);
    }

    int n = modules.size();
    //calling the function which will give me every possible order for the modules//

    findPermutations(modules, n);

    cout << "kindly enter s to close the program" << endl;
    while (c != 's')
    {
        c = getchar();
    }

    return 0;
}
