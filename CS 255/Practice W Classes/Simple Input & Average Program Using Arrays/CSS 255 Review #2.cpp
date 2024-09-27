//CHrysler Goshea | CSS 255 | Review #2 | 8/20/23
#include <iostream>
using namespace std; 

//Function
void displayLargerThanMean(double ar[], int numGrades, double& avg, int& dummy);

int main(){
//VARIABLES
	int numGrades;
	int dummy; 
	double number = 0; 
	double ar[30];
	double avg; 
	
//INPUT
	cout << "How many numbers would you like to input? (No more than 30)" << endl; 
	cin >> numGrades;
	
	cout << "Enter your numbers: " << endl; 
	for (int i = 0; i < numGrades; i++){
		cin >> ar[i]; 
	}
	
	displayLargerThanMean(ar, numGrades, avg, dummy); 
	
//OUTPUT
	cout << "Mean: " << avg << endl; 
	cout << "Numbers larger than the mean: " << dummy; 
	
	
	return 0; 
}

void displayLargerThanMean(double ar[], int numGrades, double& avg, int& dummy){
//VARIABLES	
	double sum = 0;
	int count = 0; 
	
//MATHS
	for (int i=0; i < numGrades; ++i){
		sum += ar[i]; 
	}
	
	avg = double(sum) / numGrades;

//NumGreaterThanMean
	for (int i = 0; i < numGrades; ++i){
		if (ar[i] > avg){
			++count;
			dummy = count; 
		}
	}
	
	return ;
	
}