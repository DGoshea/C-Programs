#ifndef PQUEUE_H
#define PQUEUE_H

#include "minHeap.h"
#include <iostream>

using namespace std;
template <typename T>
class pQueue {
private:
    minHeap<T> heap;


public:
    void enQueue(T e) {
        heap.Insert(e);
    }

    T deQueue() {
        return heap.Remove();

    }
    bool isEmpty() const {
        return heap.isEmpty();
    }
    T peek(){
        return heap.peek();
    }

};

#endif // End of include guard
