#ifndef _STRATEGY11_H
#define _STRATEGY11_H

#include "Strategy.h"

// Class inherited from Strategy 
// this is the class declaration for your strategy
class Strategy11 : public Strategy {
private: 
int numMoves; 	

public:
	Strategy11();
	int MakeDecision(void);	
	void ReceiveStatus(int e);
	void Reset();
	int Tie();
	string Name();

};

#endif
