#include "Strategy13.h"

Strategy13::Strategy13(){}

int Strategy13::MakeDecision(void){
	
int dec;
//Goes first
if(movesleft==20)
{
	if(movesleft==15||movesleft==11||movesleft==7)
	{
		dec= 3;
	}
	else if(movesleft==18||movesleft==14||movesleft==10||movesleft==6)
	{
		dec= 2;
	}
	else if(movesleft==20||movesleft==17||movesleft==13||movesleft==9||movesleft==5||movesleft==1)
	{
		dec= 1;
	}
}
else
{
	if(movesleft==19||movesleft==15||movesleft==11||movesleft==7)
	{
		dec= 3;
	}
	else if(movesleft==18||movesleft==14||movesleft==10||movesleft==6)
	{
		dec= 2;
	}
	else if(movesleft==17||movesleft==13||movesleft==9||movesleft==5||movesleft==1)
	{
		dec= 1;
	}
}
	return dec;
}

void Strategy13::ReceiveStatus(int e){movesleft = e;}

void Strategy13::Reset(){}

int Strategy13::Tie(){return 33;}

string Strategy13::Name(){return "Strategy13's Strategy";}