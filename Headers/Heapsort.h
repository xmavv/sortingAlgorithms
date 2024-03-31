#ifndef PROJEKT_SORTOWANIE_HEAPSORT_H
#define PROJEKT_SORTOWANIE_HEAPSORT_H
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"
#include "Algorithm.h"

using namespace std;

class Heapsort :public Algorithm {
public:
    Heapsort();
    void heapify(int arr[], int n, int i);
    virtual void sort(int *arr, int len, int left = 0, int right = 0);
};


#endif //PROJEKT_SORTOWANIE_HEAPSORT_H
