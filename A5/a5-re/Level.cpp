#include "Level.hpp"
#include "LV0.hpp"
#include "LV1.hpp"
#include "LV2.hpp"
#include "LV3.hpp"
#include "LV4.hpp"
int Level::getlevel(){return LV;}

Level * Level::setlevel(int level, std::string file){
    Level* lv;
    if (level == 0) lv =  new LV0(file);
    else if (level == 1) lv = new LV1();
    else if (level == 2) lv = new LV2();
    else if (level == 3) lv = new LV3();
    else lv = new LV4();
    return lv;
}

Level * Level::levelup(Level* lv){
    if (lv->getlevel() == 4) return lv;
    else {
        int level = lv->getlevel();
        delete lv;
        if (level == 0) {
            lv = new LV1();
        } else if (level == 1) {
            lv = new LV2();
        }
        else if (level == 2) {
            lv = new LV3();
        } else {
            lv = new LV4();
        }
    }
    return lv;
}

Level * Level::leveldown(Level* lv){
    if (lv->getlevel() == 0) return lv;
    else {
        int level = lv->getlevel();
        delete lv;
        if (level == 1) {
            lv = new LV0();
        } else if (level == 2) {
            lv = new LV1();
        } else if (level == 3) {
            lv = new LV2();
        } else {
            lv = new LV3();
        }
    }
    return lv;
}
