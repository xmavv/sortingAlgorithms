#include <algorithm>
#include "../Headers/PreSort.h"

using namespace std;

template <typename T>
void PreSort<T>::preSortPart(T *arr, int len, int type) {
    int e;
    type == 4 ? e = 1 : e = 2;
    int percent = len * e/3;

    std::sort(arr, arr+len);

    //fisher-yates shuffle
    srand(time(NULL));
    for (int i = percent; i < len; i++) {
        int j = rand() % (len-percent)+percent;
        swap(arr[i], arr[j]);
    }
}

template class PreSort<int>;
template class PreSort<float>;
template class PreSort<char>;