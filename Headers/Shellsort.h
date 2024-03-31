#ifndef PROJEKT_SORTOWANIE_SHELLSORT_H
#define PROJEKT_SORTOWANIE_SHELLSORT_H
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"
#include "Algorithm.h"

using namespace std;

class Shellsort :public Algorithm {
public:
    Shellsort();
    virtual void sort(int *arr, int len, int left = 0, int right = 0);
};


#endif //PROJEKT_SORTOWANIE_SHELLSORT_H
