#ifndef Exception_hpp
#define Exception_hpp
#include "Exception.hpp"
#include <sstream>
class Exception{
public:
    virtual std::string what() = 0;
};

class Full: public Exception{
    std::string f;
public:
    Full(std::string full):f{full}{}
    virtual std::string what() override {return f;}
};

class Has_No_Effect: public Exception{
    std::string No_Effect;
public:
    Has_No_Effect(std::string No_Effect):No_Effect{No_Effect}{}
    virtual std::string what() override {return No_Effect;}
};

class No_Matching_prefix : public Exception{
    std::string No_Matching;
   public:
    No_Matching_prefix(std::string No_Matching): No_Matching{No_Matching}{}
    virtual std::string what() override {return No_Matching;}
};

class Has_front_number : public No_Matching_prefix{
public:
    int n;
    Has_front_number(int n, std::string Matching):No_Matching_prefix{Matching},n{n}{}
};
#endif
