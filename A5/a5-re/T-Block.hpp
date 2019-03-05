#ifndef T_Block_hpp
#define T_Block_hpp
#include "Block.hpp"
class Tblock :public Block {
public:
    Tblock(char type, int level);
    virtual void clockwise() override;
    virtual void counterclock() override;
    ~Tblock() {};
};
#endif
