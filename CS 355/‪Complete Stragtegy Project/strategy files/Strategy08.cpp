#include "Strategy08.h"

Strategy08::Strategy08(){}

int Strategy08::MakeDecision(void)
{ 
	/*
	* You will need to receiveStatus for how many squares to x off there are
	* Based on that info, you will need to decide how many squares to x off
	* Try to be strategic and use inheritance to your advantage
	*/
	
	// only one spot left, take it
	if(movesleft == 1)
	{
		return 1;
	}
	
	// only two left, take it
	else if(movesleft == 2)
	{
		return 2;
	}
	
	//only three left, take em
	else if(movesleft == 3)
	{
		return 3;
	}

		
	// plenty of spots left, use em
	else if(movesleft > 3)
	{	
		if(movesleft == 4) // nothing else you can really do but hope they don't take all three spots left
		{
			return 1;
		}
		else if(movesleft == 5) // if there's five, only take 1. That way you have a chance to get the last few
		{
			return 1;
		}
		else if(movesleft == 6) // opponent only has 4 places left, leaving you with 1, or 2 after their move
		{
			return 2;
		}
		else if(movesleft == 7) // opponent only has 4 places left after your move
		{
			return 3;
		}
		else if(movesleft == 8) // opponent has 5 places left after your move, they'll probably use 1
		{
			return 3;
		}
/*		else if(movesleft == 9) // opponent has 8 places left after your move, they'll probably use 2. 
		{
			return 1;
		}
		else if(movesleft == 10) // leave em with nine places left
		{
			return 1;
		}
		else if(movesleft == 11) // just want to get the number down to ten, so use two places for x 
		{
			return 2;
		}
		else if(movesleft == 12)
		{
			return 3;
		}
		else if(movesleft == 12)
		{
			return 1;
		}
		else if(movesleft == 13)
		{
			return 2;
		}
		else if(movesleft == 14)
		{
			return 1;
		}
		else if(movesleft == 15)
		{
			return 2;
		}
		else if(movesleft == 16)
		{
			return 1;
		}
		else if(movesleft == 17)
		{
			return 2;
		}
		else if(movesleft == 18)
		{
			return 1;
		}			
		else if(movesleft == 19)
		{
			return 2;
		}			
		else if(movesleft == 20)
		{
			return 1;
		}		*/					
	}	
	return 2;
}

void Strategy08::ReceiveStatus(int e)
{
	movesleft = e;
}

void Strategy08::Reset()
{
	// CODE BELOW
}


/*
* DO NOTTTTTTTTT TOUCH!
*/
int Strategy08::Tie(){return 37;}

string Strategy08::Name(){return "Strategy08's Strategy";}