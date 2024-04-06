#include "../Headers/Quicksort.h"
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"
#include "functional"

using namespace std;

template <typename T>
void Quicksort<T>::setArray(T *arr, int left, int right, int pivotOption) {
    this -> arr = arr;
    this -> left = left;
    this -> right = right;
    this -> pivotOption = pivotOption;
}

template <typename T>
void Quicksort<T>::quicksortAlgorithm() {
//    sortHelper(arr, left, right, partitionLeft);
}

template <typename T>
void Quicksort<T>::sortHelper(T *arr, int left, int right, function<int(T[], int, int)> callback) {
    if (left >= right) return; //jednoelementowa tablica oznacza ze jest posortowana

    //wyznaczamy index elementu rozdzielajacego tablice (elementy po lewej sa mniejsze, po prawej wieksze)
    int m = callback(arr, left, right);

    //sortujemy lewa strone
    sortHelper(arr, left, m - 1, callback);

    //sortujemy prawa strone
    sortHelper(arr, m + 1, right, callback);
}

template <typename T>
void Quicksort<T>::sort() {
    if(pivotOption == 1) {
        u.startCounter(); //start timer

        sortHelper(arr, left, right, partitionLeft);

        double stop = u.getCounter();

        Utilities<T>::printArray(arr, right+1, "twoja tablica po sortowaniu"); //print sorted
        Utilities<T>::printColorText(hConsole, ("\nczas sortowania " + to_string(stop) + " [s]"), CYAN);
    } else if(pivotOption == 2) {
        u.startCounter(); //start timer

        sortHelper(arr, left, right, partitionRight);

        double stop = u.getCounter();

        Utilities<T>::printArray(arr, right+1, "twoja tablica po sortowaniu"); //print sorted
        Utilities<T>::printColorText(hConsole, ("\nczas sortowania " + to_string(stop) + " [s]"), CYAN);
    } else if(pivotOption == 3) {
        u.startCounter(); //start timer

        sortHelper(arr, left, right, partitionCenter);

        double stop = u.getCounter();

        Utilities<T>::printArray(arr, right+1, "twoja tablica po sortowaniu"); //print sorted
        Utilities<T>::printColorText(hConsole, ("\nczas sortowania " + to_string(stop) + " [s]"), CYAN);
    } else {
        u.startCounter(); //start timer

        sortHelper(arr, left, right, partitionRandom);

        double stop = u.getCounter();

        Utilities<T>::printArray(arr, right+1, "twoja tablica po sortowaniu"); //print sorted
        Utilities<T>::printColorText(hConsole, ("\nczas sortowania " + to_string(stop) + " [s]"), CYAN);
    }
}

template <typename T>
int Quicksort<T>::partitionLeft(T arr[], int left, int right) {
    int pivotElement = arr[left];
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

template <typename T>
int Quicksort<T>::partitionRight(T arr[], int left, int right) {
    int pivotElement = arr[right];
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

template <typename T>
int Quicksort<T>::partitionCenter(T arr[], int left, int right) {
    int pivotElement = arr[left + (right-left) /2];
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

template <typename T>
int Quicksort<T>::partitionRandom(T arr[], int left, int right) {
    srand(time(0));
    int pivotRandom = left + rand() % (right - left +1);
    int pivotElement = arr[pivotRandom];
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