#ifndef O_Block_hpp
#define O_Block_hpp
#include "Block.hpp"
class Oblock :public Block {
public:
    Oblock(char type, int level);
    virtual void clockwise() override {return;};
    virtual void counterclock() override {return;};
    ~Oblock() {};
};
#endif
