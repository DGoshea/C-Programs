#include <iostream>
using namespace std;

template <class T>
class Sorter<T>{
    T* access;
    int size;
public:
    Sorter(T* p, int s);
    void Reset(T*p, int s);
    void Print()const;
    virtual void Sort()const = 0;
    void FillRandom()const;
    void FillInOrder()const;
    void FillReverse()const;
};

    template <class T>
    Sorter(T* p, int s)
    {
        access = p;
        size = s;
    }

    template <class T>
    void Reset(T* p, int s)
    {
        access = p;
        size = s;
        counter = 0;
    }

    template <class T>
    void Print() const
    {
        for(int i = 0; i < size; i++)
        {
            cout << access[i] << " ";
        }
    }

    template <class T>
    virtual void Sort() const = 0;

    template <class T>
    void FillRandom() const
    {
        for(int i = 0; i < size; i++)
        {
            access[i] = rand() % size;
        }
    }

    template <class T>
    void FillInOrder() const
    {
        for(int i = 0; i < size; i++)
        {
            access[i] = i;
        }

    }

    template <class T>
    void FillReverse() const
    {
        int n = 0;
        for(int i = size; i > 0; i--)
        {
            access[n] = i;
        }

    }

class MergeSort: public Sorter<T>
{
public:


};

class BubbleSort : public Sorter<T>
{
public:
    virtual void Sort();
};
    virtual void override Sort() const
    {
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; i++)
            {
                if(acces[j] > acces[j + 1])
                {
                    int temp = access[j];
                    access[j] = access[j+1];
                    access[j+1] = temp;
                    counter++;
                }
            }
        }
    }




template <class T>
class RadixSort : public Sorter
{
public:
    Sorter(T* p, int s)
    {
        access = new T[size];
        size = s;
    }
    void Reset(T* p, int s);
    void Print() const;
    virtual void Sort() const = 0;
    void FillRandom() const;
    void FillInOrder() const;
    void FillReverse() const;
};

int main()
{


return 0;
}
