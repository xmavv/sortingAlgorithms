#ifndef PROJEKT_SORTOWANIE_QUICKSORT_H
#define PROJEKT_SORTOWANIE_QUICKSORT_H
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"
#include "Algorithm.h"

using namespace std;

class Quicksort :public Algorithm {
    int *arr;
    int left;
    int right;
    int pivotOption;
public:
    Quicksort();
    int partition(int *arr, int left, int right);
    void setArray(int *arr, int left, int right, int pivotOption);
    void sortHelper(int *arr, int left, int right);
    virtual void sort();
};


#endif //PROJEKT_SORTOWANIE_QUICKSORT_H
