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

using namespace std;


class Menu {
    int userChoice;
    int *arrayToSort;
    int arrayLength;

//    Algorithm *algorithm;
//    Insertionsort insertionsort;
//    Quicksort quicksort;
//    Shellsort shellsort;
//    Heapsort heapsort;

public:
    void start();
    void generateRandomArray(int len);
    void loadArrayFromFile(string name);
    void chooseAlgorithm();
    void showArray(int *p, int len);
};


#endif //PROJEKT_SORTOWANIE_MENU_H
