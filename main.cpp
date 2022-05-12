#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>
#include "tests.cpp"

using namespace std;


int main(int argv, char** argc){
  Cards list;

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
    char temp;
    string line;
    char word;

    getline(cardFile1, line);
    for(auto x : line){
      if(x == ' '){
        word = temp;
      }
      else{
        temp = x;
      }
    }
    cout << word << endl;
    cout << temp << endl;
    list.insert(word, temp);
  }
  cardFile1.close();

  while (getline (cardFile2, line) && (line.length() > 0)){

  }
  cardFile2.close();


  return 0;
}
