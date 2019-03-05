#ifndef Info_hpp
#define Info_hpp
#include <sstream>
#include <vector>
#include "Posn.hpp"
struct Info{
    char type;
    int level;
    int uneliminate = 4;
    std::vector <Posn> pos;
};
#endif
