//
// Created by uzair on 7/21/22.
//

#include "List.h"

// * Insert

void List::insert(int item) {
    Node* node = new Node();
    node->value = item;
    node->next = nullptr;
    if (head == nullptr)    // * isEmpty()
        head = node;
    else {
        Node *temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = node;
    }
    size++;
}

void List::insertAt(int index, int item) {
    Node* temp1 = new Node;
    temp1->value = item;
    temp1->next = nullptr;
    if (index == 0) {
        insertFirst(item);
        return;
    }
    Node* temp2 = head;
    for (int i = 1; i < index - 2; i++)
        temp2 = temp2->next;
    temp1->next = temp2->next;
    temp2->next = temp1;
    size++;
}

void List::insertFirst(int item) {
    Node* temp = new Node;
    temp->value = item;
    temp->next = nullptr;
    if (head != nullptr)
        temp->next = head;
    head = temp;
    size++;
}

// * Remove
void List::remove(int item) {
    Node* temp = head;
    if (temp == nullptr || indexOf(item) == -1)
        return;
    if (isFirst(item)) {
        head = temp->next;
        delete temp;
        size--;
        return;
    }
    for (int i = 0; i < indexOf(item); i++)
        temp = temp->next;
    Node* temp1 = temp->next;
    temp->next = temp1->next;
    delete temp1;
    size--;
}

void List::removeAt(int index) {
    Node* temp = head;
    if (temp == nullptr || index == -1)
        return;
    if (index == 0) {
        head = temp->next;
        delete temp;
        size--;
        return;
    }
    for (int i = 1; i < index; i++)
        temp = temp->next;
    Node* temp1 = temp->next;
    temp->next = temp1->next;
    delete temp1;
    size--;
}

void List::removeFirst() {
    Node* temp = head;
    if (temp == nullptr)
        return;
    head = temp->next;
    delete temp;
    size--;
}

void List::removeLast() {
    if (head == nullptr)
        return;
    removeAt(size - 1);
}

// * Get
int List::get(int index) const {
    int i = 0, val{};
    if (index >= size) {
        std::cerr << " Index out of bounds!" << std::endl;
        return index;
    }
    Node *temp = head;
    while (i < index) {
        temp = temp->next;
        val = temp->value;
        i++;
    }
    return val;
}

int List::getMiddle() const {
    int mid = 0;
    if (size % 2 == 0)
        mid = (size / 2) - 1;
    else
        mid = floor(size / 2);
    return get(mid);
}

int List::getFirst() const {
    Node* temp = head;
    if (temp != nullptr)
        return temp->value;
    else
        std::cerr << "List is Empty!" << std::endl;
    return -1;
}

int List::getLast() const {
    return get(size - 1);
}

// * Replace
void List::replace(const int &item1, const int item2) {
    if (indexOf(item1) == -1)
        return;
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->value == item1) {
            temp->value = item2;
            return;
        }
        temp = temp->next;
    }
}

void List::replaceAt(int index, const int item2) {
    if (index == -1 || index >= size)
        return;
    Node* temp = head;
    for (int i = 0; i < index; i++)
        temp = temp->next;
    temp->value = item2;
}

void List::replaceFirst(const int item) {
    if (head == nullptr)
        return;
    Node *temp = head;
    temp->value = item;
}

void List::replaceLast(const int item) {
    if (head == nullptr)
        return;
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->value = item;
}

// * Utilities
void List::print() const {
    Node* temp = head;
    std::cout << "{";
    if (temp == nullptr)
        goto end;
    while (temp != NULL) {
        std::cout << temp->value;
        temp = temp->next;
        if (temp != NULL)
            std::cout << ", ";
    }
    end:
    std::cout << "}" << std::endl;
}

void List::printMiddle() const {
    if (head == nullptr) {
        print();
        return;
    }
    Node* temp = head;
    int index = 0, i = 0;
    std::cout << "{";
    if (size % 2 == 0) {
        index = (size / 2) - 1;
        while (i <= index) {
            if (i == index) {
                std::cout << temp->value << ", ";
                temp = temp->next;
                std::cout << temp->value;
                std::cout << '}' << std::endl;
                return;
            }
            temp = temp->next;
            i++;
        }
    } else {
        index = (size / 2);
        i = 0;
        while (i <= index) {
            if (i == index) {
                std::cout << temp->value << "}" << std::endl;
                return;
            }
            temp = temp->next;
            i++;
        }
    }
}

int List::indexOf(int item) const {
    Node* temp = head;
    int i = 0;
    while (temp != nullptr) {
        if (temp->value == item)
            return i;
        temp = temp->next;
        i++;
    }
    return -1;
}

bool List::isEmpty() const {
    return size == 0;
}

int List::length() const {
    return size;
}

bool List::isFirst(int item) const {
    return indexOf(item) == 0;
}