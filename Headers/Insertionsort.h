#ifndef PROJEKT_SORTOWANIE_INSERTIONSORT_H
#define PROJEKT_SORTOWANIE_INSERTIONSORT_H
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"
#include "Algorithm.h"
#include "Utilities.h"

using namespace std;

class Insertionsort {
    Utilities u;
public:
    Insertionsort();
     void sort(int *arr, int len);
};


#endif //PROJEKT_SORTOWANIE_INSERTIONSORT_H
