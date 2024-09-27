#ifndef _STRATEGY05_H
#define _STRATEGY05_H

#include "Strategy.h"

// Class inherited from Strategy 
// this is the class declaration for your strategy
class Strategy05 : public Strategy {
	
	//add any extra data members here if you need them
public:
	Strategy05();
	int MakeDecision();	
	void ReceiveStatus(int e);
	void Reset();
	int Tie();
	string Name();

};

#endif