//*****************************************************************************************

//Description:	Come up with a strategy that will allow you to win the following game.  
//				Imagine you have a 5 x 4 grid.  Two players will take turns crossing off 
//				boxes within this grid. A player may "X" off 1, 2, or 3 boxes per turn 
//				(no less, no more).  The player to "X" off the last box wins the game. 
//Due Date:		2/29/2024 
//******************************************************************************************
#include "Strategy09.h"


Strategy09::Strategy09(){}

//**********************************************
// This method makes a decision for the student
//		player, marking off the optimal number
//		of boxes (1-3). If movesleft is even
//		then two boxes are marked off. If 
//		movesleft is odd then three boxes are
//		marked off. The goal is to avoid your
//		turn landing when there are 4 unmarked
//		boxes left. If you land then, your 
//		opponent wins no matter what given the
//		box limitations/move. 
// Incoming Data: 
//		none
// Outgoing Data:
//		returns 1 if you want to mark off 1 box
//		returns 2 if you want to mark off 2 boxes
//		returns 3 if you want to mark off 3 boxes
//**********************************************
int Strategy09::MakeDecision(void){
	
	if(movesleft%2==0)
	{
		return 2;
	}
	else if (movesleft%2==1)
	{
		return 3;
	}
}
//**********************************************
// This method passes in how many unmarked
//		boxes are left after each move.
// Incoming Data: 
//		int e as the number of unmarked boxes
//		left.
// Outgoing Data:
//		none
//**********************************************
void Strategy09::ReceiveStatus(int e){
	movesleft = e;
}

void Strategy09::Reset(){}

int Strategy09::Tie(){return 9;}

string Strategy09::Name(){return "Strategy09's Strategy";}
