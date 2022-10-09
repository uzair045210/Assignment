//
// Created by Mr. Uzair on 10/1/2022.
//

#ifndef ASSIGNMENT_AVLNODE_H
#define ASSIGNMENT_AVLNODE_H

class AVLNode {
public:
    int data;
    int height;
    AVLNode* left = nullptr;
    AVLNode* right = nullptr;
    AVLNode(int data) {
        this->data = data;
    }
};

#endif //ASSIGNMENT_AVLNODE_H
