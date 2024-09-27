#include <iostream> 
#include "scoreboard.h"
using namespace std; 

class Scoreboard
{ 
      private: 
      int p1Wins;
      int p2Wins; 
      int rockWins;
      int paperWins;
      int scisWins; 


      public: 
      Scoreboard()
      {
            p1Wins = 0; 
            p2Wins = 0; 
            rockWins = 0; 
            paperWins = 0; 
            scisWins = 0; 
      }

      showTtlWins()
      {
           cout << "Total Wins by Player: " << endl; 
           cout << "Player 1: " << p1Wins; 
           cout << "Player 2: " << p2Wins; 
      }

      
      showWinsByMove()
      {
            cout << "Total Wins By Move: " << endl; 
            cout << "Rock: " << rockWins
            cout << "Paper: " << paperWins; 
            cout << "Scissors: " << scissWins; 
      }
      
      recordResult(int p1, int p2)
      {
            if(p1 == 1 && p2 == 2){
                  p2Wins++;
                  paperWins++;
            }
            else if(p1 == 1 && p2 == 3){
                  p1Wins++;
                  rockWins++;
            }
            else if(p1 == 2 && p2 == 1){
                  p1Wins++;
                  paperWins++;
            }
            else if(p1 == 2 && p2 == 3){
                  p2Wins++;
                  scissWins++;
            }  
            else if(p1 == 3 && p2 == 1){
                  p2Wins++;
                  rockWins++;
            }
            else if(p1 == 3 && p2 == 2){
                  p1Wins++;
                  scissWins++;
            }
                
      }

      

};