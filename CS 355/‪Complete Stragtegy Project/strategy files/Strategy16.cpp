#include "Strategy16.h"

Strategy16::Strategy16(){}

int Strategy16::MakeDecision(void){
	return 1;
}

void Strategy16::ReceiveStatus(int e){movesleft = e;}

void Strategy16::Reset(){}

int Strategy16::Tie(){return 2;}

string Strategy16::Name(){return "Strategy16's Strategy";}