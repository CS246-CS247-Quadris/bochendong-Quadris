#include "Block.hpp"
using namespace std;
void Block::left(){
    for (int i = 0; i < 4; i ++) info.pos[i].x -= 1;
}

void Block::right(){
    for (int i = 0; i < 4; i ++) info.pos[i].x += 1;
}

void Block::down(){
    for (int i = 0; i < 4; i ++) info.pos[i].y -= 1;
}
void Block::up(){
    for (int i = 0; i < 4; i ++) info.pos[i].y += 1;
}
void Block::drop(int distance){
    for (int i = 0; i < 4; i ++) info.pos[i].y -= distance;
}

void Block::setblock(char c){
    info.type = c;
    vector<Posn> pos = getinfo().pos;
    info.pos.clear();
    
    if (c == 'S'){
        info.pos.push_back({1,14});
        info.pos.push_back({2,14});
        info.pos.push_back({0,13});
        info.pos.push_back({1,13});
    } else if (c == 'L') {
        info.pos.push_back({2,14});
        info.pos.push_back({0,13});
        info.pos.push_back({1,13});
        info.pos.push_back({2,13});
    } else if (c == 'Z') {
        info.pos.push_back({0,14});
        info.pos.push_back({1,14});
        info.pos.push_back({1,13});
        info.pos.push_back({2,13});
    } else if (c == 'J') {
        info.pos.push_back({0,14});
        info.pos.push_back({0,13});
        info.pos.push_back({1,13});
        info.pos.push_back({2,13});
    } else if (c == 'O') {
        info.pos.push_back({0,14});
        info.pos.push_back({1,14});
        info.pos.push_back({0,13});
        info.pos.push_back({1,13});
    } else if (c == 'T') {
        info.pos.push_back({0,14});
        info.pos.push_back({1,14});
        info.pos.push_back({2,14});
        info.pos.push_back({1,13});
    } else {
        for (int i = 0; i < 4; i ++) info.pos.push_back({i,14});
    }
}
