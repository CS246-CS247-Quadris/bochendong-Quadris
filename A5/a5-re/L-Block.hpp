#ifndef L_Block_hpp
#define L_Block_hpp
#include "Block.hpp"
class Lblock :public Block {
public:
    Lblock(char type,int level);
    virtual void clockwise() override;
    virtual void counterclock() override;
    ~Lblock() {};
};
#endif
