#include "LV2.hpp"
using namespace std;
LV2::LV2(){LV = 2;}

char LV2::getblock(){
    //srand ((unsigned) time (NULL));
    int num = rand() % 7;
    if(num < 1) return 'S';
    else if(num < 2) return 'Z';
    else if(num < 3) return 'I';
    else if(num < 4) return 'J';
    else if(num < 5) return 'L';
    else if(num < 6) return 'O';
    else return 'T';
}

void LV2::norandom(string file){}

void LV2::random(){}

LV2::~LV2(){}
