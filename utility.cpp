#include <iostream>
#include <ostream>
#include <string>
#include <cstring>
#include "utility.h"

using namespace std;

int stringToInt(string suite, string value){
    int total = 0;
    if(suite == "c"){
        total += 400;
    }
    else if(suite == "d"){
        total += 300;
    }
    else if(suite == "s"){
        total +=200;
    }
    else if(suite == "h"){
        total += 100;
    }

    if(value == "k"){
        total +=13;
    }
    else if(value == "q"){
        total += 12;
    }
    else if(value == "j"){
        total += 11;
    }
    else if(value == "a"){
        total += 1;
    }
    else{
        total += stoi(value);
    }
    return total;
}
