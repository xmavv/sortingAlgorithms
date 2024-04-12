#ifndef PROJEKT_SORTOWANIE_HEAPSORT_H
#define PROJEKT_SORTOWANIE_HEAPSORT_H
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"
#include "Algorithm.h"

using namespace std;

template <typename T>
class Heapsort :public Algorithm<T> {
    T *arr;
    int len;
    int userChoice;
public:
    Utilities<T> u;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    Heapsort() {};
    void heapsortAlgorithm();
    void heapify(T arr[], int n, int i);
    void setArray(T *arr, int len);
    virtual void sort();
};


#endif //PROJEKT_SORTOWANIE_HEAPSORT_H
