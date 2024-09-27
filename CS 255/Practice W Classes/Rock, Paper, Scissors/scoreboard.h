#include <iostream>
#include <iomanip>
using namespace std; 

class Scoreboard
{ 
      private: 
      int p1Wins;
      int p2Wins; 
      int rockWins;
      int paperWins;
      int scissWins; 


      public:
//---------------------------------------------------------------------------
/* Scoreboard() is a constrcutor that sets the wins equal to zero 
*     INCOMING DATA: none
*     OUTGOING DATA: none */ 
      Scoreboard()
      {
            p1Wins = 0; 
            p2Wins = 0; 
            rockWins = 0; 
            paperWins = 0; 
            scissWins = 0; 
      }
//---------------------------------------------------------------------------
/* showTtlWIns() prints the amount of wins for each player
*     INCOMING DATA: none
*     OUTGOING DATA: none 	*/
      void showTtlWins()
	  {
	  	cout << "Total Wins by Player: " << endl; 
        cout << setw(10) <<  "Player 1: " << p1Wins << endl; 
        cout << setw(10) << "Player 2: " << p2Wins << endl; 
      }

//---------------------------------------------------------------------------
/* showWinsByMove() show the total wins by each move
*     INCOMING DATA: none
*     OUTGOING DATA: none 	*/
      void showWinsByMove()
      {
        cout << "Total Wins By Move: " << endl; 
        cout << "Rock: " << rockWins << endl;
        cout << "Paper: " << paperWins << endl; 
        cout << "Scissors: " << scissWins << endl; 
      }
//---------------------------------------------------------------------------
/* recordResult() is the logic behind the game rock, paper, scissors
*  will also keep track of the win from ach player and move
*     INCOMING DATA: two integers(player 1 & 2's moves)
*     OUTGOING DATA: none */      
      void recordResult(int p1, int p2)
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