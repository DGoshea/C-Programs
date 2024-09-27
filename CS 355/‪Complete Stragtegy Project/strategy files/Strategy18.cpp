#include "Strategy18.h"
#include <ctime>//I included the ctime for the rand() and srand().

Strategy18::Strategy18(){}

/***************************************************************
Name: MakeDecision()
Purpose: To return an integer (1, 2, or 3) based upon a 
	strategy. This strategy is to, if possible, set  movesleft 
	to a multiple of 4 to ensure victory.
Input: void
Output: Returns an integer representing the move to be made
***************************************************************/
int Strategy18::MakeDecision(void){
//I was confused by the  "You will absolutely need to write code for ... [the] ReceiveStatus method," but I did use movesleft, so I hope that is acceptable. 

	MoveMade = movesleft % 4;//MoveMade is set to movesleft's remainder when divided by 4 (to make movesleft a multiple of 4 for the opponent).
	if (MoveMade == 0)//If the number of movesleft is already divisible by 4, then there is no best number to submit.
	{
		srand(time(0));//Used to seed rand() with zero. (It's common code, but I got it from the C++ textbook I used last year.)
		//Below, MoveMade is set to 1, 2, or 3 (since 0 cannot be returned) and because the number doesn't matter.
			//If the opponent's code adjusts and movesleft remains a multiple of 4, I cannot win. HOWEVER, if
			//the opponent's code does not adjust, mine will adjust and set/return a number to make movesleft a 
			//multiple of 4, so they lose.
		MoveMade = (rand() % 3) + 1;//1 is added so the numbers are 1, 2, 3, not 0, 1, 2.
	}
	return MoveMade;//This returns the integer selected based-upon whatever movesleft was (and still is at this point).
}

void Strategy18::ReceiveStatus(int e){movesleft = e;}

void Strategy18::Reset(){}

int Strategy18::Tie(){return 6;}

string Strategy18::Name(){return "Strategy18's Strategy";}