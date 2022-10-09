//
// Created by Mr. Uzair on 10/3/2022.
//

#include "Heap.h"

Heap::Heap() {
}

void Heap::insert(int item) {
    if (isFull()) {
        std::cerr << "Error! Heap is Full..." << std::endl;
        return;
    }
    items[size++] = item;
    bubbleUp();
}

int Heap::remove() {
    int root = items[0];
    items[0] = items[--size];
    bubbleDown();
    return root;
}

void Heap::heapify(int *numbers, int n) {
    int lastIndex = (n / 2) - 1;
    for (int i = lastIndex; i >= 0; i--) {
        heapify(numbers, n, i);
    }
}

void Heap::heapify(int *numbers, int n, int index) {
    int largerIndex = index;
    int leftIndex = index * 2 + 1,
        rightIndex = index * 2 + 2;
    if (leftIndex < n && numbers[leftIndex] > numbers[largerIndex])
        largerIndex = leftIndex;
    if (rightIndex < n && numbers[rightIndex] > numbers[largerIndex])
        largerIndex = rightIndex;
    if (index == largerIndex)
        return;
    int temp = numbers[index];
    numbers[index] = numbers[largerIndex];
    numbers[largerIndex] = temp;
    heapify(numbers, n, largerIndex);
}

int Heap::getKthLargest(int *numbers, int n, int k) {
    if (k < 1 || k > n)
        return -1;
    Heap heap = Heap();
    for (int i = 0; i < n; i++)
        heap.insert(numbers[i]);
    for (int i = 0; i < k - 1; i++)
        heap.remove();
    return heap.max();
}

void Heap::bubbleUp() {
    int index = size - 1;
    while (index > 0 && items[index] > items[parent(index)]) {
        swap(parent(index), index);
        index = parent(index);
    }
}

void Heap::bubbleDown() {
    if (isEmpty()) {
        std::cerr << "Error! Heap is Empty right Now..." << std::endl;
        return;
    }
    int index = 0;
    while (index <= size && !isValidParent(index)) {
        int largeChildIndex = getLargeChildIndex(index);
        swap(index, largeChildIndex);
        index = largeChildIndex;
    }
}

bool Heap::isValidParent(int index) {
    if (!hasLeftChild(index))
        return true;
    bool isValid = items[index] >= items[left(index)];
    if (hasRightChild(index))
        isValid &= items[index] >= items[right(index)];
    return isValid;
}

int Heap::getLargeChildIndex(int index) {
    if (!hasLeftChild(index))
        return index;
    if (!hasRightChild(index))
        return left(index);
    return (items[left(index)] > items[right(index)]) ? left(index) : right(index);
}

bool Heap::hasLeftChild(int index) {
    return left(index) <= size;
}

bool Heap::hasRightChild(int index) {
    return right(index) <= size;
}

int Heap::parent(int index) {
    return (index - 1) / 2;
}

int Heap::left(int index) {
    return (index * 2) + 1;
}

int Heap::right(int index) {
    return (index * 2) + 2;
}

void Heap::swap(int x, int y) {
    int temp = items[x];
    items[x] = items[y];
    items[y] = temp;
}

bool Heap::isFull() const {
    return size == MAX_SIZE;
}

bool Heap::isEmpty() const {
    return size == 0;
}

int Heap::max() {
    if (isEmpty())
        return -1;
    return items[0];
}