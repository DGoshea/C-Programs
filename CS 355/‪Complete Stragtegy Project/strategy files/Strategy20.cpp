// StrategyX.cpp

#include "Strategy20.h"

Strategy20::Strategy20() {
    // Initialize any necessary members
}

int Strategy20::MakeDecision() {
    // If the current total is even, cross off 2 boxes to make it odd
    if (movesleft % 2 == 0) {
        return 2;
    } else {
        // If the current total is odd, cross off 1 box to keep it odd
        return 1;
    }
}

void Strategy20::ReceiveStatus(int totalBoxes) {
    movesleft = totalBoxes;
    // Update internal state based on the totalBoxes information received
    // You may need to keep track of the opponent's moves and adapt your strategy accordingly
}

void Strategy20::Reset() {
    // Reset any necessary members
    movesleft = 0;
}

int Strategy20::Tie() {
    return 7;  // Indicate a win for the opponent in case of a tie
}

string Strategy20::Name() {
    return "Strategy20's Strategy";
}
