#ifndef PROJEKT_SORTOWANIE_PRESORT_H
#define PROJEKT_SORTOWANIE_PRESORT_H
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"

using namespace std;

template <typename T>
class PreSort {
public:
    void preSortPart(T *arr, int len, int type);
};

#endif //PROJEKT_SORTOWANIE_PRESORT_H
