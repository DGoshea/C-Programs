
#include "Strategy22.h"

Strategy22::Strategy22(){}
int Strategy22::MakeDecision(void){
	if(movesleft<=3){
		return movesleft;
	}
	if(movesleft==4){
		return 1;
	}
	if(movesleft >=5 && movesleft <=7){
		return movesleft-4;
	}
	else{
		return 2;
	}
		
}

/* Method for finding above algorithm: I noticed that if game reaches last row,
	and the last row is empty, the best move to take is filling the first square
	so, this explains the first if statement. I then followed up the second row 
	and attempted to determin what move for each position would land myself on the
	fifth row whilst keeping the fifth row empty, explaining the two proceeding
	if statements. 
*/

/* That is to say, my strategy is to ensure I am in a position to play one square(move)
   when there are but 5 squares(moves) left.
*/

void Strategy22::ReceiveStatus(int e){movesleft = e;}

void Strategy22::Reset(){}

int Strategy22::Tie(){return 13;}

string Strategy22::Name(){return "Strategy22's Strategy";}