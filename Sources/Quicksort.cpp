#include "../Headers/Quicksort.h"
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"

using namespace std;

Quicksort::Quicksort() {

}

void Quicksort::sort(int *arr, int len, int left, int right) {
    if (left >= right)
        return;

    // partitioning the array
    int p = partition(arr, left, right);

    // Sorting the left part
    sort(arr, left, p - 1);

    // Sorting the right part
    sort(arr, p + 1, right);
}

int Quicksort::partition(int *arr, int left, int right) {
    int pivot = arr[left];

    int count = 0;
    for (int i = left + 1; i <= right; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    // Giving pivot element its correct position
    int pivotIndex = left + count;
    swap(arr[pivotIndex], arr[left]);

    // Sorting left and right parts of the pivot element
    int i = left, j = right;

    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i] <= pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}
