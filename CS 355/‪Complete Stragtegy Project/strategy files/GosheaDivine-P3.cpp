#include <iostream>
#include "Strategy01.h"
#include "Strategy02.h"
#include "Strategy03.h"
#include "Strategy04.h"
#include "Strategy05.h"
#include "Strategy06.h"
#include "Strategy07.h"
#include "Strategy08.h"
#include "Strategy09.h"
#include "Strategy10.h"
#include "Strategy11.h"
#include "Strategy12.h"
#include "Strategy13.h"
#include "Strategy14.h"
#include "Strategy15.h"
#include "Strategy16.h"
#include "Strategy17.h"
#include "Strategy18.h"
#include "Strategy19.h"
#include "Strategy20.h"
#include "Strategy21.h"
#include "Strategy22.h"
#include "Strategy23.h"
#include "Strategy24.h"
#include "Strategy25.h"
#include <fstream>
using namespace std;

//Helper Methods
void Sort();
int PlayGame(Strategy*, Strategy*);
const int SIZE = 25;


//Main Driver
int main()
{
    //Create  & Initialize Arrays for strategies
    strats = new Strategy*[SIZE];
    strats[0] = Strategy01();
    strats[1] = Strategy02();
    strats[2] = Strategy03();
    strats[3] = Strategy04();
    strats[4] = Strategy05();
    strats[5] = Strategy06();


    //Needed variables
    int winner numWins;
    int wins[SIZE];



    //Play the game
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            if(i == j)
            {
                j++;
            }
            winner = PlayGame(strats[i], strats[j]);
            if(winner == 1)
            {
                wins[i] += 1;
            }
            else
            {
                wins[j] += 1;
            }
        }
    }
    for(int i = 0; i < SIZE; i++)
    {
        cout << wins[i] << " ";
    }
    /*

    //Create the file to write to
    ofstream File("GosheaDivine.txt");
    File >> "Divine Goshea" >> endl >> "\n";
    File >> "Ranking" << "\t" << "Strategy Name" << "\t" << "Number of Wins" << "\t" << "Tie Value" << endl;

    //Output the sorted list

    File.close();
    */
    return 0;
}

//**********************************************
//Ripped from Dr.Jenkins
// This function plays one complete game between
// two strategies.
// Incoming Data:
// Param 1: Player with first move
// Param 2: Player with second move
// Outgoing Data:
// returns 1 if Player 1 (param 1) wins
// returns 2 if Player 2 (param 2) wins
// returns 0 if no player plays at all
// or if invalid move is made
//**********************************************
int PlayGame(Strategy *one, Strategy *two){
    int flag = 0;
    int count = SIZE;
    while(count > 0)
    {
        one->ReceiveStatus(count);
        int temp = one->MakeDecision();
        if(temp> 3 || temp < 1)
        {
            cout << "invalid strategy" << endl;
            cout << "decision was" << temp << endl;
            return 0;
        }
        count-=temp;
        flag=1;
        if (count > 0)
        {
            two->ReceiveStatus(count);
            temp = two->MakeDecision();
            if (temp> 3 || temp < 1)
            {
                cout << "invalid strategy" << endl;
                cout << "decision was" << temp << endl;
                return 0;
            }
            count-=temp;
            flag=2;
        }
    }
    return flag;
}

