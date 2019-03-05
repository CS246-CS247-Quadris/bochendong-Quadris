#ifndef Grid_hpp
#define Grid_hpp
#include <vector>
#include "Block.hpp"
#include "Level.hpp"
#include "subject.hpp"
#include "T-Block.hpp"
#include "I-Block.hpp"
#include "J-Block.hpp"
#include "O-Block.hpp"
#include "L-Block.hpp"
#include "S-Block.hpp"
#include "Z-Block.hpp"
#include "Exception.hpp"
#include "TextDisplay.hpp"
class Grid: public Subject {
    public:
    // Keep track of current block's information
    Block * b;
    Level * LV;
    TextDisplay *td = nullptr;
    
    char Curr_Type;
    char Next_Type;
    // Record current scores and highest scores
    int Curr_Score;
    int High_Score = 0;
    // Record the number of blocks of level 4 without clearing one line
    int LV4_Counter;
    // Determine whether we need Graphic Display
    bool Graphic;
    
    bool random;
    // Record information about blocks that have not been completely eliminated
    std::vector <Block *> Blocks;
    
    std::vector <std::vector <char>> grid;
    
    void init(bool Text_Only, int level, std::string file = "sequence.txt");
    // For initialize, clears old grid, if necessary. For restart, always clear grid
    void clear();
    
    void level_up();
    void level_down();
    
    // the string is down,left,right,drop,clockwise or counterclockwise
    void Operation(std::string OP);
    
    void Get_Block(int level);
    void Update_Grid();
    
    void eliminate();
    void notify();
    
    void dorandom(){LV->random();}
    void norandom(std::string file){LV->norandom(file);}
    
    void setblock(char c);
    
    friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};

#endif
