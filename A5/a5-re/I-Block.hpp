#ifndef I_Block_hpp
#define I_Block_hpp
#include "Block.hpp"
class Iblock : public Block{
public:
    Iblock(char type, int level);
    virtual void clockwise() override;
    virtual void counterclock() override;
    ~Iblock() {};
};
#endif
