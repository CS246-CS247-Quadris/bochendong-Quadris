#ifndef subject_hpp
#define subject_hpp
#include "state.hpp"
#include "observer.hpp"
#include <vector>

class Subject {
    std::vector<Observer *> observers;
    State state;
public:
    void setState(State state);
    State getState();
    void attach(Observer * o);
    void clearObservers();
    void notifyObservers();
};


#endif
