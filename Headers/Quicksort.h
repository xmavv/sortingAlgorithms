#ifndef PROJEKT_SORTOWANIE_QUICKSORT_H
#define PROJEKT_SORTOWANIE_QUICKSORT_H
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"
#include "Algorithm.h"

using namespace std;

class Quicksort :public Algorithm {
public:
    Quicksort();
    int partition(int *arr, int start, int end);
    virtual void sort(int *arr, int len, int left = 0, int right = 0);
};


#endif //PROJEKT_SORTOWANIE_QUICKSORT_H
