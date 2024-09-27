// ---------------------------------------------------------------------------

// Description: This program aims to utilize a strategy to win a game in a 5x4 grid by entering 1 to 3.
//				By filling in the last space, we take the win. Therefore, our startegy revolves around
//				filling in the last space.
// ---------------------------------------------------------------------------
#ifndef _STRATEGY15_H
#define _STRATEGY15_H
#include "Strategy.h"

//Derived class StrategyX from base class Strategy
class Strategy15 : public Strategy 
{
public:
	Strategy15();	//Default Constructor
	int MakeDecision(void);		//Returns a 1,2,or 3 to fill in the grid.
	void ReceiveStatus(int e);	//Receives the number of free spaces left in the grid.
	void Reset();	//Reset the attributes of this class.
	int Tie();	//Returns 100 for a tie in this game.
	string Name();	//Return the name of the strategy.
};

#endif
