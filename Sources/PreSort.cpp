#include "../Headers/PreSort.h"
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"

using namespace std;

template <typename T>
void PreSort<T>::preSortPart(T *arr, int len, int type) {
    int e;
    type == 3 ? e = 1 : e = 2;
}

template class PreSort<int>;
template class PreSort<float>;
template class PreSort<char>;