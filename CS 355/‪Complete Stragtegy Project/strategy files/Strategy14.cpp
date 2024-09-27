#include "Strategy14.h"
Strategy14::Strategy14() { remaning = 0; }
int Strategy14::MakeDecision(void) {
	while (remaning <= 12 || remaning <= 13)
	{
		return 3;
	}
	if (remaning == 13)
	{
		return 3;
	}
	else if (remaning == 12 || remaning == 11) {
		return 2;
	}
	else {
		return 1;
	}
}
void Strategy14::ReceiveStatus(int e) { remaning = e; }
void Strategy14::Reset() { movesleft = 20; }
int Strategy14::Tie() { return 16; }
string Strategy14::Name() { return "Strategy14's Strategy"; }
