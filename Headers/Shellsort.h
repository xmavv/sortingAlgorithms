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
    virtual int sort(int *arr, int len);
};


#endif //PROJEKT_SORTOWANIE_SHELLSORT_H
