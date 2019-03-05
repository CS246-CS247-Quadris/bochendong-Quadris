#ifndef J_Block_hpp
#define J_Block_hpp
#include "Block.hpp"
class Jblock :public Block {
public:
    Jblock(char type, int level);
    virtual void clockwise() override;
    virtual void counterclock() override;
    ~Jblock() {};
};
#endif
