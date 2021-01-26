#include "hash.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char*argv[])
{
    int arr[100];
    for(int i = 0; i < 100; i++){
        arr[i] = rand() % 100;
    }

    HashTable hash(100);

    for(int i = 0; i < 100; i++){
        if(hash.insertItem(arr[i])){
            //cout << "Inserted: " << arr[i] << endl;
        }else {
            cout << "Did not insert: " << arr[i] << endl;
        }
    }
    cout << hash.getNumOfCollision() << endl;
}