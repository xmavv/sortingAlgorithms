#ifndef PROJEKT_SORTOWANIE_QUICKSORT_H
#define PROJEKT_SORTOWANIE_QUICKSORT_H

#include <functional>
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"
#include "Algorithm.h"

using namespace std;

template <typename T>
class Quicksort :public Algorithm<T> {
    T *arr;
    int left;
    int right;
    int pivotOption;
public:
    Utilities<T> u;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    Quicksort() {};
    void quicksortAlgorithm();
    static int partitionLeft(T arr[], int left, int right);
    static int partitionRight(T arr[], int left, int right);
    static int partitionCenter(T arr[], int left, int right);
    static int partitionRandom(T arr[], int left, int right);
    void setArray(T *arr, int left, int right, int pivotOption);
    void sortHelper(T *arr, int left, int right, function<int(T[], int, int)> callback);
    virtual double sort();
};


#endif //PROJEKT_SORTOWANIE_QUICKSORT_H
