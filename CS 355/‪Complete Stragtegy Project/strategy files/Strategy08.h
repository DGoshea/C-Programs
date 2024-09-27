#ifndef _STRATEGY08_H
#define _STRATEGY08_H

#include "Strategy.h" 

// Class inherited from Strategy 
// this is the class declaration for your strategy
class Strategy08 : public Strategy 
{	
	//add any extra data members here if you need them
public:
	Strategy08();
	int MakeDecision(void);	
	void ReceiveStatus(int e);
	void Reset();
	int Tie();
	string Name();
//	int movesleft; // for keeping track of the global identifier SIZE
};

#endif