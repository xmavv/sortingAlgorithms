#ifndef PROJEKT_SORTOWANIE_QUICKSORT_H
#define PROJEKT_SORTOWANIE_QUICKSORT_H
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"
#include "Algorithm.h"

using namespace std;

template <typename T>
class Quicksort :public Algorithm<T> {
    T *arr;
    int left;
    int right;
    int pivotOption;
public:
    Quicksort() {};
    int partition(T *arr, int left, int right);
    void setArray(T *arr, int left, int right, int pivotOption);
    void sortHelper(T *arr, int left, int right);
    virtual void sort();
};


#endif //PROJEKT_SORTOWANIE_QUICKSORT_H
