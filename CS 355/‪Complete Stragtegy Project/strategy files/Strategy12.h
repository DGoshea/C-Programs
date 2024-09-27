#ifndef _STRATEGY12_H
#define _STRATEGY12_H

#include "Strategy.h"

// Class inherited from Strategy 
// this is the class declaration for your strategy
class Strategy12 : public Strategy {
	
	//add any extra data members here if you need them
public:
	Strategy12();
	int MakeDecision(void);	
	void ReceiveStatus(int e);
	void Reset();
	int Tie();
	string Name();

};

#endif