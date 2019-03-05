#ifndef LV2_hpp
#define LV2_hpp
#include "Level.hpp"
class LV2: public Level {
public:
    LV2();
    virtual char getblock() override;
    virtual void random() override;
    virtual void norandom(std::string file) override;
    ~LV2();
};
#endif
