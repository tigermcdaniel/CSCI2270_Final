#include "hash.h"
#include <string>
#include <iostream>

using namespace std;
//table size: m = 40,009
//hash function: h(x) = x % m;

HashTable::HashTable(int bsize) {
    tableSize = 40009;

    //initialize the array of nodes and point the head to the start of them 
    NODE arr[40009];
    head = &arr[0];
    numOfcolision = 0;
}

/*
* resolution 1 will be linear addressing
* ie look for next available position with the next highest index
*/
bool HashTable::resolution1(NODE* insert, NODE* current, int hashIndex) {
    //resolution 1: linear probing 
    NODE* start = current;
    NODE* index = current + 1;
    hashIndex ++;
    
    //while we haven't gone in a full circle
    while (index != start) 
    {
        if (hashIndex >= 40000) 
        {
            index = head;
            hashIndex = 0;
            cout << "reset search to head" << endl;
            return false;
        }
        else 
        {
            if (index != NULL && index->initialized == false) 
            {
                *index = *insert;
                index->initialized = true;
                return true;
            }
        }

        index = index + 1;
        hashIndex ++;
    }
    return false;
}

/*
* resolution 2 will recursively perform quadratic probing to try and find a spot
*/
bool HashTable::resolution2(NODE* insert, int startingIndex, int index) {
    if (startingIndex == index) return false;

    int newHash = startingIndex + (index * index);
    if (newHash >= 40000) {
        newHash = newHash - 40000;
    }
    NODE* current = head + newHash;
    if (current == NULL) {
        *current = *head;
        index = 0;
    }
    if (current->initialized == false) {
        *current = *insert;
        current->initialized = true;
        return true;
    }
    else {
        resolution2(insert, startingIndex, index + 1);
    }
}

/*
* resolution 3 will perform linked list chainging to add the element
*/
bool HashTable::resolution3(NODE* insert, NODE* current) {
    NODE* index = current;
    while (index->next != NULL) {
        index = index->next;
    }
    index->next = insert;
    return true;
}

bool HashTable::insertItem(int key) {
    NODE* insert = new NODE();
    insert->key = key;

    //index is the position is will ideally be stored under 
    int index = key % tableSize;
    NODE* current = (head + index);
    bool added = false;

    if (current == NULL) {
        current = head;
    }
    if (current->initialized == false) {
        *current = *insert;
        current->initialized = true;
        added = true;
        //cout << "inserted: " << current->key << endl;
    }
    else {
        //we have a collision
        //cout << "We have a collision. " << endl;
        numOfcolision++;

        cout << "try resoltion 1" << endl;
        added = resolution1(insert, current, index);
        if(added) cout << "res1 worked" << endl;

        if (!added){
            cout << "try resolution 2" << endl;
            added = resolution2(insert, index, 0);
            if(added) cout << "res2 worked" << endl;
        }

        if (!added){
            cout << "try resolution 3" << endl;
            added = resolution3(insert, current);
            if(added) cout << "res3 worked" << endl;
        }
    }
    return added;
}

int HashTable::getNumOfCollision() {
    return numOfcolision;
}

NODE* HashTable::searchItem(int key){
    /*
    for(int i = 0; i < tableSize; i++)
    {
        NODE* current = (head + i);
        if(current != NULL && current->initialized == true)
        {
            if(current->key == key) return current;

            if(current->next != NULL && current->next->initialized == true)
            {
                NODE* index = current->next;
                while(index != NULL && index->initialized == true)
                {
                    if(index->key == key) return index;
                    index = index->next;
                }
            }
        }
    }
    */
    return NULL;
}