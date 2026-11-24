#include <iostream>
#include <string>
#include <filesystem>
using namespace std;

int main()
{
    string directoryPath;
    bool validPath = false;
    int fileCounter = 0;

    cout << "LOCAL SEARCH" << endl;
    cout << "--------------------------\n";

    while (validPath == false)
    {
        cout << "Enter directory path: \n";
        getline(cin,directoryPath);

        if (filesystem::is_directory(directoryPath))
        {
            cout << "Directory found! \n\n";
            validPath = true;
        }
        else
        {
            cout << "\nInvalid directory! \n" << "Try again! \n\n";
        }
    }

    for (const auto & entry : filesystem::directory_iterator(directoryPath))
    {
        if (entry.is_regular_file() && entry.path().extension() == ".txt")
        {
            fileCounter++;
            cout << fileCounter << ") " << entry.path().filename() << endl;

        }
    }
    cout << "\nNumber of text file in the directory: " << fileCounter;


    return 0;
}