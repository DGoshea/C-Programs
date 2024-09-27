#ifndef _STRATEGY21_H
#define _STRATEGY21_H

#include "Strategy.h"

// Class inherited from Strategy 
// this is the class declaration for your strategy
class Strategy21 : public Strategy {
	
	//add any extra data members here if you need them
	int movesleft;
public:
	Strategy21();
	int MakeDecision(void);	
	void ReceiveStatus(int e);
	void Reset();
	int Tie();
	string Name();

};

#endif
