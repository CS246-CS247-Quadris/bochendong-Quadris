#ifndef TextDisplay_hpp
#define TextDisplay_hpp
#include <vector>
#include <iostream>
#include "subject.hpp"

class TextDisplay: public Observer{
    std::vector<std::vector<char> >&grid;
    int level;
    char nextType;
    int Curr_score;
    int High_score;
public:
    TextDisplay(std::vector<std::vector<char>> & board);
    virtual void notify(Subject &whoFrom) override;
    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};
#endif
