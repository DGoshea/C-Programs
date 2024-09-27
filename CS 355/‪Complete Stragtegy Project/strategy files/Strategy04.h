#ifndef _STRATEGY04_H
#define _STRATEGY04_H

#include "Strategy.h"

// Class inherited from Strategy 
// this is the class declaration for your strategy
class Strategy04 : public Strategy {
	
	//add any extra data members here if you need them
public:
	Strategy04();
	int MakeDecision(void);	
	void ReceiveStatus(int e);
	void Reset();
	int Tie();
	string Name();

};

#endif