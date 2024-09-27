#ifndef _STRATEGY14_H
#define _STRATEGY14_H
#include "Strategy.h"

// Class inherited from Strategy
// this is the class declaration for your strategy
class Strategy14 : public Strategy {
private:
	int remaning;

	//add any extra data members here if you need them
public:
	Strategy14();
	int MakeDecision(void);
	void ReceiveStatus(int e);
	void Reset();
	int Tie();
	string Name();
};
#endif