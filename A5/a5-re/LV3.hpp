#ifndef LV3_hpp
#define LV3_hpp
#include "Level.hpp"
class LV3: public Level {
    bool Random;
public:
    LV3();
    virtual char getblock() override;
    virtual void random() override;
    virtual void norandom(std::string file) override;
    ~LV3();
};
#endif
