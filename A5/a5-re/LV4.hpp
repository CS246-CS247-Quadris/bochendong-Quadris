#ifndef LV4_hpp
#define LV4_hpp
#include "Level.hpp"
class LV4: public Level {
    bool Random;
public:
    LV4();
    virtual char getblock() override;
    virtual void random() override;
    virtual void norandom(std::string file) override;
    ~LV4();
};
#endif
