#include "BST.cpp"
#include "LinkedList.cpp"
#include "hash.cpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <math.h>

using namespace std::chrono;

int testDataA[40000];
int insert_LL_A[400];
int insert_BST_A[400];
int insert_Hash_A[400];
int search_LL_A[400];
int search_BST_A[400];
int search_Hash_A[400];


int testDataB[40000];
int insert_LL_B[400];
int search_LL_B[400];
int insert_BST_B[400];
int insert_Hash_B[400];
int search_BST_B[400];
int search_Hash_B[400];

LinkedList DataSetA_LL;
HashTable DataSetA_Hash(40009);
BST DataSetA_BST;

LinkedList DataSetB_LL;
HashTable DataSetB_Hash(40009);
BST DataSetB_BST;

void TestLL(bool A){
    auto start = high_resolution_clock::now();
    for(int index = 0; index < 40000; index++){
        int data;
        //Linked List Test
        if(A){
            data = testDataA[index];
            DataSetA_LL.insert(data);
        }else {
            data = testDataB[index];
            DataSetB_LL.insert(data);
        }

        /* if we just added 100 items...
        *  1. log the time elapsed/100 as the average insert time 
        *  2. generate 100 psydo rand nums from the dataSet and search them 
        *  3. log the time elapsed / 100 as average seach time 
        * */
        if(index % 100 == 0 && index != 0)
        {
            //get the time elapsed for the insertion and record 
            auto stop = high_resolution_clock::now(); 
            auto duration = duration_cast<microseconds>(stop - start);
            int timeElapsed = 0;
            if(duration.count()!=0)
            timeElapsed = duration.count()/100;

            if(A){
                insert_LL_A[index/100 - 1] = timeElapsed;
            }else {
                insert_LL_B[index/100 - 1] = timeElapsed;
            }

            //get the time elapsed for the search and record 
            auto startSearch = high_resolution_clock::now();
            int searchNums[100];
            for(int i = 0; i < 100; i++){ //here [0, (index-1)] are all filled with data
                if(A){
                    int TDA = rand() % index;
                    searchNums[i] = testDataA[TDA];
                    DataSetA_LL.search(searchNums[i]);
                }else {
                    searchNums[i] = testDataB[rand() % index];
                    DataSetB_LL.search(searchNums[i]);
                }
            }
            auto stopSearch = high_resolution_clock::now();
            auto searchDuration = duration_cast<microseconds>(stopSearch - startSearch);
            if(duration.count()!=0)
            timeElapsed = searchDuration.count()/100;
            if(A){
                search_LL_A[index/100 - 1] = timeElapsed;
                //cout << search_LL_A[index/100 - 1] << endl;
            }else {
                search_LL_B[index/100 - 1] = timeElapsed;
            }
        }
    }
}

void TestBST(bool A){
    auto start = high_resolution_clock::now();
    for(int index = 0; index < 40000; index++){
        int data;
        //Test Data for BST
        if(A){
            data = testDataA[index];
            DataSetA_BST.insert(data);
        }else {
            data = testDataB[index];
            DataSetB_BST.insert(data);
        }

        /* if we just added 100 items...
        *  1. log the time elapsed/100 as the average insert time 
        *  2. generate 100 psydo rand nums from the dataSet and search them 
        *  3. log the time elapsed / 100 as average seach time 
        * */
        if(index % 100 == 0 && index != 0)
        {
            //ge the time elapsed for the insertion and record 
            auto stop = high_resolution_clock::now(); 
            auto duration = duration_cast<microseconds>(stop - start);
            int timeElapsed;
            if(duration.count()!=0)
            timeElapsed = duration.count()/100;
            if(A){
                insert_BST_A[index/100 - 1] = timeElapsed;
            }else {
                insert_BST_B[index/100 - 1] = timeElapsed;
            }

            //get the time elapsed for the search and record 
            auto startSearch = high_resolution_clock::now();
            int searchNums[100];
            for(int i = 0; i < 100; i++){ //here [0, (index-1)] are all filled with data
                if(A){
                    searchNums[i] = testDataA[rand() % index];
                    DataSetA_BST.search(searchNums[i]);
                }else {
                    searchNums[i] = testDataB[rand() % index];
                    DataSetB_BST.search(searchNums[i]);
                }
            }
            auto stopSearch = high_resolution_clock::now();
            auto searchDuration = duration_cast<microseconds>(stopSearch - startSearch);
            timeElapsed = searchDuration.count()/100;
            if(A){
                search_BST_A[index/100 - 1] = timeElapsed;
            }else {
                search_BST_B[index/100 - 1] = timeElapsed;
            }
        }
    }
}

