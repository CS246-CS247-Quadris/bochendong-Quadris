#include "I-Block.hpp"
using namespace std;
Iblock::Iblock(char type, int level){
    info.level = level;
    info.type = type;
    for (int i = 0; i < 4; i ++) info.pos.push_back({i,14});
}

void Iblock::clockwise(){
    vector<Posn> pos = getinfo().pos;
    int l = pos.at(0).x;    //The leftmost x coordinate of the block
    int r = pos.at(0).x;    //The rightmost x coordinate of the block
    int b = pos.at(0).y;    //Block lowest y coordinate
    for(unsigned int i = 0; i < pos.size(); i++) {
        if (pos.at(i).x < l)  l = pos.at(i).x;
        if (pos.at(i).x > r)  r = pos.at(i).x;
        if (pos.at(i).y < b) b = pos.at(i).y;
    }
    if ((r - l) == 3) {
        // the block is IIII
        info.pos[0] = {l,b + 3};
        info.pos[1] = {l,b + 2};
        info.pos[2] = {l,b + 1};
        info.pos[3] = {l,b};
    } else {
        // the block is I
        //              I
        //              I
        //              I
        info.pos[0] = {l,b};
        info.pos[1] = {l + 1,b};
        info.pos[2] = {l + 2,b};
        info.pos[3] = {l + 3,b};
    }
}

void Iblock::counterclock() {
    clockwise();
}
