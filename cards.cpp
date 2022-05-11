// cards.cpp
// Author: Your name
// Implementation of the classes defined in cards.h
//NEW BRANCH



#include "cards.h"
#include <iostream>
#include <cstring>

using namespace std;

Cards::Cards(){
    root = nullptr;
}

Cards::~Cards(){
    clear(root);
}

//Insert
bool Cards::insert(string newSuite, string newVal){
    if(root == nullptr){
        Node* temp;
        cout << "checkpoint 1" << endl;
        for(auto x : newSuite){
            temp->suite += x;
        }
        cout << "checkpoint 2"<< endl;
        for(auto x : newVal){
            temp->value += x;
        }

        root = temp;
        return true;
        cout << "checkpoint 4"<< endl;
    }
    else{
        //insert(newSuite, newVal, root);
        return true;
    }
}

//Recursive Insert
bool Cards::insert(string newSuite, string newVal, Node* n){
    Node* temp;
    temp->suite = newSuite;
    temp->value = newVal;
    if(n > temp){
        if(n->left == nullptr){
            n->left = temp;
            temp->parent = n;
            return true;
        }
        else{
            insert(newSuite, newVal, n->left);
        }
    }
    else if(temp > n){
        if(n->right == nullptr){
            n->right = temp;
            temp->parent = n;
            return true;
        }
        else{
            insert(newSuite, newVal, n->right);
        }
    }
    else{
        return false;
    }
    return false;
}

//Find
Cards::Node* Cards::getNodeFor(string suite, string value) const{
    if(!root){
        return nullptr;
    }
    Node* n = root;
    Node* temp;
    temp->suite = suite;
    temp->value = value;

    while(n){
        if(n == temp){
            return n;
        }
        else if(n < temp){
            n = n->right;
        }
        else if(n > temp){
            n = n->left;
        }
    }
    return nullptr;
}

void Cards::clear(Node *n) {
    if (!n){
        return;
    }
    clear(n->left);
    clear(n->right);
    delete n;
}

//find
/*
bool Cards::find(int value){
    if(!root){
        return false;
    }
    Node* temp = getNodeFor(value);
    if(temp){
        return true;
    }
    else{
        return false;
    }
}
*/

//Remove
bool Cards::remove(string suite, string value){
    if(!root){
        return false;
    }
    Node* n = getNodeFor(suite, value);
    if(!n){
        return false;
    }
    if(!n->left && !n->right){
        if(n->parent && n == n->parent->right){
            n->parent->right = nullptr;
        }
        else if(n->parent && n == n->parent->left){
            n->parent->left = nullptr;
        }
        else if(!n->parent){
            root = nullptr;
        }
        delete n;
        return true;
    }
    else if(n->left && n->right){
        Node* successor = getSuccessorNode(n->suite, n->value);
        string tempSuite = successor->suite;
        string tempVal = successor->value;

        remove(successor->suite, successor->value);
        n->suite = tempSuite;
        n->value = tempVal;
        return true;
    }
    else if(n->left){
        if(n->parent && n == n->parent->left){
            n->parent->left = n->left;
            n->left->parent = n->parent;
        }
        else if(n->parent && n == n->parent->right){
            n->parent->right = n->right;
            n->right->parent = n->parent;
        }
        else if(!n->parent){
            n->left->parent = nullptr;
            root = n->left;
        }
        delete n;
        return true;
    }
    else if(n->right)
    {
        if(n->parent && n == n->parent->left){
            n->parent->left = n->left;
            n->left->parent = n->parent;
        }
        else if(n->parent && n == n->parent->right){
            n->parent->right = n->right;
            n->right->parent = n->parent;
        }
        else if(!n->parent){
            n->right->parent = nullptr;
            root = n->right;
        }
        delete n;
        return true;
    }
    return true;
}


//Predecessor Private
Cards::Node* Cards::getPredecessorNode(string suite, string value) const{
    Node* temp = getNodeFor(suite, value);
    if(!temp){
        return nullptr;
    }
    if(!temp->left){
        if(temp == temp->parent->right){
            return temp->parent;
        }
        else{
            return nullptr;
        }
    }
    else{
        temp = temp->left;
        while(temp->right){
            temp = temp->right;
        }
    }
    return temp;
}

//Successor
Cards::Node* Cards::getSuccessorNode(string suite, string value) const{
    Node* temp = getNodeFor(suite, value);
    if(!temp){
        return nullptr;
    }
    if(!temp->right){
        if(temp == temp->parent->left){
            return temp->parent;
        }
        else{
            return nullptr;
        }
    }
    else{
        temp = temp->right;
        while(temp->left){
            temp = temp->left;
        }
    }
    return temp;
}