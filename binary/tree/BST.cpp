//
// Created by Mr. Uzair on 9/21/2022.
//


#include "BST.h"

BST::BST() {}

void BST::insert(int data) {
    BNode* newNode = new BNode(data);
    if (root == nullptr)
        root = newNode;
    else {
        BNode* current = root;
        while (true) {
            if (data < current->data) {
                if (current->left == nullptr) {
                    current->left = newNode;
                    break;
                }
                current = current->left;
            } else {
                if (current->right == nullptr) {
                    current->right = newNode;
                    break;
                }
                current = current->right;
            }
        }
    }
    size++;
}

void BST::remove(int data) {
    remove(root, data);
}

BNode* BST::remove(BNode *head, int data) {
    if (head == nullptr)
        return head;
    if (data < head->data)
        head->left = remove(head->left, data);
    else if (data > head->data)
        head->right = remove(head->right, data);
    else {
        // Case 1: No Child
        if (head->left == nullptr && head->right == nullptr) {
            delete head;
            head = nullptr;
        }
        // Case 2: One Child
        else if (root->left == nullptr) {
            BNode* temp = head;
            head = head->right;
            delete temp;
        } else if (root->right == nullptr) {
            BNode* temp = head;
            head = head->left;
            delete temp;
        }
        // Case 3: Two Child
        else {
            BNode* temp = findMin(head->right);
            head->data = temp->data;
            head->right = remove(head->right, temp->data);
        }
    }
    return head;
}

BNode* BST::findMin(BNode *head) {
    BNode* current = head;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

bool BST::doesExist(int data) {
    BNode* current = root;
    while (current != NULL) {
        if (data < current->data)
            current = current->left;
        else if (data > current->data)
            current = current->right;
        else
            return true;
    }
    return false;
}

bool BST::isEmpty() {
    return size;
}

int BST::getLeftMost() {
    BNode* current = root;
    while (current->left != nullptr)
        current = current->left;
    return current->data;
}

int BST::getRightMost() {
    BNode* current = root;
    while (current->right != nullptr)
        current = current->right;
    return current->data;
}

int BST::getLeftChild(int data) {
    BNode* parent = find(data);
    return (parent != NULL) ? ((parent->left != NULL) ? parent->left->data : -1) : -1;
}

int BST::getRightChild(int data) {
    BNode* parent = find(data);
    return (parent != NULL) ? ((parent->right != NULL) ? parent->right->data : -1) : -1;
}

bool BST::isFullParent(int data) {
    BNode* parent = find(data);
    return (parent->left == NULL && parent->right == NULL);
}

bool BST::isSingleParent(int data) {
    BNode* parent = find(data);
    return (parent->left != NULL && parent->right != NULL);
}

void BST::getChildren(int data) {
    BNode* parent = find(data);
    if (parent != NULL) {
        cout << ((parent->left != NULL) ? parent->left->data : -1) << " " <<
                ((parent->right != NULL) ? parent->right->data : -1);
    }
    return;
}

int BST::getSuccessor(int data) {
    successorPredecessor(root, data);
    return successor;
}

int BST::getPredecessor(int data) {
    successorPredecessor(root, data);
    return predecessor;
}

void BST::successorPredecessor(BNode *head, int data) {
    if (head != NULL) {
        if (head->data == data) {
            if (head->left != NULL) {
                BNode* temp = head->left;
                while (temp->right != NULL)
                    temp = temp->right;
                predecessor = temp->data;
            }
            if (head->right != NULL) {
                BNode* temp = head->right;
                while (temp->left != NULL)
                    temp = temp->left;
                successor = temp->data;
            }
        } else if (head->data > data) {
            successor = head->data;
            successorPredecessor(head->left, data);
        } else if (head->data < data) {
            predecessor = head->data;
            successorPredecessor(head->right, data);
        }
    }
}

bool BST::isBST() {
    return isBST(root, INT_MIN, INT_MAX);
}

bool BST::isBST(BNode* head, int max, int min) {
    if (head == NULL)
        return true;
    if (head->data < min || head->data > max)
        return false;
    return isBST(head->left, min, head->data - 1)
            && isBST(head->right, head->data + 1, max);
}

BNode* BST::find(int data) {
    return find(root, data);
}

BNode* BST::find(BNode* head, int data) {
    if (head->data == data)
        return head;
    if (data < head->data)
        head = head->left;
    else if (data > head->data)
        head = head->right;
    else
        return NULL;
}

int BST::height() {
    return height(root);
}

int BST::height(BNode* head) {
    if (head == NULL)
        return -1;
    if (head->left == NULL && head->right == NULL)
        return 0;
    return 1 + __max(height(head->left), height(head->right));
}

void BST::kDistance(int distance) {
    kDistance(distance);
}

void BST::kDistance(BNode* head, int distance) {
    if (head == NULL)
        return;
    if (distance == 0) {
        cout << head->data << " ";
        return;
    }
    kDistance(head->left, distance - 1);
    kDistance(head->right, distance - 1);
}

void BST::levelOrder() {
    for (int i = 0; i <= height(); i++) {
        kDistance(i);
    }
}

void BST::preOrder() {
    preOrder(root);
    cout << endl;
}
// (Root, Left, Right)
void BST::preOrder(BNode* head) {
    if (head == nullptr)
        return;
    cout << head->data << " ";
    preOrder(head->left);
    preOrder(head->right);
}

void BST::inOrder() {
    inOrder(root);
    cout << endl;
}

// (Left, Root, Right)
void BST::inOrder(BNode* head) {
    if (head == nullptr)
        return;
    inOrder(head->left);
    cout << head->data << " ";
    inOrder(head->right);
}

void BST::postOrder() {
    postOrder(root);
    cout << endl;
}

// (Left, Right, Root)
void BST::postOrder(BNode* head) {
    if (head == nullptr)
        return;
    postOrder(head->left);
    postOrder(head->right);
    cout << head->data << " ";
}


