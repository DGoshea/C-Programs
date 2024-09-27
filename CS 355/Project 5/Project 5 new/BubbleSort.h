#include "Sorter.h"
/// Bubble sort
///****************
template <class T>
class BubbleSort : public Sorter<T>
{
public:
    BubbleSort(T* p, int s): Sorter<T>(p, s){}
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
