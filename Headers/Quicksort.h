#ifndef PROJEKT_SORTOWANIE_QUICKSORT_H
#define PROJEKT_SORTOWANIE_QUICKSORT_H
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"
#include "Algorithm.h"

using namespace std;

class Quicksort {
public:
    Quicksort();
    int partition(int *arr, int start, int end);
    void sort(int *arr, int left, int right);
};


#endif //PROJEKT_SORTOWANIE_QUICKSORT_H
