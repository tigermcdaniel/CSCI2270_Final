#ifndef LINKEDLIST_H
#define LINKEDLIST_H

using namespace std;

struct node{
    int key;
    node* next;
};

class LinkedList{
    public :
        void insert(int key);    
        node* search(int key);
        void display();

    private :
        node* root;
        node* tail;
};

#endif // LINKEDLIST_H