#ifndef LV1_HPP
#define LV1_HPP
#include "Level.hpp"
class LV1: public Level {
public:
    LV1();
    virtual char getblock() override;
    virtual void random() override;
    virtual void norandom(std::string file) override;
    ~LV1();
};
#endif
