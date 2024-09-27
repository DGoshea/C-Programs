/*
    File: Sorter.h
    Author: Jackson Ferrigno, Divine Goshea, and Jayden Green
    Date: 05/01/2024
    Description:
    Header file for BubbleSort class template which is a sorting algorithm, which is derived from Sorter class template.
    used GeeksForGeeks to help with bubble sort build
*/
#include "Sorter.h"
template <class T>
class BubbleSort : public Sorter<T>
{
public:
    /*
    Parametric constructor for BubbleSort class template.
    Parameters:
        p: Pointer to an array of type T
        s: Size of the array
    Outgoing Data:
        None
*/
    BubbleSort(T* p, int s): Sorter<T>(p, s){}
    /*
    Sorts an array of elements using bubble sort algorithm.
    Parameters:
        None
    Returns:
        None
*/
    void Sort()const;
};

template <class T>
void BubbleSort<T>:: Sort()const{
    for(int i=0; i < this->size-1; i++)
    {
        for(int j = 0; j < this->size-i-1; j++)
        {
            if(this->access[j] > this->access[j+1])
            {
                T temp = this->access[j];
                this->access[j] = this->access[j+1];
                this->access[j+1] = temp;
                this->counter++;
            }
        }
    }
}
