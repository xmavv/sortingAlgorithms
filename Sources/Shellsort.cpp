#include "../Headers/Shellsort.h"
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"

using namespace std;

Shellsort::Shellsort() {

}

void Shellsort::setArray(int *arr, int len) {
    this -> arr = arr;
    this -> len = len;
}

void Shellsort::sort() {
    for (int gap = len/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < len; i += 1)
        {
            int temp = arr[i];

            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            arr[j] = temp;
        }
    }

    return;
}