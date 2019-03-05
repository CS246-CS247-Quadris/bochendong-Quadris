#include "LV0.hpp"
using namespace std;
LV0::LV0(std::string file){
    LV = 0;
    infile.open(file);
}

char LV0::getblock(){
    char type;
    infile >> type;
    return type;
}

void LV0::norandom(string file){}

void LV0::random(){}

LV0::~LV0(){
    infile.close();
}
