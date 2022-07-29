//
// Created by uzair on 7/21/22.
//

#ifndef DSA_LIST_H
#define DSA_LIST_H

#include "Node.h"
#include <iostream>
#include <math.h>

#define SIZE 20

class List {
public:
    // * Insert
    void insert(int item);
    void insertAt(int index, int item);
    void insertFirst(int item);
    // * Remove
    void remove(int item);
    void removeAt(int index);
    void removeFirst();
    void removeLast();
    // * Get
    int get(int index) const;
    int getMiddle() const;
    int getFirst() const;
    int getLast() const;
    // * Modify
    void replace(const int& item1, const int item2);
    void replaceAt(int index, const int item2);
    void replaceFirst(const int item);
    void replaceLast(const int item);
    // * Utilities
    int indexOf(int item) const;
    void printMiddle() const;
    void print() const;
    bool isEmpty() const;
    int length() const;
private:
    Node* head;
    int size;
    bool isFirst(int item) const;
};


#endif //DSA_LIST_H
