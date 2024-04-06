#include "../Headers/Quicksort.h"
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"

using namespace std;

template <typename T>
void Quicksort<T>::setArray(T *arr, int left, int right, int pivotOption) {
    this -> arr = arr;
    this -> left = left;
    this -> right = right;
    this -> pivotOption = pivotOption;
}

template <typename T>
void Quicksort<T>::sortHelper(T *arr, int left, int right) {
    if (left >= right) return; //jednoelementowa tablica oznacza ze jest posortowana

    //wyznaczamy index elementu rozdzielajacego tablice (elementy po lewej sa mniejsze, po prawej wieksze)
    int m = partition(arr, left, right);

    //sortujemy lewa strone
    sortHelper(arr, left, m - 1);

    //sortujemy prawa strone
    sortHelper(arr, m + 1, right);
}

template <typename T>
void Quicksort<T>::sort() {
    sortHelper(arr, left, right);
}

template <typename T>
int Quicksort<T>::partition(T *arr, int left, int right) {
    int pivotElement;

    if(pivotOption == 1) {
        pivotElement = arr[left];
    } else if(pivotOption == 2) {
        pivotElement = arr[right];
    } else if(pivotOption == 3) {
        pivotElement = arr[left + (right-left) /2];
    } else {
        srand(time(0));
        int pivotRandom = left + rand() % (right - left +1);
        pivotElement = arr[pivotRandom];
    }

    int l=left; int r=right;
    while(true) {
        //szukamy elementu wiekszego od pivota z lewej strony
        while(arr[l]<pivotElement) ++l;
        //szukamy elementu mniejszego od pivota z prawej strony
        while(arr[r]>pivotElement) --r;
        //jezeli nasze "wskazniki" zamienily sie miejscami, zamieniamy te dwa elementy
        if(l < r) {
            swap(arr[l], arr[r]);
            ++l;
            --r;
        } else {
            if(r == right) r--;
            return r;
        }
    }
}

template class Quicksort<int>;
template class Quicksort<float>;
template class Quicksort<char>;