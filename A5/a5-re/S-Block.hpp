#ifndef S_Block_hpp
#define S_Block_hpp
#include "Block.hpp"
class Sblock :public Block {
public:
    Sblock(char type,int level);
    virtual void clockwise() override;
    virtual void counterclock() override;
    ~Sblock() {};
};
#endif
