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
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

using namespace std;


class Menu {
    int userChoice;
    int *arrayToSort;
    int arrayLength;
//    Algorithm *algorithm;
    Insertionsort insertionsort;
    Quicksort quicksort;
    Shellsort shellsort;
    Heapsort heapsort;

public:
    void start();
    void generateRandomArray(int len);
    void loadArrayFromFile(string name);
    void chooseAlgorithm();
};


#endif //PROJEKT_SORTOWANIE_MENU_H
