#ifndef LV0_hpp
#define LV0_hpp
#include "Level.hpp"
class LV0: public Level {
public:
    LV0(std::string file = "sequence.txt");
    virtual char getblock() override;
    virtual void random() override;
    virtual void norandom(std::string file) override;
    virtual ~LV0();
};
#endif
