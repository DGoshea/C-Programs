#include "Strategy01.h"

Strategy01::Strategy01() 
{
    // Initializing data members here
    movesleft = 0;
}

void Strategy01::ReceiveStatus(int e)
{
    // Updating the number of boxes which are not currently "X"ed off
	movesleft = e;
}

int Strategy01::MakeDecision() 
{
    // Implementing a strategy that aims to leave the opponent in a losing position.
    
    if (movesleft % 4 == 0)
	{
        // If the moves left are divisible by 4, take off 3 
        return 3;
    }
	else 
	{
        
        return movesleft % 4 ? movesleft % 4 : 1;
    }
}

void Strategy01::Reset() 
{
    // Reset the original data members to their original states
    movesleft = 0;
}
