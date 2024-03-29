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
    virtual int sort(int *arr, int len);
};


#endif //PROJEKT_SORTOWANIE_QUICKSORT_H
