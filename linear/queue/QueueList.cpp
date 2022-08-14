//
// Created by Mr. Uzair on 8/11/2022.
//

#include "QueueList.h"

QueueList::QueueList(int size) {
    this->max_size = size;
}

void QueueList::enqueue(int item) {
    if (isFull())
        return;
    list.insert(item);
    size++;
}

void QueueList::dequeue() {
    if (isEmpty())
        return;
    list.removeFirst();
    size--;
}

int QueueList::peek() const {
    if (isEmpty()) {
        cerr << "Queue is empty right now!";
        return -1;
    }
    return list.getFirst();
}

bool QueueList::isEmpty() const {
    return size == 0;
}

bool QueueList::isFull() const {
    return size == max_size;
}

int QueueList::length() const {
    return size;
}
