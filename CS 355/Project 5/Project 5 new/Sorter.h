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
    mutable int counter;
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
    int getSize();
    int getCounter();
};

template <class T>
Sorter<T>::Sorter(T *p, int s)
{
    access = p;
    size = s;
    counter=0;
}
template <class T>
void Sorter<T>::Reset(T *p, int s)
{
    access = p;
    size = s;
    counter = 0;
}
template <class T>
void Sorter<T>::FillRandom() const
{
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        access[i] = rand() % size;
    }
}
template <class T>
void Sorter<T>::FillInOrder() const
{
    for (int i = 0; i < size; i++)
    {
        access[i] = i;
    }
}
template <class T>
void Sorter<T>::FillReverse() const
{
    for (int i = size - 1, j = 0; i >= 0; i--, j++)
    {
        access[j] = i;
    }
}
template <class T>
void Sorter<T>::Print() const
{
    for (int i = 0; i < size; i++)
    {
        cout << access[i] << " ";
    }
    cout << endl;
}
template <class T>
int Sorter<T>::getSize()
{
    return size;
}
template<class T>
int Sorter<T>::getCounter(){
return counter;
}

#endif // SORTER_H
