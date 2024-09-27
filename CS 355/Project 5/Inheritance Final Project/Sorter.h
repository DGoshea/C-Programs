//************************************
//Base Class
//Only added a getter for the counter and changed data
//members to protected
//*********************************************
#ifndef SORTER_H
#define SORTER_H

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template <class T>
class Sorter
{
protected:
    mutable int counter;//Referenced Geeks for Geeks
    T *access;
    int size;

public:
    Sorter(T *p, int s);
    void Reset(T *p, int s);
    void Print() const;
    virtual void Sort() const = 0;
    void FillRandom() const;
    void FillInOrder() const;
    void FillReverse() const;
    int getCounter()const;//Only added function
};
//************************************
//Incoming: array, size of array
//Outcoming: nothing
//Parameters: p, s
//*********************************************
template <class T>
Sorter<T>::Sorter(T *p, int s)
{
    access = p;
    size = s;
    counter=0;
}
//************************************
//Incoming: array, size of array
//Outcoming: nothing
//Parameters: p, s
//*********************************************
template <class T>
void Sorter<T>::Reset(T *p, int s)
{
    access = p;
    size = s;
    counter = 0;
}
//************************************
//Incoming: nothing
//Outcoming: nothing
//Parameters: nothing
//*********************************************
template <class T>
void Sorter<T>::FillRandom() const
{
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        access[i] = rand() % size;
    }
}
//************************************
//Incoming: nothing
//Outcoming: nothing
//Parameters: nothing
//*********************************************
template <class T>
void Sorter<T>::FillInOrder() const
{
    for (int i = 0; i < size; i++)
    {
        access[i] = i;
    }
}
//************************************
//Incoming: nothing
//Outcoming: nothing
//Parameters: nothing
//*********************************************
template <class T>
void Sorter<T>::FillReverse() const
{
    for (int i = size - 1, j = 0; i >= 0; i--, j++)
    {
        access[j] = i;
    }
}
//************************************
//Incoming: nothing
//Outcoming: nothing
//Parameters: nothing
//*********************************************
template <class T>
void Sorter<T>::Print() const
{
    for (int i = 0; i < size; i++)
    {
        cout << access[i] << " ";
    }
    cout << endl;
}
//************************************
//Incoming: nothing
//Outcoming: counter
//Parameters: nothing
//*********************************************
template<class T>
int Sorter<T>::getCounter()const{
	return counter;
}

#endif // SORTER_H
