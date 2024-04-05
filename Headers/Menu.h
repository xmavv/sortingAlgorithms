#ifndef PROJEKT_SORTOWANIE_MENU_H
#define PROJEKT_SORTOWANIE_MENU_H
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"
#include "Algorithm.h"
#include "Insertionsort.h"
#include "Quicksort.h"
#include "Shellsort.h"
#include "Heapsort.h"
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

template <typename T>
class Menu {
    int variableType;
    int userChoice;
    T *arrayToSort;
    int arrayLength;
    Utilities<T> u;
    Algorithm<T> *algorithm;
    Insertionsort<T> insertionsort;
    Quicksort<T> quicksort;
    Shellsort<T> shellsort;
    Heapsort<T> heapsort;

public:
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    Menu(int variableType);
    void choosePreSort();
    void chooseArray();
    void chooseAlgorithm(T originalArray[]);
    void generateRandomArray(int len);
    void loadArrayFromFile(string name);
    void startAlgorithm(Algorithm<T> *a);
};


#endif //PROJEKT_SORTOWANIE_MENU_H
