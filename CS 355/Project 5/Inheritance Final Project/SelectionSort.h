//*********************************
//Referenced Greeks for Geeks
//*********************************
#include<iostream>
#include"Sorter.h"
template <class T>
class SelectionSort : public Sorter<T>
{
	public:
    SelectionSort(T* p, int s): Sorter<T>(p, s){}
    void Sort()const;
};
//************************************
//Incoming: nothing
//Outcoming: nothing
//Parameters: nothing
//*********************************************
template <class T>
void SelectionSort<T> ::Sort()const{
	int min_idx;

	for(int i = 0; i<this->size-1; i++){
		min_idx = i;
		for(int j=i+1;j<this->size;j++){
			this->counter++;
			if(this->access[j]<this->access[min_idx])
				min_idx = j;
		}
		if(min_idx != i){
			swap(this->access[min_idx], this->access[i]);
		}



	}

}
