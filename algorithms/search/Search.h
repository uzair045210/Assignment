//
// Created by Mr. Uzair on 10/8/2022.
//

#ifndef ASSIGNMENT_SEARCH_H
#define ASSIGNMENT_SEARCH_H

#include <math.h>

class Search {
public:
    int linearSearch(int arr[], int n, int target);
    int binarySearchIteration(int arr[], int n, int target);
    int binarySearchRecursion(int arr[], int n, int target);
    int ternarySearch(int arr[], int n, int target);
    int jumpSearch(int arr[], int n, int target);
    int exponentialSearch(int arr[], int n, int target);
private:
    int binarySearchRecursion(int arr[], int n, int target, int left, int right);
    int ternarySearch(int arr[], int n, int target, int left, int right);
    int exponentialSearch(int arr[], int n, int target, int range);
};


#endif //ASSIGNMENT_SEARCH_H
