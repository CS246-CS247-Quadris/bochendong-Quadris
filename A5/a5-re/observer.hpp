#ifndef observer_hpp
#define observer_hpp

class Subject;
class Observer {
public:
    virtual void notify(Subject &whoFrom) = 0;
    virtual ~Observer() = default;
};
#endif
