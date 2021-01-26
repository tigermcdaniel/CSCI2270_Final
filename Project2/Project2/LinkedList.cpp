#include "LinkedList.h"
#include <iostream>

using namespace std;

/*
* Inserts the key into the LL
*/
void LinkedList::insert(int key) {
    node* insert = new node();
    insert->key = key;

    if (root == NULL) {
        root = insert;
        return;
    }

    node* empty = root;
    while (empty->next != NULL) {
        empty = empty->next;
    }

    empty->next = insert;
}

/*
* Returns a pointer if the key exists within the LL
* else reutrn NULL
*/
node* LinkedList::search(int key) {
    node* index = root;

    while (index != NULL) {
        if (index->key == key) {
            return index;
        }
        index = index->next;
    }
    //key not found 
    return NULL;
}

/*
* Print the contents of the Linked List in columns 10 across
*/
void LinkedList::display() {
    node* index = root;
    int i = 0;

    while (index != NULL) {
        cout << index->key << " -> ";
        if (i % 10 == 0) {
            cout << endl;
        }
        i++;
        index = index->next;
    }
}