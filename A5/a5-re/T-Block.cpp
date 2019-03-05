#include "T-Block.hpp"
using namespace std;
Tblock::Tblock(char type, int level){
    info.level = level;
    info.type = type;
    info.pos.push_back({0,14});
    info.pos.push_back({1,14});
    info.pos.push_back({2,14});
    info.pos.push_back({1,13});
}

void Tblock::clockwise(){
    int num = 0;
    vector<Posn> pos = getinfo().pos;
    int l = pos.at(0).x;    //The leftmost x coordinate of the block
    int r = pos.at(0).x;    //The rightmost x coordinate of the block
    int b = pos.at(0).y;    //Block lowest y coordinate
    for(unsigned int i = 0; i < pos.size(); i++) {
        if (pos.at(i).x < l)  l = pos.at(i).x;
        if (pos.at(i).x > r)  r = pos.at(i).x;
        if (pos.at(i).y < b) b = pos.at(i).y;
    }
    if ((r - l) == 2) {
        for(unsigned int i = 0; i < pos.size(); i++) {
            if (pos.at(i).y == b) num++;
        }
        if (num == 3) {
            info.pos[0] = {l,b + 2};
            info.pos[1] = {l,b + 1};
            info.pos[2] = {l + 1,b + 1};
            info.pos[3] = {l,b};
        } else {
            info.pos[0] = {l + 1,b + 2};
            info.pos[1] = {l,b + 1};
            info.pos[2] = {l + 1,b + 1};
            info.pos[3] = {l + 1,b};
        }
    } else {
        for(unsigned int i = 0; i < pos.size(); i++) {
            if (pos.at(i).x == l) num++;
        }
        if (num == 3) {
            info.pos[0] = {l,b + 1};
            info.pos[1] = {l + 1,b + 1};
            info.pos[2] = {l + 2,b + 1};
            info.pos[3] = {l + 1,b};
        } else {
            info.pos[0] = {l + 1,b + 1};
            info.pos[1] = {l,b};
            info.pos[2] = {l + 1,b};
            info.pos[3] = {l + 2,b};
        }
    }
}

void Tblock::counterclock() {
    int num = 0;
    vector<Posn> pos = getinfo().pos;
    int l = pos.at(0).x;    //The leftmost x coordinate of the block
    int r = pos.at(0).x;    //The rightmost x coordinate of the block
    int b = pos.at(0).y;    //Block lowest y coordinate
    for(unsigned int i = 0; i < pos.size(); i++) {
        if (pos.at(i).x < l)  l = pos.at(i).x;
        if (pos.at(i).x > r)  r = pos.at(i).x;
        if (pos.at(i).y < b) b = pos.at(i).y;
    }
    if ((r - l) == 2) {
        for(unsigned int i = 0; i < pos.size(); i++) {
            if (pos.at(i).y == b) num++;
        }
        if (num == 3) {
            info.pos[0] = {l + 1,b + 2};
            info.pos[1] = {l,b + 1};
            info.pos[2] = {l + 1,b + 1};
            info.pos[3] = {l + 1,b};
        } else {
            info.pos[0] = {l,b + 2};
            info.pos[1] = {l,b + 1};
            info.pos[2] = {l + 1,b + 1};
            info.pos[3] = {l,b};
        }
    } else {
        for(unsigned int i = 0; i < pos.size(); i++) {
            if (pos.at(i).x == l) num++;
        }
        if (num == 3) {
            info.pos[0] ={l + 1,b + 1};
            info.pos[0] ={l,b};
            info.pos[0] = {l + 1,b};
            info.pos[0] ={l + 2,b};
        } else {
            info.pos[0] = {l,b + 1};
            info.pos[0] = {l + 1,b + 1};
            info.pos[0] = {l + 2,b + 1};
            info.pos[0] = {l + 1,b};
        }
    }
}

