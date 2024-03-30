#ifndef PROJEKT_SORTOWANIE_UTILITIES_H
#define PROJEKT_SORTOWANIE_UTILITIES_H
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"

// colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

using namespace std;

class Utilities {
public:
    Utilities();
    static void printArray(int *arr, int len, string mes);
    static void copyArray(int *arr, int *arrayCopy, int len);
};


#endif //PROJEKT_SORTOWANIE_UTILITIES_H
