#include <iostream>
#include "Sorter.h"
#include "BubbleSort.h"
#include "MergeSorter.h"
int main() {
    const int size = 10;
    int arr[size];

    cout << "********** Bubble Sort ********** " << endl;
    BubbleSort<int> Sorter(arr, size);

    cout << "Random Array: ";
    Sorter.FillRandom();
    Sorter.Print();

    cout << "Sorted Array: ";
    Sorter.Sort();
    Sorter.Print();
    cout << "Bubble Sort Made: " << Sorter.getCounter() << " comparisons";

    cout << "\n" << endl;

    cout << "********** Merge Sort *********** " << endl;
    MergeSorter<int> MSorter(arr, size);

    cout << "Random Array: ";
    MSorter.FillRandom();
    MSorter.Print();

    cout << "Sorted Array: ";
    MSorter.Sort();
    MSorter.Print();
    cout << "Merge Sort Made: "; //<< comparisonvariable << "comparisons" << endl;

    return 0;
}
