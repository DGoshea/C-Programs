#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>
using namespace std;
template <typename T>
class minHeap {
private:
    T* heapArray; // Pointer to the elements in the array
    int allocationSize; // Max size
    int heapSize; // Number of elements actually in the heap

    void ResizeArray() {
        int newAllocationSize = allocationSize * 2;
        T* newArray = new T[newAllocationSize];
        if (newArray) {
            // Copy from existing array to new array
            for (int i = 0; i < allocationSize; i++) {
                newArray[i] = heapArray[i];
            }

            // Delete old array and set pointer to new
            delete[] heapArray;
            heapArray = newArray;

            // Update allocation size
            allocationSize = newAllocationSize;
        }
    }

public:
        minHeap() {
        allocationSize = 1;
        heapArray = new T[allocationSize];
        heapSize = 0;

    }

    minHeap(int size) { // Parametric constructor to pass in size
        allocationSize = size;
        heapArray = new T[allocationSize];
        heapSize = 0;
    }

    virtual ~minHeap() {
        delete[] heapArray;
    }

    void PercolateUp(int node) {
        while (node > 0) {
            int parent = (node - 1) / 2; // Find parent node
            // Check to see if it violates min-heap property
            if (heapArray[node] >= heapArray[parent]) {
                return;
            } else {
                // Swap the two
                T temp = heapArray[node];
                heapArray[node] = heapArray[parent];
                heapArray[parent] = temp;

                node = parent;
            }
        }
    }

    void PercolateDown(int nodeIndex) {
        int childIndex = 2 * nodeIndex + 1;
        T value = heapArray[nodeIndex];

        while (childIndex < heapSize) {
            // Find the minimum among the node and all the node's children
            T minValue = value;
            int minIndex = -1;
            for (int i = 0; i < 2 && i + childIndex < heapSize; ++i) {
                if (heapArray[i + childIndex] < minValue) {
                    minValue = heapArray[i + childIndex];
                    minIndex = i + childIndex;
                }
            }

            // Check for a violation of the min-heap property
            if (minValue == value) {
                return;
            } else {
                // Swap heapArray[nodeIndex] and heapArray[minIndex]
                T temp = heapArray[nodeIndex];
                heapArray[nodeIndex] = heapArray[minIndex];
                heapArray[minIndex] = temp;

                // Continue loop from the min index node
                nodeIndex = minIndex;
                childIndex = 2 * nodeIndex + 1;
            }
        }
    }

    void Insert(T value) {
        // Resize if needed
        if (heapSize == allocationSize) {
            ResizeArray();
        }

        // Add the new value to the end of the array
        heapArray[heapSize] = value;
        heapSize++;

        // Percolate up from the last index to restore heap property
        PercolateUp(heapSize - 1);
    }

    T Remove() {
        // Save the min value from the root of the heap
        T minValue = heapArray[0];

        // Move the last item in the array into index 0
        T replaceValue = heapArray[heapSize - 1];
        heapSize--;
        if (heapSize > 0) {
            heapArray[0] = replaceValue;

            // Percolate down to restore min-heap property
            PercolateDown(0);
        }

        // Return the min value
        return minValue;
    }
    bool isEmpty() const {
        return heapSize == 0;
    }
    T peek(){
    return heapArray[0];
    }

};

#endif // End of include guard
