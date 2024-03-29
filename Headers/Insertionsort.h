#ifndef PROJEKT_SORTOWANIE_INSERTIONSORT_H
#define PROJEKT_SORTOWANIE_INSERTIONSORT_H
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"
#include "Algorithm.h"

using namespace std;

class Insertionsort :public Algorithm {
public:
    Insertionsort();
    virtual void sort();
};


#endif //PROJEKT_SORTOWANIE_INSERTIONSORT_H
