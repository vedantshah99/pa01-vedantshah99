// cards.cpp
// Author: Your name
// Implementation of the classes defined in cards.h
//NEW BRANCH

#include "cards.h"
#include <iostream>
#include <cstring>

using namespace std;

// constructor sets up empty tree
Cards::Cards() {
    root = nullptr;
}

bool disable = false;
// destructor deletes all nodes
Cards::~Cards() {
    if(!disable){
        clear(root);
    }
    disable = false;
}

// recursive helper for destructor
void Cards::clear(Node *n) {
    if (!n){
        return;
    }
    clear(n->left);
    clear(n->right);
    delete n;
}

string Cards::intToString(int num) const{
    int suiteNum = num/100;
    int valNum = num - 100*suiteNum;
    string card = "";

    if(suiteNum == 4){
        card += "c";
    }
    else if(suiteNum == 3){
        card += "d";
    }
    else if(suiteNum == 2){
        card += "s";
    }
    else if(suiteNum == 1){
        card += "h";
    }

    card += " ";

    if(valNum == 13){
        card += "k";
    }
    else if(valNum == 12){
        card += "q";
    }
    else if(valNum == 11){
        card += "j";
    }
    else if(valNum == 1){
        card += "a";
    }
    else{
        card += to_string(valNum);
    }
    return card;
}


void Cards::print() const{
    print(root);
}

void Cards::print(Node* n) const{
    if(!n){
        return;
    }
    print(n->left);
    string temp = intToString(n->value);
    cout << temp << endl;
    print(n->right);
}

// insert value in tree; return false if duplicate
bool Cards::insert(int value) {
    if (!root) {
        root = new Node {value};
        return true;
    }
    else if (contains(value)){
        return false;
    }
    else {
        return insert(value, root);
    }
}

// recursive helper for insert (assumes n is never 0)
bool Cards::insert(int value, Node* n) {
    if (value > n->value){
        if (!n->right){
            n->right = new Node {value};
            n->right->parent = n;
            return true;
        }
        else {
            insert(value, n->right);
        }
    }
    else if (value < n->value){
        if (!n->left){
            n->left = new Node {value};
            n->left->parent = n;
            return true;
        }
        else {
            insert(value, n->left);
        }
    }
    return false;
}


Cards::Node* Cards::getNodeFor(int value) const{
    Node* n = root;
    if(!n){
        return nullptr;
    }
    while(n){
        if(n->value < value){
            n = n->right;
        }
        else if(n->value > value){
            n = n->left;
        }
        else{
            return n;
        }
    }
    return nullptr;
}

// returns true if value is in the tree; false if not
bool Cards::contains(int value) const {
    Node* temp = root;
    if (!temp) {return false;}
    if (temp->value == value){
        return true;
    }
    while (temp){
        if(temp->value == value){
            return true;
        }
        else if (value < temp->value){
            temp = temp->left;
        }
        else if (value > temp->value){
            temp = temp->right;
        }
    }
    return false;
}

bool found = false;
int removedVal;

void Cards::hasSame(Cards other){
    Node* o = other.root;
    found = false;
    //cout << "checkpoint 1" << endl;
    hasSame(o);
    other.remove(removedVal);
    //cout << "checkpoint 10" << endl;
    disable = true;
}

void Cards::hasSame(Node* other) {
    if(other->left){
        hasSame(other->left);
    }
    if(!found && contains(other->value)){
        //cout << "checkpoint 2" << endl;
        string temp = intToString(other->value);
        cout << temp << endl;
        found = true;
        removedVal = other->value;
        remove(other->value);
        return;
    }
    if(!found && other->right){
        hasSame(other->right);
    }
    if(!found && !other->left && !other->right){
        return;
    }
    return;
}




// returns the Node containing the predecessor of the given value
Cards::Node* Cards::getPredecessorNode(int value) const{
    return getNodeFor(getPredecessor(value));
}

// returns the predecessor value of the given value or 0 if there is none
int Cards::getPredecessor(int value) const{
    Node* n = getNodeFor(value);
    if (!n) {return 0;}
    if (n->left){
        n = n->left;
        while(n->right){
            n = n->right;
        }
        return n->value;
    }
    else if (n->parent && (n->parent->value < n->value)){
        return n->parent->value;
    }
    else if (n->parent && root->value < n->value){
        while(n->value >= value){
            n = n->parent;
        }
        return n->value;
    }
    else {return 0;}
}

// returns the Node containing the successor of the given value
Cards::Node* Cards::getSuccessorNode(int value) const{
    Node* n = getNodeFor(value);
    if (!n) {return 0;}
    if (n->right){
        n = n->right;
        while(n->left){
            n = n->left;
        }
        return n;
    }
    else if (n->parent && (n->parent->value > n->value)){
        return n->parent;
    }
    else if (n->parent && root->value > n->value){
        while(n->value <= value){
            n = n->parent;
        }
        return n;
    }
    else {return nullptr;}
}

// returns the successor value of the given value or 0 if there is none
int Cards::getSuccessor(int value) const{
    if (!getSuccessorNode(value)){
        return 0;
    }
    else{
        return getSuccessorNode(value)->value;
    }
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool Cards::remove(int value){
    //if tree is empty
    if (!root) {return false;}
    //find node with the given value
    Node* n = getNodeFor(value);
    if (!n) {return false;}
    //case if n has no children
    if (!n->left && !n->right){
        if (!n->parent){
            delete n;
            root = nullptr;
            return true;
        }
        else{
            if (n->value < n->parent->value){
                n->parent->left = nullptr;
                delete n;
                return true;
            }
            else{
                n->parent->right = nullptr;
                delete n;
                return true;
            }
        }
    }
    //case if n only has a left child
    else if (n->left && !n->right){
        if (!n->parent){
            root = n->left;
            n->left->parent = nullptr;
            delete n;
            return true;
        }
        else{
            if (n->value > n->parent->value){
                n->parent->right = n->left;
                n->left->parent = n->parent;
                delete n;
                return true;
            }
            else{
                n->parent->left = n->left;
                n->left->parent = n->parent;
                delete n;
                return true;
            }
        }
    }
    //case if n only has a right child
    else if (!n->left && n->right){
        if (!n->parent){
            root = n->right;
            n->right->parent = nullptr;
            delete n;
            return true;
        }
        else{
            if (n->value > n->parent->value){
                n->parent->right = n->right;
                n->right->parent = n->parent;
                delete n;
                return true;
            }
            else{
                n->parent->left = n->right;
                n->right->parent = n->parent;
                delete n;
                return true;
            }
        }
    }
    //case if n has two children
    else{
        Node* successor = getSuccessorNode(n->value);
        int num = successor->value;
        remove(num);
        n->value = num;
        return true;
    }
}