#include "LV3.hpp"
using namespace std;
LV3::LV3(){
    LV = 3;
    Random = true;
}

void LV3::random(){
    Random = true;
}
void LV3:: norandom(std::string file){
    Random = false;
    infile.close();
    infile.open(file);
}

char LV3::getblock(){
    if(!Random){
        char type;
        infile >> type;
        return type;
    }
    //srand ((unsigned) time (NULL));
    int num = rand() % 9;
    if(num < 2)return 'S';
    if(num < 4)return 'Z';
    if(num < 5)return 'I';
    if(num < 6)return 'J';
    if(num < 7)return 'L';
    if(num < 8)return 'O';
    return 'T';
}

LV3::~LV3(){
    infile.close();
}
