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

        bool insert(char newSuite, char newVal);
        void print() const;
        bool remove(char suite, char value);
        //bool find(int value);
        int getPredecessor(char suite, char value) const;
        int getSuccessor(char suite, char value) const;

    private:
        struct Node {
            //char suite;
            char suite;
            char value;
            Node *left, *right, *parent;
            //Node(int v =0) : suite(''), value(''), left(0), right(0), parent(0) {}

            bool operator==(const Node& card2){
                if(suite == card2.suite && value == card2.value){
                    return true;
                }
                else{
                    return false;
                }
            }

            
            bool operator>(const Node& card2){
                //same suite
                if(suite == card2.suite){
                    if(value == card2.value){
                        return false;
                    }
                    else if(value == 'k'){
                        return true;
                    }
                    else if(card2.value == 'k'){
                        return false;
                    }
                    else if(value == 'q'){
                        return true;
                    }
                    else if(card2.value == 'q'){
                        return false;
                    }
                    else if(value == 'j'){
                        return true;
                    }
                    else if(card2.value == 'j'){
                        return false;
                    }
                    else if(value == 'a'){
                        return false;
                    }
                    else if(card2.value == 'a'){
                        return true;
                    }
                    else{
                        return value > card2.value;
                    }
                }
                else if(suite == 'c'){
                    return true;
                }
                else if(card2.suite == 'c'){
                    return false;
                }
                else if(suite == 'h'){
                    return true;
                }
                else if(card2.suite == 'h'){
                    return false;
                }
                else if(suite == 'd'){
                    return true;
                }
                else if(card2.suite == 'd'){
                    return false;
                }
            }
            
        };

        Node* root;

        bool insert(char newSuite, char newVal, Node* n);
        void clear(Node* n);
        Node* getNodeFor(char suite, char value) const;
        Node* getPredecessorNode(char suite, char value) const;
        Node* getSuccessorNode(char suite, char value) const;
};

#endif
