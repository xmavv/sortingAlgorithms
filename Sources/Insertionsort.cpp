#include "../Headers/Insertionsort.h"
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"

using namespace std;

Insertionsort::Insertionsort() {

}

int Insertionsort::sort(int *arr, int len) {
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

    Utilities::printArray(arr, len, "twoja tablica po sortowaniu");

//    delete [] arr;
    return *arr;
}