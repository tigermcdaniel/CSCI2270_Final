#include "BST.hpp"
#include <string>
#include <iostream>

using namespace std;

void BST::insert(int key){
    
    bool inserted = false;
    Node* index = root;
    Node* i = new Node();
    i->key = key;
    
    if(index == NULL)
    {
        root = new Node();
        root->key = key;
        inserted = true;
    }
    while(!inserted)
    {
        if(index->key <= key){
            //go right 
            if(index->right == NULL){
                index->right = i;
                inserted = true;
            }else {
                index = index->right;
            }
            //cout << "going right" << endl;
        }else if(index->key > key){
            //go left 
            if(index->left == NULL){
                index->left = i;
                inserted = true;
            }else {
                index = index->left;
            }
            //cout << "going left" << endl;
        }
    }
}

Node* BST::search(int key){
    bool found = false;
    Node* index = root;

    while(index != NULL && !found)
    {
        if(index->key == key){
            found = true;
            return index;
        }else if(index->key > key){
            //go left 
            index = index->left;
        }else {
            //go right 
            index = index->right;
        }
    }
    cout << "key not found" << endl;
    return NULL;
}

/*
* recusively display the BST from left to right(smallest to largest)
*/
void BST::display(Node* index){
    if(index == NULL)return;
    display(index->left);
    cout << index->key << " -> ";
    display(index->right);
}

Node* BST::getRoot(){
    if(root != NULL){
        return root;
    }
    return NULL;
}