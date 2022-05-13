// cards.h
// Author: Vedant Shah
// All class declarations go here

#ifndef CARDS_H
#define CARDS_H

#include <iostream>
#include<stdlib.h>
#include <cstring>

using namespace std;

class Cards{
    public:
        Cards();
        ~Cards();

        bool insert(int value);
        bool remove(int value);
        //bool find(int value);
        int getPredecessor(int value) const;
        int getSuccessor(int value) const;
        bool contains(int value) const;
        string intToString(int num) const;
        void print() const;
        bool hasSame(Cards other);
        bool hasSameMod(Cards other);

    private:
        struct Node {
            //char suite;
            int value;
            Node *left, *right, *parent;
            //Node(int v =0) : suite(""), value(""), left(0), right(0), parent(0) {}
            
        };

        Node* root;

        bool insert(int value, Node* n);
        void clear(Node* n);
        void print(Node* n) const;
        void hasSame(Node* n);
        void hasSameMod(Node* n);
        Node* getNodeFor(int value) const;
        Node* getPredecessorNode(int value) const;
        Node* getSuccessorNode(int value) const;

};

#endif