#ifndef PQUEUE_H
#define PQUEUE_H

#include "minHeap.h"
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
};

#endif // End of include guard
