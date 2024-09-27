// ---------------------------------------------------------------------------

// Description: This project implements a strategy for a game in a 5x4 grid 
// where players take turns marking 1, 2, or 3 boxes with 'X's until the last 
// 'X' is marked off. The player to mark the last 'X' is the winner.
// ---------------------------------------------------------------------------

#include "Strategy06.h"

Strategy06::Strategy06(){} // movesleft initialized to 0 from Strategy base class

//**********************************************
// MakeDecision() is strategy for the X out 
// game, where players either 'X' out 1, 2, or 3
// boxes in a 5x4 grid. With this strategy, it 
// utilizes a multiples of 4 trick. If going 
// second, the program forces the opponent 
// player to have moves left in multiples of 4.
// That way, at the end of the game, the opponent
// will have 4 moves left, which guarantees a win
// for the player that went second.
// Incoming Data: 
//		none
// Outgoing Data:
//		returns 1 if the move decision was 1
//		returns 2 if the move decision was 2
//		returns 3 if the move decision was 3
//**********************************************
int Strategy06::MakeDecision(void)
{
	int move; // used to store move decision
	
	switch(movesleft)
	{
		/* If going second, this will cause the other player to have moves left 
		in multiples of 4. This causes the second player to be guaranteed a win. 
		This is due to the fact that the game will always end where the first player 
		is left with 4 boxes, and no matter which move they make, the second player
		can X out 1, 2, or 3 boxes and win the game. For example, if movesleft is 19,
		then the move chosen will be 3, which results in 16 moves left (a multiple 
		of 4). */
		case 19: case 15: case 11: case 7: case 3:
			move = 3; 
			break; 
		case 18: case 14: case 10: case 6: case 2:
			move = 2; 
			break; 
		case 17: case 13: case 9: case 5: case 1:
			move = 1; 
			break;
		// for 20, 16, 12, 8, and 4 (multiples of 4), or invalid values
		/* The game cannot be won if the other player uses the same strategy. 
		   The first player is always going to lose if they have 4 spots left
		   to X out at the end of the game and they have moves left in multiples
		   of 4. */
		default:
			move = 2; // randomly chosen move number since the game is not winnable here
			break; 
	}
	
	return move;
}

//**********************************************
// ReceiveStatus() updates movesleft to 
// determine how many moves are left in the 4x5 
// grid.
// Incoming Data: 
//		Param 1: integer variable holding 
//			number of moves left
// Outgoing Data:
//		none
//**********************************************
void Strategy06::ReceiveStatus(int e)
{
	movesleft = e;
}

//**********************************************
// Reset() sets data members back to their 
// initial values; since none were added, 
// nothing is re-initialized.
// Incoming Data: 
//		none
// Outgoing Data:
//		none
//**********************************************
void Strategy06::Reset(){}

// for next project
int Strategy06::Tie(){return 17;}

string Strategy06::Name(){return "Strategy06's Strategy";}
