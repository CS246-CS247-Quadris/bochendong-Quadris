#ifndef Block_hpp
#define Block_hpp
#include <vector>
#include <iostream>
#include "Info.hpp"

// Block is an abstract class
// Each block is born at the top left of the grid
class Block {
protected:
    // info record the infomation of the block's type , born level and positons
    Info info;
public:
    Info getinfo() {return info;}
    // provide following possible operation to block
    void left();
    void right();
    void down();
    void up();
    void drop(int distance);
    virtual void clockwise() = 0;
    virtual void counterclock() =0;
    // Set the current undroped block to another type of block
    void setblock(char c);
    void eliminate() {info.uneliminate -= 1;}
    virtual ~Block() {};
};
#endif
