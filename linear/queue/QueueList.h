//
// Created by Mr. Uzair on 8/11/2022.
//

#ifndef ASSIGNMENT_QUEUELIST_H
#define ASSIGNMENT_QUEUELIST_H

#include <iostream>
#include "../linkedList/List.h"

#define MAX_SIZE 10

using namespace std;

class QueueList {
public:
    QueueList(int size = MAX_SIZE);
    void enqueue(int item);
    void dequeue();
    int peek() const;
    bool isFull() const;
    bool isEmpty() const;
    int length() const;
    void print() const;

private:
    List list{};
    int max_size = MAX_SIZE;
    int size = 0;
};


#endif //ASSIGNMENT_QUEUELIST_H
