/*----------------------------------------------------------------------------------------------*
																	    *
 * Program:		Strategy for a game with a grid of 4x5. The last player to mark off a box wins. *
 *----------------------------------------------------------------------------------------------*/

#include "Strategy25.h"
#include <cstdlib>

Strategy25::Strategy25(){}

int Strategy25::MakeDecision(void) 
{
    //cout << "Moves Left: " << movesleft << endl; 

    if (movesleft % 4 == 0) //Return a random number if the opponent goes first as if they have the same strategy there is no point and if they do not it will eventually go into the other checks
    {
    	//cout << "S: // 0, 1" << endl;
		return rand()%3 + 1;
	}
    if (movesleft % 4 == 1) // Return 3 if the remainder is 1
    {
    	//cout << "OPE: 1 // 3" << endl;
		return 3;
	}
    if (movesleft % 4 == 2) //Return 2 is the remainder is 2
    {
    	//cout << "OPE: 2 // 2" << endl;
		return 2;
	}    
	if (movesleft % 4 == 3) //Return 1 if the remainder is 3
    {
		//cout << "OPE: 3 // 1" << endl;
		return 1;
	}
	
	//cout << "Shouldn't reach here" << endl; 
	return 1; //The program should not reach here // it is here just in case
}

void Strategy25::ReceiveStatus(int e){movesleft = e;}

void Strategy25::Reset(){}

int Strategy25::Tie(){return 17;}

string Strategy25::Name(){return "Strategy25's Strategy";}
