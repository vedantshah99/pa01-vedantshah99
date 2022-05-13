#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>
#include "cards.h"
#include "utility.h"

using namespace std;


int main(int argv, char** argc){ 
  Cards list1;
  Cards list2;

  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }

  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  //Read each file
  while (getline (cardFile1, line) && (line.length() > 0)){
    string temp = "";
    string word;
    
    for(auto x : line){
      if(x == ' '){
        for(auto y : temp){
          word += y;
        }
        temp = "";
      }
      else{
        temp = temp + x;
      }
    }
    int numerical = stringToInt(word, temp);
    //cout << numerical << endl;
    list1.insert(numerical);
  }
  cardFile1.close();
  //list1.print();

  //getting second list
  while (getline (cardFile2, line) && (line.length() > 0)){
    string temp = "";
    string word;

    for(auto x : line){
      if(x == ' '){
        for(auto x : temp){
          word += x;
        }
        temp = "";
      }
      else{
        temp = temp + x;
      }
    }
    int numerical = stringToInt(word, temp);
    list2.insert(numerical);
  }
  cardFile2.close();
  //list2.print();
  //cout << endl;


  //game
  cout << "Alice picked a matching card ";
  list1.hasSame(list2);

  cout << "Bob picked a matching card ";
  list1.hasSame(list2);

  cout << "Alice picked a matching card ";
  list1.hasSame(list2);

  cout << "Bob picked a matching card ";
  list2.hasSame(list1);
  cout << endl;

  cout << "Alice's cards:" << endl;
  list1.print();
  cout << endl;
  cout << "Bob's cards:" << endl;
  list2.print();

  return 0;
}
