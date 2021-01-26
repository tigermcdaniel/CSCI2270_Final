#include "hash.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

//Testing function for USPS Performance Tests
int main(int argc, char* argv[]) {

    string file_name = "dataSetA.csv";
    ifstream dataFile;
    //cout << "opening file" << endl;
    dataFile.open(file_name);

    if (!dataFile.is_open())
    {
        cerr << "Could not open " << file_name << " for reading!" << endl;
        return 2;
    }

    //cout << "file opened" << endl;
    string line;
    HashTable HT(40009);

    //extract every line from the data set and piece out the number sets 
    while (std::getline(dataFile, line))
    {
        string datum;
        stringstream dataStream(line);

        while (getline(dataStream, datum, ',')) {
            //now you have the data as strings within datum to fill the data structures 
            int data = std::stoi(datum);
            if (HT.insertItem(data)) {
                cout << "add successful" << endl;
            }
            else {
                cout << "add unsuccessful" << endl;
            }
        }
    }

    //HT.display();
    dataFile.close();

}