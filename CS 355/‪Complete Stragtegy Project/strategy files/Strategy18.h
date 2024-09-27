
// Description: Change/Develop a strategy for the method 
//		MakeDecision() to win the game developed by Dr.Jenkins.
//--------------------------------------------------------------
#ifndef _STRATEGY18_H
#define _STRATEGY18_H

#include "Strategy.h"

// Class inherited from Strategy 
// this is the class declaration for your strategy
class Strategy18 : public Strategy {
	
	int MoveMade;//This is basically a holding integer to help with the return value calculation for MakeDecision().
	
	//add any extra data members here if you need them
public:
	Strategy18();//Constructor (Parameterless)
	int MakeDecision(void);	//Strategy to play the game
	void ReceiveStatus(int e);//Method to set the number of moves left
	void Reset();//Similar to constructor, resets any data members (if applicable)
	int Tie();//To be developed
	string Name();//To be developed

};

#endif