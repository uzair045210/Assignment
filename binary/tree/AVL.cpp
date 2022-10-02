//
// Created by Mr. Uzair on 10/1/2022.
//

#include "AVL.h"

void AVL::insert(int data) {
    head = insert(head, data);
}

AVLNode* AVL::insert(AVLNode *head, int data) {
    if (head == nullptr)
        return new AVLNode(data);
    if (data < head->data)
        head->left = insert(head->left, data);
    else
        head->right = insert(head->right, data);
    setHeight(head);
    size++;
    return balance(head);
}

bool AVL::isBalanced() {
    int bf = balanceFactor(head);
    return (bf >= -1) && (bf <= 1);
}

AVLNode* AVL::balance(AVLNode* head) {
    if (isLeftHeavy(head)) {
        if (balanceFactor(head->left) < 0) {
            head->left = leftRotate(head->left);
        }
        return rightRotate(head);
    } else if (isRightHeavy(head->right)) {
        if (balanceFactor(head->right) > 0) {
            head->right = rightRotate(head->right);
        }
        return leftRotate(head);
    }
    return head;
}

int AVL::height(AVLNode* node) {
    return (node == nullptr) ? -1 : node->height;
}

void AVL::setHeight(AVLNode *node) {
    node->height = __max(height(node->left), height(node->right)) + 1;
}

bool AVL::isLeftHeavy(AVLNode *node) {
    return balanceFactor(node) > 1;
}

bool AVL::isRightHeavy(AVLNode *node) {
    return balanceFactor(node) < -1;
}

int AVL::balanceFactor(AVLNode *node) {
    return (node == nullptr) ? 0 : (height(node->left) - height(node->right));
}

AVLNode* AVL::leftRotate(AVLNode *root) {
    AVLNode* newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;

    setHeight(root);
    setHeight(newRoot);

    return newRoot;
}

AVLNode* AVL::rightRotate(AVLNode *root) {
    AVLNode* newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;

    setHeight(root);
    setHeight(newRoot);

    return newRoot;
}