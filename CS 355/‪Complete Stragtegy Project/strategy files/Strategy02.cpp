#include "Strategy02.h"
#include "DefaultStrategy.h"
Strategy02::Strategy02(){}

int Strategy02::MakeDecision(void){

	if(movesleft <= 20) //go first
		return 2;
	else if(movesleft >=10)
	{
		return 1;
	}
	else
		return 3;
}

void Strategy02::ReceiveStatus(int e)
{
	movesleft = e;
	
}

void Strategy02::Reset()
{

}

int Strategy02::Tie(){return 9;}

string Strategy02::Name(){return "Strategy02's Strategy";}