//
// Created by Mr. Uzair on 10/1/2022.
//

#ifndef ASSIGNMENT_AVL_H
#define ASSIGNMENT_AVL_H

#include "../AVLNode.h"
#include <math.h>

class AVL {
public:
    void insert(int data);
private:
    AVLNode* head = nullptr;
    int size = 0;

    AVLNode* insert(AVLNode* head, int data);
    int height(AVLNode* node);
    void setHeight(AVLNode* node);
    bool isLeftHeavy(AVLNode* node);
    bool isRightHeavy(AVLNode* node);
    int balanceFactor(AVLNode* node);
    AVLNode* balance(AVLNode* head);
    AVLNode* leftRotate(AVLNode* root);
    AVLNode* rightRotate(AVLNode* root);
};


#endif //ASSIGNMENT_AVL_H
