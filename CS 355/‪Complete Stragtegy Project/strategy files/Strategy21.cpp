
#include "Strategy21.h"

// Initializes the members, if needed.
Strategy21::Strategy21(){}

// Checks the number of boxes to remove based on the current game state.
int Strategy21::MakeDecision(){
	
	// Default decision to remove 1 box if no strategic advantage is identified.
    int boxesToRemove = 1; 
    
    // Calculate remainder to identify strategic move.
    int remainderAfterDivision = movesleft % 4; 

	// Ensure there are boxes left to make a decision.
    if (movesleft > 0) 
	{ 
        if (remainderAfterDivision == 0) 
		{
            // If the remaining boxes are a multiple of 4,
			// remove 1 to avoid giving the opponent an advantageous position.
            boxesToRemove = 1;
        } else {
            // If not a multiple of 4, remove enough boxes to reach the nearest 
			// multiple of 4, setting up a strategic advantage.
            boxesToRemove = remainderAfterDivision;
        }
    }

	// Return the calculated decision.
    return boxesToRemove; 
}

// Updates the strategy with the current number of boxes left in the game.
void Strategy21::ReceiveStatus(int currentBoxes)
	{
	movesleft = currentBoxes;
	}

// It sets any internal state to start a new game. 
// Inherits Reset from the Strategy class.
void Strategy21::Reset() 
	{
     Strategy::Reset();
	}

// Determines the outcome in case of a tie. Here, it defaults to a loss (0).
int Strategy21::Tie(){return 14;}

// Provides the name of this strategy for identification.
string Strategy21::Name(){return "Strategy21's Strategy";}

