//
// Created by Mr. Uzair on 10/8/2022.
//

#include "Search.h"

int Search::linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++)
        if (arr[i] == target)
            return i;
    return -1;
}

int Search::binarySearchIteration(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    int middle = (left + right) / 2;
    while (left <= right) {
        if (arr[middle] == target)
            return middle;
        if (arr[middle] > target)
            right = middle - 1;
        else if (arr[middle] < target)
            left = middle + 1;
        middle = (left + right) / 2;
    }
    return -1;
}

int Search::binarySearchRecursion(int arr[], int n, int target) {
    return binarySearchRecursion(arr, n, target, 0, n - 1);
}

int Search::binarySearchRecursion(int arr[], int n, int target, int left, int right) {
    if (right < left)
        return -1;
    int middle = (left + right) / 2;
    if (arr[middle] == target)
        return middle;
    if (arr[middle] > target)
        return binarySearchRecursion(arr, n, target, left, middle - 1);
    return binarySearchRecursion(arr, n, target, middle + 1, right);
}

int Search::ternarySearch(int arr[], int n, int target) {
    return ternarySearch(arr, n, target, 0, n - 1);
}

int Search::ternarySearch(int arr[], int n, int target, int left, int right) {
    int partitionSize = (right - left) / 3;
    int mid1 = left + partitionSize;
    int mid2 = right - partitionSize;
    if (left > right)
        return -1;
    if (target == arr[mid1])
        return mid1;
    if (target == arr[mid2])
        return mid2;
    else if (target < arr[mid1])
        return ternarySearch(arr, n, target, left, mid1 - 1);
    else if (target > arr[mid2])
        return ternarySearch(arr, n, target, mid2 + 1, right);
    return ternarySearch(arr, n, target, mid1 + 1, mid2 - 1);
}

int Search::jumpSearch(int arr[], int n, int target) {
    int blockSize = sqrt(n) + 1;
    int start = 0, end = blockSize - 1;
    while (start < n && end < n) {
        if (arr[end - 1] < target) {
            start = end;
            end += blockSize - 1;
        }
        else if (arr[end - 1] > target) {
            for (int i = start; i < end; ++i) {
                return (arr[i] == target) ? i : -1;
            }
        }
        else if (arr[end] == target)
            return end;
    }
    return -1;
}

int Search::exponentialSearch(int arr[], int n, int target) {
    return exponentialSearch(arr, n, target, 1);
}

int Search::exponentialSearch(int arr[], int n, int target, int range) {
    int bound = 1;
    while (arr[bound] < target && bound < n)
        bound *= 2;
    int left = bound / 2,
            right = __min(bound, n - 1);
    return binarySearchRecursion(arr, n, target, left, right);
}