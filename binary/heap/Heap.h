//
// Created by Mr. Uzair on 10/3/2022.
//

#ifndef ASSIGNMENT_HEAP_H
#define ASSIGNMENT_HEAP_H

#include <iostream>

#define MAX_SIZE 10

class Heap {
public:
    Heap();
    void insert(int item);
    int remove();
    void heapify(int *numbers, int n);
    int getKthLargest(int *numbers, int n, int k);
    int max();
    bool isFull() const;
    bool isEmpty() const;
private:
    int items[MAX_SIZE];
    int size = 0;
    void swap(int x, int y);
    int parent(int index);
    int left(int index);
    int right(int index);
    void bubbleUp();
    void bubbleDown();
    bool hasLeftChild(int index);
    bool hasRightChild(int index);
    int getLargeChildIndex(int index);
    bool isValidParent(int index);
    void heapify(int* numbers, int n, int index);
};


#endif //ASSIGNMENT_HEAP_H
