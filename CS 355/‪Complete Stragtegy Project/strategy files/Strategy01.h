#ifndef STRATEGY01_H
#define STRATEGY01_H

#include "Strategy.h"
#include <string>

class Strategy01 : public Strategy {
public:
    Strategy01();
    virtual ~Strategy01() {}
    virtual int MakeDecision();    
    virtual void ReceiveStatus(int e);
    virtual void Reset();
    virtual int Tie() { return 11; } 
    virtual std::string Name() { return "Strategy01's Strategy"; }
};

#endif
