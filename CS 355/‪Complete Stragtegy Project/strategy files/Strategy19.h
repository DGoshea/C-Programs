#ifndef _STRATEGY19_H
#define _STRATEGY19_H

#include "Strategy.h"

class Strategy19 : public Strategy {
public:
    Strategy19();
    int MakeDecision(void) override;
    void ReceiveStatus(int e) override;
    void Reset() override;
    int Tie() override;
    string Name() override;
};

#endif
