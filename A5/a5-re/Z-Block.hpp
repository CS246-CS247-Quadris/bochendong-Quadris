#ifndef Z_Block_hpp
#define Z_Block_hpp
#include "Block.hpp"
class Zblock :public Block {
public:
    Zblock(char type, int level);
    virtual void clockwise() override;
    virtual void counterclock() override;
    ~Zblock() {};
};
#endif
