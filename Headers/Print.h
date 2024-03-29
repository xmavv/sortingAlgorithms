#ifndef PROJEKT_SORTOWANIE_PRINT_H
#define PROJEKT_SORTOWANIE_PRINT_H
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"

using namespace std;

class Print {
public:
    Print();
    static void printArray(int *arr, int len, string mes);
};


#endif //PROJEKT_SORTOWANIE_PRINT_H
