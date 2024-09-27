//----------------------------------------
// Chrysler Goshea
// CS255-02
// Daily HW 6
// 9/12/23
// This is the driver file to the 8ball.h header file it creates a menu to acces the methods
//-----------------------------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include "8ball.h"

using namespace std; 

int main()
{
	m8Ball mB; 
	int x; 
	string posAns;
	string negAns; 
	while(x != 3)
	{
		cout << "Your fate is at level: " << mB.fateScore() << "\n";
		cout << "Select from the following menu: " << "\n" << "	" << "1. Change your fate setting." << "\n" << "	 "
		<< "2. Shake the Magic 8 Ball." << "\n" << "	 "<< "3. Quit" << endl; 
		cin >> x; 
		if (x == 1)
		{
		//call method to change fate score
			mB.setFate();
		}
		//Call to method to shake 8ball 
		else if (x == 2)
		{
			mB.shake8Ball(); 
		}
		else if (x == 3)
		{
			mB.printAll(); //When uncommented calls method that shows total responses bad and good) 
			return 0; 
		}
		else 
		{
			cout << "ERROR invalid input. Choice set to one." << endl; 
			x = 1; 
		}
	}

}