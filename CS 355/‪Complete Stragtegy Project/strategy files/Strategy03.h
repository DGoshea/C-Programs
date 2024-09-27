#ifndef _STRATEGYX_H
#define _STRATEGYX_H

#include "Strategy.h"

// Class inherited from Strategy 
// this is the class declaration for your strategy
class Strategy03 : public Strategy {
	
	//add any extra data members here if you need them
public:
	Strategy03();
	int MakeDecision(void);	
	void ReceiveStatus(int e);
	void Reset();
	int Tie();
	string Name();

};

#endif