#ifndef PROJEKT_SORTOWANIE_SHELLSORT_H
#define PROJEKT_SORTOWANIE_SHELLSORT_H
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"
#include "Algorithm.h"
#include <vector>

using namespace std;

template <typename T>
class Shellsort :public Algorithm<T> {
    T *arr;
    int len;
    int type;
public:
    Shellsort() {};
    void setArray(T *arr, int len, int type);
//    void shellsortMarcinciur(vector<T>& arr);
    virtual void sort();
};


#endif //PROJEKT_SORTOWANIE_SHELLSORT_H
