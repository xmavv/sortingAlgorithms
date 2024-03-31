#ifndef PROJEKT_SORTOWANIE_UTILITIES_H
#define PROJEKT_SORTOWANIE_UTILITIES_H
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"
#include "windows.h"

// colors
#define WHITE   7
#define RED     12
#define GREEN   10
#define YELLOW  14
#define BLUE    9
#define MAGENTA 13
#define CYAN    11

using namespace std;

template <typename T>
class Utilities {
    double PCFreq = 0.0;
    __int64 start = 0;
public:
    Utilities() {};
    static void printArray(T *arr, int len, string mes);
    static void printColorText(HANDLE console, string message, int color);
    static void copyArray(T *arr, T *arrayCopy, int len);
    void startCounter();
    double getCounter();
};


#endif //PROJEKT_SORTOWANIE_UTILITIES_H
