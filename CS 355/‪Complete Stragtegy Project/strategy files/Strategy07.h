#ifndef _STRATEGY07_H
#define _STRATEGY07_H

#include "Strategy.h"

// Class inherited from Strategy 
// this is the class declaration for your strategy
class Strategy07 : public Strategy {
	
	//add any extra data members here if you need them
public:
	Strategy07();
	int MakeDecision(void);	
	void ReceiveStatus(int e);
	void Reset();
	int Tie();
	string Name();

};

#endif