void TestHash(bool A){
    auto start = high_resolution_clock::now();
    for(int index = 0; index < 40000; index++){
        int data;
        //Test for Hash 
        if(A){
            data = testDataA[index];
            DataSetA_Hash.insertItem(data);
        }else {
            data = testDataB[index];
            DataSetB_Hash.insertItem(data);
        }

        /* if we just added 100 items...
        *  1. log the time elapsed/100 as the average insert time 
        *  2. generate 100 psydo rand nums from the dataSet and search them 
        *  3. log the time elapsed / 100 as average seach time 
        * */
        if(index % 100 == 0 && index != 0)
        {
            //ge the time elapsed for the insertion and record 
            auto stop = high_resolution_clock::now(); 
            auto duration = duration_cast<microseconds>(stop - start);
            int timeElapsed;
            if(duration.count()!=0)
            timeElapsed = duration.count()/100;
            if(A){
                insert_Hash_A[index/100 - 1] = timeElapsed;
            }else {
                insert_Hash_B[index/100 - 1] = timeElapsed;
            }

            //get the time elapsed for the search and record 
            auto startSearch = high_resolution_clock::now();
            int searchNums[100];
            for(int i = 0; i < 100; i++){ //here [0, (index-1)] are all filled with data
                if(A){
                    searchNums[i] = testDataA[rand() % index];
                    DataSetA_Hash.searchItem(searchNums[i]);
                }else {
                    searchNums[i] = testDataB[rand() % index];
                    DataSetB_Hash.searchItem(searchNums[i]);
                }
            }
            auto stopSearch = high_resolution_clock::now();
            auto searchDuration = duration_cast<microseconds>(stopSearch - startSearch);
            if(duration.count()!=0)
            timeElapsed = duration.count()/100;
            if(A){
                search_Hash_A[index/100 - 1] = timeElapsed;
            }else {
                search_Hash_B[index/100 - 1] = timeElapsed;
            }
        }
    }
}
/*
* read in the file file_name depending on if it is dataset A or not 
*/
void readFile(string file_name, bool A){
    ifstream dataFile;
    dataFile.open(file_name);

    if (!dataFile.is_open())
	{
		cerr << "Could not open " << file_name << " for reading!" << endl;
	}

    string line;
    int i = 0;
    //read in all data from the file 
    while (std::getline(dataFile, line))
	{
        string datum;
		stringstream dataStream(line);

        while(getline(dataStream, datum, ','))
        {
            //now you have the data as strings within datum to fill the data structures 
            int data = std::stoi(datum);
            if(A){
                testDataA[i] = data;
            }else {
                testDataB[i] = data;
            }
            i++;
        }
    }
    dataFile.close();
}

void writeToFile(){
    ofstream file1;
    file1.open ("insertsearchperformancelinkedlistdataSetA.csv");

    file1 << "Linked List Data for Set A" << endl;
    file1 << endl;
    file1 << "Insertion Performance: " << endl;

    for(int i = 0; i < 399; i++){
        file1 << insert_LL_A[i] << endl;
    }

    file1 << "\nSearch Performance: ";
    for(int i = 0; i < 399; i++){
        file1 << "\n" << search_LL_A[i];
    }
    file1.close();

    ofstream file2;
    file2.open("insertsearchperformancelinkedlistdataSetB.csv");

    file2 << "Linked List Data for Set B" << endl;
    file2 << endl;
    file2 << "Insertion Performance: " << endl;
    for(int i = 0; i < 399; i++){
        file2 << insert_LL_B[i] << endl;
    }
    file2 << "\nSearch Performance: ";

    for(int i = 0; i < 399; i++){
        file2 << "\n" << search_LL_B[i];
    }
    file2.close();

    ofstream file3;
    file3.open("insertsearchperformancehashtabledataSetA.csv");

    file3 << "Hash Table Data for Set A\n" << endl;
    file3 << "Insertion Performance: " << endl;
    for(int i = 0; i < 399; i++){
        file3 << insert_Hash_A[i] << endl;
    }

    file3 << "\nSearch Performance: ";
    for(int i = 0; i < 399; i++){
        file3 << "\n" << search_Hash_A[i];
    }
    file3.close();

    ofstream file4;
    file4.open("insertsearchperformancehashtabledataSetB.csv");
    file4 << "Hash Table Data for Set B\n" << endl;
    file4 << "Insertion Performance: " << endl;
    for(int i = 0; i < 399; i++){
        file4 << insert_Hash_B[i] << endl;
    }

    file4 << "\nSearch Performance: ";
    for(int i = 0; i < 399; i++){
        file4 << "\n" << search_Hash_B[i];
    }
    file4.close();

    ofstream file5;
    file5.open("insertsearchperformancebstdataSetA.csv");
    file5 << "BST Data for Set A\n" << endl;
    file5 << "Insertion Performance: " << endl;
    for(int i = 0; i < 399; i++){
        file5 << insert_BST_A[i] << endl;
    }

    file5 << "\nSearch Performance: ";
    for(int i = 0; i < 399; i++){
        file5 << "\n" << search_BST_A[i];
    }
    file5.close();

    ofstream file6;
    file6.open("insertsearchperformancebstdataSetB.csv");
    file6 << "BST Data for Set B\n" << endl;
    file6 << "Insertion Performance: " << endl;
    for(int i = 0; i < 399; i++){
        file6 << insert_BST_B[i] << endl;
    }

    file6 << "\nSearch Performance: ";
    for(int i = 0; i < 399; i++){
        file6 << "\n" << search_BST_B[i];
    }
    file6.close();
}

/*
* Testing function for USPS Performance Tests
* Time is measured in micorseconds 
*/
int main(int argc, char *argv[]){

    //Step 1: read in both files 
    readFile("dataSetA.csv", true);
    readFile("dataSetB.csv", false);

    //Step 2: Perform the Test for each Data Structure and Each Set
    TestLL(true);
    TestLL(false);
    TestBST(true);
    TestBST(false);
    TestHash(true);
    TestHash(false);

    //Step 3: write the performance data to a file 
    writeToFile();
}