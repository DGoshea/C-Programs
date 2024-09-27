//----------------------------------------
// Chrysler Goshea
// CS255-02
// Daily HW 5
// 9/7/23
// This program will ask the user to choose a number of games to play
// rock, paper, scissors using methods from class Scoreboard to record
// the total wins for each player and total wins by which object. 
//----------------------------------------
#include <iomanip>
#include "scoreboard.h"

using namespace std; 

int main(){
	//Initialize sB as an object of Scoreboard class
	Scoreboard sB;
	int x; 
	int y; 
	int z; 
	cout << "How many games would you like to play? " << endl; 
	cin >> x; 
	//For loop for each game  
	for(int i = 0; i < x; i++){
		cout << "What did player 1 play? Enter 1 for rock, 2 for paper, 3 for scissors." << endl; 
		cin >> y; 
		cout << "What did player 2 play? Enter 1 for rock, 2 for paper, 3 for scissors." << endl; 
		cin >> z; 
		sB.recordResult(y,z);
	}
	sB.showTtlWins();
	cout << endl; 
	sB.showWinsByMove(); 
}