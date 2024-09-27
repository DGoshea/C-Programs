// ---------------------------------------------------------------------------

// Description: This project implements a strategy for a game in a 5x4 grid 
// where players take turns marking 1, 2, or 3 boxes with 'X's until the last 
// 'X' is marked off. The player to mark the last 'X' is the winner.
// ---------------------------------------------------------------------------

#ifndef _STRATEGY06_H
#define _STRATEGY06_H

#include "Strategy.h"

// Class inherited from Strategy 
// this is the class declaration for your strategy

// derived from Strategy base class
class Strategy06 : public Strategy {
	
	//add any extra data members here if you need them
public:
	Strategy06(); // constructor
	int MakeDecision(void); // to be implemented from base class
	void ReceiveStatus(int e); // to be implemented from base class
	void Reset(); // to be implemented from base class only if new data members are created
	int Tie(); // for next project
	string Name(); // for next project

};

#endif