#ifndef BST_H
#define BST_H
#include <iostream>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

class BST {
public:

    void insert(int key);

    Node* search(int key);

    void display(Node* index);

    Node* getRoot();

private:
    Node* root;
};

#endif // BST_H