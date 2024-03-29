#ifndef PROJEKT_SORTOWANIE_INSERTIONSORT_H
#define PROJEKT_SORTOWANIE_INSERTIONSORT_H
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"
#include "Algorithm.h"

using namespace std;

class Insertionsort :public Algorithm{
public:
    Insertionsort();
    virtual int sort(int *arr, int len);
};


#endif //PROJEKT_SORTOWANIE_INSERTIONSORT_H
