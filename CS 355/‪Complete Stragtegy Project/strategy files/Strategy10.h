#ifndef _STRATEGY10_H
#define _STRATEGY10_H

#include "Strategy.h"

// Class inherited from Strategy
// this is the class declaration for your strategy
class Strategy10 : public Strategy {
private:
    int totalBoxes;


	//add any extra data members here if you need them
public:
	Strategy10();
	int MakeDecision();
	void ReceiveStatus(int e);
	void Reset();
	int Tie();
	string Name();

};

#endif
