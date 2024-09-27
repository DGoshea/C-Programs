//----------------------------------------
// Chrysler Goshea
// CS255-02
// Daily HW 6
// 9/12/23
// This .h creates class of magic 8 ball with methods to change the fate, shake the 8 ball,
// return the response, and return fate score. This class also has a constructor that reads in 
// two txt files with the responses
//-----------------------------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
     
using namespace std; 

class m8Ball
{
	private: 
	const static int SIZE = 10; 
    string posAnswer[SIZE];
    string negAnswer[SIZE]; 
    int fate = 0; 


    public:
    string posAns;
    string negAns;
//---------------------------------------------------------------------------
/* fateScore() returns the fate score
*     INCOMING DATA: none
*     OUTGOING DATA: fate score */ 
	int fateScore(){
		return fate; 
	}
//Constructor that asks the user for both filenames and loads them into an array of strings 
// Also sets the fate score to 5		
	m8Ball()
	{
		string posFilename;
    	string negFilename; 
    	fate = 5; 
    	cout << "Enter the positive answer filename. " << endl; 
    	cin >> posFilename; 
    	//Confirms filename and loops to store strings into posAnswers array
    	if(posFilename == "positive.txt"){
    		int i = 0; 
        	ifstream posFile;
        	posFile.open(posFilename);
        	while(!posFile.eof()){
        		getline(posFile, posAnswer[i]);
        		i++;
        		//if(i == 10){
        		//	break;
			//	}
			}
			posFile.close();
		}
		
		cout << "\n";

		cout << "Enter the negative answer filename." << endl; 
    	cin >> negFilename; 
    	//Confirms negative filename and loop to store strings into neg answer array
    	if(negFilename == "negative.txt"){
    		int i = 0; 
			ifstream negFile;
			negFile.open(negFilename);
    		while(!negFile.eof()){
        		getline(negFile, negAnswer[i]);
        		i++;
        		if(i == 10){
        			break;
				}
			}
			negFile.close();
		}
		
    	cout << "\n";
    }
//---------------------------------------------------------------------------
/* setFate()  Allows the user to set the fate
*     INCOMING DATA: none
*     OUTGOING DATA: none; (changes variable fate)*/    
    void setFate()
	{
		cout << "Choose a fate between 1 & 10. (1 being the worst luck and 10 being the best luck)" << endl; 
        int newFate;
        cin >> newFate; 
        if(newFate < 1 || newFate > 10){
            cout << "Error invalid fate" << endl;
            newFate = 1; 
            newFate = fate; 
            cout << "Fate set to 1" << endl;
        }
        else
		{
        	fate = newFate;
        }
	}
//---------------------------------------------------------------------------
/* shake8Ball()  Simulates shaking the 8-ball and receiving a response and 
	and selects a random string and returns that string to main()
*     INCOMING DATA: none
*     OUTGOING DATA: string: negative or positive answer*/ 	
	void shake8Ball()
	{
		int num1, num2, num3; 
		unsigned seed; 
		seed = time(0);
		srand(seed); 
		
		//Generate 3 random numbers 0-9, 1-3, & 1 or 2
		num1 = (rand() % (9 - 0 + 1)) + 0;
		num2 = (rand() % (3 - 1 + 1)) + 1;
		num3 = (rand() % (2 - 1 + 1)) + 1; 
		cout << num1 << "\n";
		
		// Always be negative if fate is 1 
		if(fate == 1){
			cout << negAnswer[num1];
			cout << "\n";
		}
		//Always be positive if fate is 10
		else if (fate == 10){
			cout << posAnswer[num1];
			cout << "\n";
		}
		//66% Chance of positive if high fate
		else if (fate > 5 && fate < 10){
			if(num2 == 1 || num2 == 2){
				cout << posAnswer[num1];
				cout << "\n";
			}
			else if(num2 == 3){
				cout << negAnswer[num1];
				cout << "\n";
			}
		}
		//66% Chance of negative if low fate
		else if (fate > 0 && fate < 5)
		{
			if(num2 == 1 || num2 == 2)
			{
				cout << negAnswer[num1];
				cout << "\n";
			}
			else if(num2 == 3)
			{
				cout << posAnswer[num1];
				cout << "\n";
			}
		}
		// 50/50 chance if fate is 5 
		else if (fate == 5)
		{
			if (num3 == 1)
			{
				cout << negAnswer[num1];
				cout << "\n";
			}
			else if (num3 == 2)
			{
				cout << posAnswer[num1];
				cout << "\n";
			}
		}
		
	}
	
	void printAll()
	{
		cout << "POSITIVE RESPONSES: " << endl;
		for(int i = 0; i < SIZE; i++)
		{
			cout << posAnswer[i] << endl; 
		}
		cout << "\n";
		cout << "NEGATIVE RESPONSES: " << endl; 
		for(int i = 0; i < SIZE; i++)
		{
			cout << negAnswer[i] << endl; 
		}
	}
};