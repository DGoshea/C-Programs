#include "Strategy10.h"
#include <cstdlib>
#include <ctime>
// initialize total boxes to 20
Strategy10::Strategy10() : totalBoxes(20) {
    srand(time(nullptr));
}
/* This strategy works as followed:
if I go first: random number
if I go second, every round (my opponent + me) will equal 4
example if my opponent places 3 x's, I will put down 1. If they do 2, I do 2, if they do 1, I do 3
If I go second I will win every time
*/


int Strategy10::MakeDecision() {
    if (movesleft == 0) {
        movesleft = rand() % 3 + 1;
        return movesleft;
    } else {
        int opponentMove = 4 - movesleft;
        int myMove;
        if (opponentMove == 1) {
            myMove = 3;
        } else if (opponentMove == 2) {
            myMove = 2;
        } else {
            myMove = 1;
        }
        totalBoxes -= myMove;
        return myMove;
    }
}

void Strategy10::ReceiveStatus(int e){movesleft = e;}

void Strategy10::Reset(){totalBoxes=20;}

int Strategy10::Tie(){return 18;}

string Strategy10::Name(){return "Strategy10's Strategy";}
