#include "Strategy24.h"
#include <iostream>

// Constructor
Strategy24::Strategy24() : Strategy() {}

int Strategy24::MakeDecision() {
    // Adjust strategy if starting the game
    if (movesleft == 20) { // Assuming 20 is the total moves at the start, adjust as needed
        return 3; // Force the opponent into a non-multiple of 4 position
    } else if (movesleft % 4 == 0) {
        return 3; // Adjusted to always aim for a strong strategic position
    } else {
        // Aim to leave a multiple of 4
        return movesleft % 4;
    }
}


// Receive the current status of the game
void Strategy24::ReceiveStatus(int e) {
    movesleft = e;
}

// Reset the strategy for a new game
void Strategy24::Reset() {
    movesleft = 20; // Assuming a starting game of 20 moves, adjust based on actual game setup
}

// Method to handle ties (if applicable)
int Strategy24::Tie() {
    return 8; // Placeholder value, adjust based on game rules
}

// Return the name of the strategy
std::string Strategy24::Name() {
    return "Strategy24's Strategy";
}