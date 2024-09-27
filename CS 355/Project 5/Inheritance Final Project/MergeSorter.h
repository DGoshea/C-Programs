/*
    File: MergeSorter.h
    Author: Jayden Green, Divine Goshea, and Jackson Ferrigno
    Date: 05/01/2024

    Description:
    MergeSorter class template a divide and conquer sorting algorithm, which is derived from Sorter class template.
    Used merge sort from Dr. Jenkins implementation
*/


#include "Sorter.h"

template <class T>
class MergeSorter: public Sorter<T>{
public:
/*
    Parametric constructor for MergeSorter class template.
        Parameters:
            a: Pointer to an array of type T
            s: Size of the array
        Outgoing Data:
            None
    */
    MergeSorter(T* a, int s): Sorter<T>(a,s){}
        /*
        Sorts an array of elements using merge sort algorithm.
        Parameters:
            None
        Returns:
            None
    */
    void Sort()const;
private:
    /*
        Merges two sorted subarrays.

        Parameters:
            a: Pointer to an array of type T
            tmp: Temporary array to store merged subarrays
            left: Starting index of the first subarray
            mid: Ending index of the first subarray
            right: Ending index of the second subarray

        Returns:
            None
    */
    void Merge(T* a, T* tmp, int left, int mid, int right)const;
     /*
        Recursively sorts subarrays using merge sort algorithm.

        Parameters:
            a: Pointer to an array of type T
            tmp: Temporary array to store merged subarrays
            left: Starting index of the subarray to be sorted
            right: Ending index of the subarray to be sorted

        Returns:
            None
    */

    void MergeSort(T* a, T* tmp, int left, int right)const;
};

template <class T>
void MergeSorter<T>::Merge(T* a, T* tmp, int left, int mid, int right)const{
    int one = left;
    int two = mid;
    int tmpPos = left;

    while(one<mid && two <= right){
    	this->counter++;
        if(a[one] < a[two])
            tmp[tmpPos++] = a[one++];
        else
            tmp[tmpPos++] = a[two++];
    }

    while(one < mid)
        tmp[tmpPos++] = a[one++];
    while(two<=right)
        tmp[tmpPos++] = a[two++];

    for(int x = left; x<=right; x++){
        a[x] = tmp[x];
    }
}

template <class T>
void MergeSorter<T>::MergeSort(T* a, T* tmp, int left, int right)const{
    if(left < right){
        int mid = (left + right) / 2;
        MergeSort(a, tmp, left, mid);
        MergeSort(a, tmp, mid+1, right);
        Merge(a, tmp, left, mid+1, right);
    }
}

template <class T>
void MergeSorter<T>::Sort()const{
    T* tmp=new T[this->size];
    MergeSort(this->access, tmp, 0, this->size-1);
    delete[] tmp;
}
