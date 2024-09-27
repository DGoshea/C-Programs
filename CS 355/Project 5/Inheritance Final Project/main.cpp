//**********************************
//Project 5
//Jackson, Jayden, Divine
//**********************************
#include <iostream>
#include "Sorter.h"
#include "BubbleSort.h"
#include "MergeSorter.h"
#include "SelectionSort.h"
int main() {
     int size = 1;

    //Bubble Sort Insantiation
    cout<<"Bubble Sort:"<<endl;
    for(int i=0; i<4;i++){
    	size*=10;
    	int arr[size];
    	Sorter<int> * s1 = new BubbleSort<int>(arr,size);
    	s1->FillRandom();
    	s1->Sort();
    	cout << "Size:"<<size<<endl;
		cout<< "Random Comparisons:"<<s1->getCounter()<<endl;
		s1->Reset(arr,size);
		s1->FillInOrder();
		s1->Sort();
		cout<<"InOrder Comparisons: "<<s1->getCounter()<<endl;
		s1->Reset(arr,size);
		s1->FillReverse();
		s1->Sort();
		cout<<"Reverse Comparisons: "<<s1->getCounter()<<endl;
	}

	//Merge Sort Instantiation
	cout<<endl<<"MergeSort:"<<endl;
	size=1;//resets after each use
	for(int i=0; i<4;i++){
    	size*=10;
    	int arr[size];
    	Sorter<int> * s1 = new MergeSorter<int>(arr,size);
    	s1->FillRandom();
    	s1->Sort();
    	cout << "Size:"<<size<<endl;
		cout<< "Random Comparisons:"<<s1->getCounter()<<endl;
		s1->Reset(arr,size);
		s1->FillInOrder();
		s1->Sort();
		cout<<"InOrder Comparisons: "<<s1->getCounter()<<endl;
		s1->Reset(arr,size);
		s1->FillReverse();
		s1->Sort();
		cout<<"Reverse Comparisons: "<<s1->getCounter()<<endl;
	}

	//Selection Sort Instantion
	cout<<endl<<"Selection Sort:"<<endl;
	size=1;
	for(int i=0; i<4;i++){
    	size*=10;
    	int arr[size];
    	Sorter<int> * s1 = new SelectionSort<int>(arr,size);
    	s1->FillRandom();
    	s1->Sort();
    	cout << "Size:"<<size<<endl;
		cout<< "Random Comparisons:"<<s1->getCounter()<<endl;
		s1->Reset(arr,size);
		s1->FillInOrder();
		s1->Sort();
		cout<<"InOrder Comparisons: "<<s1->getCounter()<<endl;
		s1->Reset(arr,size);
		s1->FillReverse();
		s1->Sort();
		cout<<"Reverse Comparisons: "<<s1->getCounter()<<endl;
	}


    return 0;
}
