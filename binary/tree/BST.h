//
// Created by Mr. Uzair on 9/21/2022.
//

#ifndef ASSIGNMENT_BST_H
#define ASSIGNMENT_BST_H

#include <iostream>
#include <math.h>
#include "../BNode.h"

using namespace std;

class BST {
public:
    BST();

    void insert(int data);

    void remove(int data);

    bool doesExist(int data);

    bool isEmpty();

    // Getters
    int getLeftMost();

    int getRightMost();

    int getLeftChild(int data);

    int getRightChild(int data);

    bool isFullParent(int data);

    bool isSingleParent(int data);

    int height();

    void kDistance(int distance);

    void getChildren(int data);

    int getSuccessor(int data);

    int getPredecessor(int data);

    // Traversals
    void levelOrder();

    void preOrder();

    void inOrder();

    void postOrder();

private:
    BNode *root = nullptr;
    int successor{}, predecessor{};
    int size = 0;

    BNode *remove(BNode *head, int data);

    BNode *findMin(BNode *head);

    void preOrder(BNode *head);

    void inOrder(BNode *head);

    void postOrder(BNode *head);

    BNode *find(int data);

    BNode *find(BNode *head, int data);

    int height(BNode *head);

    void kDistance(BNode *head, int distance);

    void successorPredecessor(BNode* head, int data);
};

#endif //ASSIGNMENT_BST_H