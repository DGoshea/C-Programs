#include "Strategy17.h"

Strategy17::Strategy17() : Strategy() {}

int Strategy17::MakeDecision(void) {
    if (movesleft % 4 == 0) return 3;
    else return movesleft % 4;
}

void Strategy17::ReceiveStatus(int e) {
    movesleft = e;
}

void Strategy17::Reset() {
    Strategy::Reset(); 
}

int Strategy17::Tie() {
    return 0; 
}

string Strategy17::Name() {
    return "Strategy17's Strategy";
}
