#ifndef _STRATEGY17_H
#define _STRATEGY17_H
#include "Strategy.h"

class Strategy17 : public Strategy {
public:
    Strategy17();
    int MakeDecision(void); 
    void ReceiveStatus(int e); 
    void Reset(); 
    int Tie(); 
    string Name(); 
};

#endif
