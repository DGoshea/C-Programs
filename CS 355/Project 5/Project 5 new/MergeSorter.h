#include "Sorter.h"
/// Merge sort
///****************
template <class T>
class MergeSorter: public Sorter<T>{
public:
    MergeSorter(T* a, int s): Sorter<T>(a,s){}
    void Sort() const;
private:
    void Merge(T* a, T* tmp, int left, int mid, int right)const;
    void MergeSort(T* a, T* tmp, int left, int right)const;
};

template <class T>
void MergeSorter<T>::Merge(T* a, T* tmp, int left, int mid, int right)const{
    int one = left;
    int two = mid;
    int tmpPos = left;

    while(one<mid && two <= right){
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
void MergeSorter<T>::Sort() const{
    T* tmp = new T[this->size];
    MergeSort(this->access, tmp, 0, this->size-1);
    delete[] tmp;
}

