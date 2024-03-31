#include "../Headers/Insertionsort.h"
#include "iostream"

using namespace std;

Insertionsort::Insertionsort() {

}

void Insertionsort::sort(int *arr, int len, int left, int right) {
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