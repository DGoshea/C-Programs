// ---------------------------------------------------------------------------

// Description: This program aims to utilize a strategy to win a game in a 5x4 grid by entering 1 to 3.
//				By filling in the last space, we take the win. Therefore, our startegy revolves around
//				filling in the last space.
// ---------------------------------------------------------------------------
#include "Strategy15.h"
#include <stdlib.h>

//---------------------------------------------------------------------------
/* StrategyX() is a constructor of the StrategyX() class. It initializes no local attribute, as there is no attribute within StrategyX's class.
 * But it initializes the default constructor of parent class Strategy.
 *     INCOMING DATA: None.
 *     OUTGOING DATA: None. No attributes are initialized because of lack of attributes.
 */
Strategy15::Strategy15(){}

//---------------------------------------------------------------------------
/* MakeDecision() is a method of the StrategyX() class. It returns a value between 1 and 3 inclusive, number of 'X's to enter into the grid.
 *     INCOMING DATA: None.
 *     OUTGOING DATA: Integer between 1 to 3 inclusive. This is the number of 'X's to put into the grid.
 */
int Strategy15::MakeDecision(void)
{
	// The strategy is based on the number 4, which is the addition of 3 and 1. 3 represents the maximum input and 1 represents the minimum input.
	// Therefore, by focusing on keeping the number of empty spots in the grid at multiples of 4, we can achieve victory if we go second. Thus, even
	// if the opponent goes for the maximum or minium input, we can fill in our own values to keep it a value of 4 to obtain victory. This also works
	// with this grid as the total number of spaces in this grid is a multiple of 4.

	if(movesleft%4==0)	//If the number of moves left is a multiple of 4, this executes.
	{
		return rand()%3 +1;	//Returns a random value between 1 and 3 inclusive as it doesn't matter and we will try to make it multiples of 4 in future moves.
	}

	else	//If the number of moves left is not a multiple of 4, this executes. This is done to give a complement of 4 to maintain a multiple of 4.
	{
		return(movesleft%4);	//This returns a number which will reduce the number of free spaces to become a multiple of 4.
	}
}

//---------------------------------------------------------------------------
/* ReceiveStatus(int) is a method of the StrategyX() class. It returns a value between 1 and 3 inclusive, number of 'X's to enter into the grid.
 *     INCOMING DATA: Integer for number of spaces left in the grid.
 *     OUTGOING DATA: None. The attribute movesleft is set to the input, which is the number of free spaces left in the grid.
 */
void Strategy15::ReceiveStatus(int e)
{
	movesleft = e;	//movesleft is set to the number of free spaces left in the grid.
}

//---------------------------------------------------------------------------
/* Reset() is a method of the StrategyX() class. It resets the attributes of class StrategyX to default.
 *     INCOMING DATA: None.
 *     OUTGOING DATA: None. The attributes of class StrategyX is set to default.
 */
void Strategy15::Reset(){}

//---------------------------------------------------------------------------
/* Tie() is a method of the StrategyX() class. It returns a value to say whether a game is a tie or not.
 *     INCOMING DATA: None.
 *     OUTGOING DATA: Integer value which determines whether a game is a tie or not.
 */
int Strategy15::Tie(){return 9;}

//---------------------------------------------------------------------------
/* Name() is a method of the StrategyX() class. It returns a string saying X's Strategy.
 *     INCOMING DATA: None.
 *     OUTGOING DATA: A string which says X's Strategy.
 */
string Strategy15::Name(){return "Strategy15's Strategy";}
