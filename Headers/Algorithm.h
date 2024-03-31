#ifndef PROJEKT_SORTOWANIE_ALGORITHM_H
#define PROJEKT_SORTOWANIE_ALGORITHM_H
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"
#include "windows.h"
#include "Utilities.h"

// colors
#define WHITE   7
#define RED     12
#define GREEN   10
#define YELLOW  14
#define BLUE    9
#define MAGENTA 13
#define CYAN    11

using namespace std;

class Algorithm {
protected:
    Utilities u;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
public:
    virtual void sort() = 0;
};

#endif //PROJEKT_SORTOWANIE_ALGORITHM_H
