#include "../Headers/Quicksort.h"
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"

using namespace std;

Quicksort::Quicksort() {

}

void Quicksort::setArray(int *arr, int left, int right, int pivotOption) {
    this -> arr = arr;
    this -> left = left;
    this -> right = right;
    this -> pivotOption = pivotOption;
}

void Quicksort::sortHelper(int *arr, int left, int right) {
    if (left >= right)
        return;

    // partitioning the array
    int p = partition(arr, left, right);

    // Sorting the left part
    sortHelper(arr, left, p - 1);

    // Sorting the right part
    sortHelper(arr, p + 1, right);
}

void Quicksort::sort() {
    sortHelper(arr, left, right);
}

int Quicksort::partition(int *arr, int left, int right) {
    int pivotElement;

    if(pivotOption == 1) {
        pivotElement = arr[left];
    } else if(pivotOption == 2) {
        pivotElement = arr[right];
    } else if(pivotOption == 3) {
        pivotElement = arr[left + (right-left) /2];
    } else {
        srand(time(0));
        int pivotRandom = left + rand() % (right - left +1);
        pivotElement = arr[pivotRandom];
    }

    int count = 0;
    for (int i = left + 1; i <= right; i++) {
        if (arr[i] <= pivotElement)
            count++;
    }

    // Giving pivot element its correct position
    int pivotIndex = left + count;
    swap(arr[pivotIndex], arr[left]);

    // Sorting left and right parts of the pivot element
    int i = left, j = right;

    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i] <= pivotElement) {
            i++;
        }

        while (arr[j] > pivotElement) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}
