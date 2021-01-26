#pragma once
#ifndef HASH_HPP
#define HASH_HPP

#include <string>


using namespace std;

struct NODE
{
    int key;
    struct NODE* next;
    bool initialized = false;
};

class HashTable
{
    // No. of buckets (linked lists)
    int tableSize;

    // Pointer to an array containing buckets
    NODE* head;

    //store num of collisions 
    int numOfcolision = 0;

    NODE* createNode(int key, NODE* next);

public:

    // Constructor
    HashTable(int bsize);

    // inserts a key into hash table
    bool insertItem(int key);

    //linear probing 
    bool resolution1(NODE* insert, NODE* currentPos, int hashIndex);

    //quadratic probing 
    bool resolution2(NODE* insert, int startingIndex, int index);

    //chaining with linked lists 
    bool resolution3(NODE* insert, NODE* current);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    //print the current table sores 
    void printTable();

    //return the num of collisions 
    int getNumOfCollision();

    //return pointer to said node containing key 
    NODE* searchItem(int key);
};

#endif
