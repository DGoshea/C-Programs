#include "Strategy19.h"

Strategy19::Strategy19() {
    // Add any initialization if needed
}

int Strategy19::MakeDecision(void) {
    // The winning strategy is to leave the opponent with a multiple of 4 boxes.
    // Whenever the opponent crosses off 'n' boxes, this strategy will cross off
    // (4 - n) boxes to leave the opponent with a multiple of 4.
    // This ensures that ultimately, we are the one to cross off the last box.

    // ReceiveStatus call to update the current state
    // Check the current number of boxes remaining
    if (movesleft % 4 == 0) {
        // If the opponent left a multiple of 4 boxes, we'll leave another multiple of 4
        return 3; // Cross off 3 boxes
    } else {
        // Else calculate how many boxes to cross off to leave a multiple of 4
        int remaining = movesleft % 4;
        return remaining;
    }
}

void Strategy19::ReceiveStatus(int e) {
    // Update the number of boxes left
    movesleft = e;
}

void Strategy19::Reset() {
}

int Strategy19::Tie() {
    return 5;
}

string Strategy19::Name() {
    // Return the name of Strategy
    return "Strategy19's Strategy";
}
