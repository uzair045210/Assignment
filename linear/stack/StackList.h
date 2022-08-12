//
// Created by Mr. Uzair on 8/11/2022.
//

#ifndef ASSIGNMENT_STACKLIST_H
#define ASSIGNMENT_STACKLIST_H

// * Stack using linked list

#include <iostream>
#include "../linkedList/List.h"

#define MAX_SIZE 10

using namespace std;

class StackList {
public:
    StackList(int size = MAX_SIZE);
    void push(int item);
    void pop();
    int peek() const;
    bool isEmpty() const;
    bool isFull() const;
    int length() const;
private:
    List list;
    int max_size = MAX_SIZE;
    int size = 0;
};


#endif //ASSIGNMENT_STACKLIST_H
