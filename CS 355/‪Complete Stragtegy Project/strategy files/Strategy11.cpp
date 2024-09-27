#include "Strategy11.h"
#include <cstdlib>
using namespace std; 
Strategy11::Strategy11(){numMoves = 0;}

int Strategy11::MakeDecision(void){
	
	//Generate a random number 1 - 3
	int randy = 1 + (rand()  % 3);
	
	//If I get first move draw two X's
	if(numMoves == 20)
	{
		return 2; 
	}
	
	//If the number is 7 draw 3 X's 
	if(numMoves == 7)
	{
		return 3;
	}
	
	//If the number is six and its my turn return 2 and win next move
	if(numMoves == 6)
	{
		return 2; 
	}
	
	//If the num of moves is 5 return 1 and win next move
	if(numMoves == 5)
	{
		return 1; 
	}
	
	//Win the game if there is only three spots
	else if(numMoves == 3)
	{
		return 3;
	}
	
	//Win the game if there is only two spots
	else if(numMoves == 2)
	{
		return 2; 
	}
	
	//Win the game if there is one spot left
	else if(numMoves == 1)
	{
		return 1; 
	}
	
	//If the number is not even use three
	else if(numMoves % 2 != 0)
	{
		return 3; 
	}
	
	//If the number is even then use two 
	else if(numMoves % 2 == 0)
	{
		return 2; 
	}
	
	//If none of these branches execute use a random number 1-3
	else
		return randy; 
}
void Strategy11::ReceiveStatus(int e){movesleft = e; numMoves = e;}

void Strategy11::Reset(){numMoves = 0;}

int Strategy11::Tie(){return 43;}

string Strategy11::Name(){return "Strategy11's Strategy";}
