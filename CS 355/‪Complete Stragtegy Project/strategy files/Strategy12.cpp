#include "Strategy12.h"

Strategy12::Strategy12(){}

int Strategy12::MakeDecision(void){
	int decision = 0;
	
	if(movesleft == 20)
		return 3;
	// makes sure that you win at the very end
	else if(movesleft == 5)
		return 2;
	else if(movesleft == 4)
		return 1;
	else if(movesleft <= 3)
		return movesleft;
	//kind of mirrors whats going on
	else if(movesleft%2 == 0)
		return 2;
	else if(movesleft%3==0)
		return 3;
	//fail safe
	return 1;
}

void Strategy12::ReceiveStatus(int e){movesleft = e;}

void Strategy12::Reset(){}

int Strategy12::Tie(){return 15;}

string Strategy12::Name(){return "Strategy12's Strategy";}