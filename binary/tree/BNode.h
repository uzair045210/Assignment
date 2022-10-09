//
// Created by Mr. Uzair on 9/21/2022.
//

#ifndef ASSIGNMENT_BNODE_H
#define ASSIGNMENT_BNODE_H

using namespace std;

class BNode {
    public:
        int data;
        BNode* left = nullptr;
        BNode* right = nullptr;

        BNode(int data = 0) {
            this->data = data;
        }

};

#endif //ASSIGNMENT_BNODE_H
