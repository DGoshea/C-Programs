#include "Strategy23.h"

Strategy23::Strategy23(){}

int Strategy23::MakeDecision(void){
	
	if (movesleft == 20)
		return 3;
	
	else if (movesleft % 2 == 1)
		return 1;
		
	else if (movesleft % 2 == 0)
		return 2;
}

void Strategy23::ReceiveStatus(int e){
	movesleft = e;
}

void Strategy23::Reset(){}

int Strategy23::Tie(){return 7;}

string Strategy23::Name(){return "Strategy23's Strategy";}
