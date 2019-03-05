#include "O-Block.hpp"
using namespace std;
Oblock::Oblock(char type, int level){
    info.level = level;
    info.type = type;
    info.pos.push_back({0,14});
    info.pos.push_back({1,14});
    info.pos.push_back({0,13});
    info.pos.push_back({1,13});
}
