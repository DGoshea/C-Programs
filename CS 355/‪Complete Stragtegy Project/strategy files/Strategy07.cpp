#include "Strategy07.h"

Strategy07::Strategy07(){}

int Strategy07::MakeDecision(void){
	
	// This strategy attempts to make movesleft a multiple of 4. 
	// It is impossible to lose if you can make the movesleft equal 4, 8, 12, or 16 on your turn.
	// You cannot lose if you are the second player with this strategy, and the only strategy that beats
	// this one is itself. 
	
	if (movesleft % 4 == 3 || movesleft % 4 == 0){
		return 3;
	}
	else if (movesleft % 4 == 2){
		return 2;
	}
	else if (movesleft % 4 == 1){
		return 1;	
	}
}

void Strategy07::ReceiveStatus(int e){movesleft = e;}

void Strategy07::Reset(){}

int Strategy07::Tie(){return 100;}

string Strategy07::Name(){return "Strategy07's Strategy";}