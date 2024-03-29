#ifndef PROJEKT_SORTOWANIE_ALGORITHM_H
#define PROJEKT_SORTOWANIE_ALGORITHM_H
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"
#include "Print.h"

using namespace std;

class Algorithm {
public:
    virtual int sort(int *arr, int len) = 0;
};

#endif //PROJEKT_SORTOWANIE_ALGORITHM_H
