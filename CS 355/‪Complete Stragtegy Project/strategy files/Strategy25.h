/*----------------------------------------------------------------------------------------------*
 																    *
 * Program:		Strategy for a game with a grid of 4x5. The last player to mark off a box wins. *
 *----------------------------------------------------------------------------------------------*/
#ifndef _STRATEGY25_H
#define _STRATEGY25_H

#include "Strategy.h"

// Class inherited from Strategy 
// this is the class declaration for your strategy
class Strategy25 : public Strategy {
private:
	//add any extra data members here if you need them
public:
	Strategy25();
	int MakeDecision(void);	
	void ReceiveStatus(int e);
	void Reset();
	int Tie();
	string Name();

};

#endif
