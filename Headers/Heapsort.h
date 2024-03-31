#ifndef PROJEKT_SORTOWANIE_HEAPSORT_H
#define PROJEKT_SORTOWANIE_HEAPSORT_H
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"
#include "Algorithm.h"

using namespace std;

class Heapsort {
public:
    Heapsort();
    void heapify(int arr[], int n, int i);
    void sort(int *arr, int len);
};


#endif //PROJEKT_SORTOWANIE_HEAPSORT_H
