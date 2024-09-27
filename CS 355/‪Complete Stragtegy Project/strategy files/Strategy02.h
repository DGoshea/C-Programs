#ifndef _STRATEGY02_H
#define _STRATEGY02_H

#include "Strategy.h"

// Class inherited from Strategy 
// this is the class declaration for your strategy
class Strategy02 : public Strategy {
	
	//add any extra data members here if you need them
public:
	Strategy02();
	int MakeDecision(void);	
	void ReceiveStatus(int e);
	void Reset();
	int Tie();
	string Name();

};

#endif