#include "../Headers/Insertionsort.h"
#include "iostream"

using namespace std;

Insertionsort::Insertionsort() {

}

void Insertionsort::setArray(int *arr, int len) {
    this -> arr = arr;
    this -> len = len;
}

void Insertionsort::sort() {
    int i, key, j;
    for (i = 1; i < len; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    return;
}