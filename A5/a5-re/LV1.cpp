#include "LV1.hpp"
using namespace std;
LV1::LV1(){LV = 1;}

char LV1::getblock(){
    //srand ((unsigned) time (NULL));
    int num = rand() % 12;
    if(num < 1)return 'S';
    else if(num < 2)return 'Z';
    else if(num < 4)return 'I';
    else if(num < 6)return 'J';
    else if(num < 8)return 'L';
    else if(num < 10)return 'O';
    else return 'T';
}

void LV1::norandom(string file){}

void LV1::random(){}

LV1::~LV1(){}

