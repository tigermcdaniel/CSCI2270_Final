#include "hash.hpp"
#include <string>
#include <iostream>

using namespace std;
//table size: m = 40,009
//hash function: h(x) = x % m;

HashTable::HashTable(int bsize) {
    tableSize = bsize;

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
    hashIndex++;
    //while we haven't gone in a full circle
    while (index != start) {
        if (hashIndex > 40008) {
            index = 0;
            index = head;
        }
        else {
            if (index->initialized == false) {
                index = insert;
                index->initialized = true;
                return true;
            }
        }
    }
    return false;
}

bool HashTable::resolution2(NODE* insert, int startingIndex, int index) {
    if (startingIndex == index) return false;

    int newHash = startingIndex + index ^ 2;
    if (newHash > 40008) {
        newHash = newHash - 40008;
    }
    NODE* current = head + newHash;
    if (current->initialized == false) {
        current = insert;
        current->initialized = true;
        return true;
    }
    else {
        resolution2(insert, startingIndex, index + 1);
    }
}

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

    if (current->initialized == false) {
        current = insert;
        current->initialized = true;
        added = true;
    }
    else {
        //we have a collision
        numOfcolision++;

        added = resolution1(insert, current, index);

        if (!added)
            added = resolution2(insert, index, 0);

        if (!added)
            added = resolution3(insert, current);
    }
    return added;
}

int HashTable::getNumOfCollision() {
    return numOfcolision;
}

NODE* HashTable::searchItem(int key){
    for(int i = 0; i < tableSize; i++)
    {
        if((head+i)->initialized == true){
            if((head+i)->key == key) return (head+1);
        }
    }
    return NULL;
}