#ifndef PROJEKT_SORTOWANIE_SHELLSORT_H
#define PROJEKT_SORTOWANIE_SHELLSORT_H
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"
#include "Algorithm.h"

using namespace std;

class Shellsort :public Algorithm {
    int *arr;
    int len;
public:
    Shellsort();
    void setArray(int *arr, int len);
    virtual void sort();
};


#endif //PROJEKT_SORTOWANIE_SHELLSORT_H
