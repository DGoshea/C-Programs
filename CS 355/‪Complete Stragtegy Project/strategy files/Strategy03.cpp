#include "Strategy03.h"

Strategy03::Strategy03(){}

// Strategy in English - If I am at a point to win the game, win the game. Otherwise, I am just marking off 1. This strategy performs well when playing against my pseudo-default strategy (I have a mac), which checks how far the moves remaining is from being a multiple of 4 and complements accordingly. 
int Strategy03::MakeDecision(void){
  if (movesleft == 1)
    return 1 ;
  if (movesleft == 2) 
    return 2;
  if (movesleft == 3)
    return 3 ;
  else 
    return 1 ;
    
}

void Strategy03::ReceiveStatus(int e){
  movesleft = e;
}

void Strategy03::Reset(){}

int Strategy03::Tie(){return 9;}

string Strategy03::Name(){return "Strategy03's Strategy";}