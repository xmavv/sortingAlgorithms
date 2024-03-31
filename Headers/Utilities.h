#ifndef PROJEKT_SORTOWANIE_UTILITIES_H
#define PROJEKT_SORTOWANIE_UTILITIES_H
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"

// colors
#define WHITE   7
#define RED     12
#define GREEN   10
#define YELLOW  14
#define BLUE    9
#define MAGENTA 13
#define CYAN    11

using namespace std;

class Utilities {
    double PCFreq = 0.0;
    __int64 start = 0;
public:
    Utilities();
    static void printArray(int *arr, int len, string mes);
    static void copyArray(int *arr, int *arrayCopy, int len);
    void startCounter();
    double getCounter();
};


#endif //PROJEKT_SORTOWANIE_UTILITIES_H
