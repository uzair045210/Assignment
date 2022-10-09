#include <iostream>
#include "algorithms/search/Search.h"

using namespace std;

int main() {
    int SIZE = 10;
    int numbers[10] = {3, 5, 6, 9, 11, 18, 20, 21, 24, 30};
    string nums = "Numbers: { ";
    for (int i = 0; i < SIZE; i++) {
        nums += to_string(numbers[i]);
        if (i != SIZE - 1)
            nums += ", ";
        if (i == SIZE - 1)
            nums += " }";
    }
    cout << nums << endl;
    int target = numbers[6];
    cout << "Target = " << target << endl;
    Search search;
    cout << "Linear Search: " << search.linearSearch(numbers, SIZE, target) << endl;
    cout << "Binary Search (ITERATION): " << search.binarySearchIteration(numbers, SIZE, target) << endl;
    cout << "Binary Search (RECURSION): " << search.binarySearchRecursion(numbers, SIZE, target) << endl;
    cout << "Ternary Search (RECURSION): " << search.ternarySearch(numbers, SIZE, target) << endl;
    cout << "Jump Search: " << search.jumpSearch(numbers, SIZE, target) << endl;
    cout << "Exponential Search: " << search.exponentialSearch(numbers, SIZE, target) << endl;
    return 0;
}