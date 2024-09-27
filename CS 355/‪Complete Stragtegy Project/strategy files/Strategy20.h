// StrategyX.h

#ifndef _STRATEGY20_H
#define _STRATEGY20_H

#include "Strategy.h"

// Class inherited from Strategy
// This is the class declaration for the strategy implemented by StrategyX
class Strategy20 : public Strategy {
public:
    // Constructor for StrategyX
    Strategy20();

    // Override the MakeDecision method from the base class
    int MakeDecision() override;

    // Override the ReceiveStatus method from the base class
    void ReceiveStatus(int totalBoxes) override;

    // Override the Reset method from the base class
    void Reset() override;

    // Override the Tie method from the base class
    int Tie() override;

    // Override the Name method from the base class
    string Name() override;
};

#endif

