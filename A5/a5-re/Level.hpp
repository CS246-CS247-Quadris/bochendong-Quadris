#ifndef Level_hpp
#define Level_hpp
#include <fstream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <iostream>
class Level {
protected:
    int LV;
    std::ifstream infile;
public:
    int getlevel();
    // Use only in LV3 and LV4
    virtual void random() = 0;
    virtual void norandom(std::string file) = 0;
    
    virtual char getblock() = 0;
    
    static Level* setlevel(int level, std::string = "sequence.txt");
    static Level* levelup(Level* lv);
    static Level* leveldown(Level* lv);
    
    virtual ~Level(){}
};
#endif
