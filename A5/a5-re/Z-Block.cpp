#include "Z-Block.hpp"
using namespace std;
Zblock::Zblock(char type, int level){
    info.level = level;
    info.type = type;
    info.pos.push_back({0,14});
    info.pos.push_back({1,14});
    info.pos.push_back({1,13});
    info.pos.push_back({2,13});
}

void Zblock::clockwise(){
    vector<Posn> pos = getinfo().pos;
    int l = pos.at(0).x;    //The leftmost x coordinate of the block
    int r = pos.at(0).x;    //The rightmost x coordinate of the block
    int b = pos.at(0).y;    //Block lowest y coordinate
    for(unsigned int i = 0; i < pos.size(); i++) {
        if (pos.at(i).x < l)  l = pos.at(i).x;
        if (pos.at(i).x > r)  r = pos.at(i).x;
        if (pos.at(i).y < b) b = pos.at(i).y;
    }
    
    vector<Posn> n;
    if ((r - l) == 2) {
        // the block is  ZZ
        //                ZZ
        info.pos[0] = {l+1,b+2};
        info.pos[1] = {l,b+1};
        info.pos[2] = {l+1,b+1};
        info.pos[3] = {l,b};
    } else {
        // the block is  Z
        //              ZZ
        //              Z
        info.pos[0] = {l,b+1};
        info.pos[1] = {l+1,b+1};
        info.pos[2] = {l+1,b};
        info.pos[3] = {l+2,b};
    }
}

void Zblock::counterclock(){
    clockwise();
}
