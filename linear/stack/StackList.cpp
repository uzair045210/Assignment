//
// Created by Mr. Uzair on 8/11/2022.
//

#include "StackList.h"

StackList::StackList(int size) {
    this->max_size = size;
}

void StackList::push(int item) {
    if (isFull())
        return;
    list.insertFirst(item);
    size++;
}

void StackList::pop() {
    if (isEmpty())
        return;
    list.removeFirst();
    size--;
}

int StackList::peek() const {
    if (isEmpty()) {
        cerr << "Stack is empty right now!";
        return -1;
    }
    return list.getFirst();
}

bool StackList::isEmpty() const {
    return size == 0;
}

bool StackList::isFull() const {
    return size == max_size;
}

int StackList::length() const {
    return size;
}