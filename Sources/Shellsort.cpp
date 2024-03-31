#include <vector>
#include "../Headers/Shellsort.h"
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"

using namespace std;

template <typename T>
void Shellsort<T>::setArray(T *arr, int len, int type) {
    this -> arr = arr;
    this -> len = len;
    this -> type = type;
}

template <typename T>
void Shellsort<T>::sort() {
    for (int gap = len/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < len; i++)
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

//void shellsortMarcinciur(vector<T>& arr) {
//    int n = arr.size();
//    vector<int> gaps = {701, 301, 132, 57, 23, 10, 4, 1};
//
//    for (int gap : gaps) {
//        for (int i = gap; i < n; i++) {
//            T temp = arr[i];
//            int j;
//            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
//                arr[j] = arr[j - gap];
//            }
//            arr[j] = temp;
//        }
//    }
//}

template class Shellsort<int>;
template class Shellsort<float>;
template class Shellsort<char>;