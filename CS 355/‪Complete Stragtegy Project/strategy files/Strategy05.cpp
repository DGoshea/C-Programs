#include "Strategy05.h"

Strategy05::Strategy05(){}

int Strategy05::MakeDecision() {
    if (movesleft <= 3) {
        return movesleft;
    }

    if (movesleft % 4 == 0) {
        return 3;
    } else if (movesleft % 4 == 1) {
        return 1;
    } else {
        return 2;
    }
}


void Strategy05::ReceiveStatus(int e){movesleft = e;}

void Strategy05::Reset(){}

int Strategy05::Tie(){return 10;}

string Strategy05::Name(){return "Strategy05's Strategy";}