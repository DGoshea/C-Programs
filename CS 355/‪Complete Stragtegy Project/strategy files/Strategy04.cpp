#include "Strategy04.h"
#include <random>

Strategy04::Strategy04(){}

int Strategy04::MakeDecision(void){
/*
	There are 20 total squares to be filled, which means that if you fill the 16th square, reguardless of the opponents next move
	you are guaranteed to win. So if you make moves that end up in you filling in the fourth square in the sequence, you'll always
	fill in the 16th square. This is easy if you're going second. However, going first means that if your opponent knows that making 4
	guarantees winning, theres no way to win. You must rely on the opponent not making a total of 4, capitalize on that by making the
	total of 4, when that happens, you'll be able to win.
*/
	int oppoMove = movesleft % 4; //determines how many spaces the opponent filled in based upon how many spaces are left
	
	//depending on how many spaces opponent filled in, this determines how many needs filled to make 4
	if (oppoMove == 1)
	{
		return 3;
	}
	else if (oppoMove == 2)
	{
		return 2;
	}
	else if (oppoMove == 3)
	{
		return 1;
	}
	//The else statement returns a random value since 
	else
	{
		return 3;
	}
}

void Strategy04::ReceiveStatus(int e)
{
	movesleft = e;
}

void Strategy04::Reset(){}

int Strategy04::Tie(){return 18;}

string Strategy04::Name(){return "Strategy04's Strategy";}