#ifndef PROJEKT_SORTOWANIE_ALGORITHM_H
#define PROJEKT_SORTOWANIE_ALGORITHM_H
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"
#include "Utilities.h"

using namespace std;

class Algorithm {
public:
    virtual void sort(int *arr, int len);
};

#endif //PROJEKT_SORTOWANIE_ALGORITHM_H
