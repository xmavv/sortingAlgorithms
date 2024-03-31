#ifndef PROJEKT_SORTOWANIE_INSERTIONSORT_H
#define PROJEKT_SORTOWANIE_INSERTIONSORT_H
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"
#include "Algorithm.h"

using namespace std;

template <typename T>
class Insertionsort :public Algorithm<T> {
    T *arr;
    int len;
public:
    Insertionsort() {};
    void setArray(T *arr, int len);
    virtual void sort();
};


#endif //PROJEKT_SORTOWANIE_INSERTIONSORT_H
