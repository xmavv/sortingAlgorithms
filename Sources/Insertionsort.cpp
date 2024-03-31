#include "../Headers/Insertionsort.h"
#include "iostream"

using namespace std;

template <typename T>
void Insertionsort<T>::setArray(T *arr, int len) {
    this -> arr = arr;
    this -> len = len;
}

template <typename T>
void Insertionsort<T>::sort() {
    int i, j;
    double key;

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

template class Insertionsort<int>;
template class Insertionsort<float>;
template class Insertionsort<char>;