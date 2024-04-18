#include "../Headers/Heapsort.h"
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"

using namespace std;

template <typename T>
void Heapsort<T>::setArray(T *arr, int len) {
    this -> arr = arr;
    this -> len = len;
}

//budujemy kopiec maksymalny, zamieniamy korzen z ostatnim elementem, jako juz
//do posortowanej tablicy, i tak rekurencyjnie dla coraz to mniejszych podproblemow

template <typename T>
void Heapsort<T>::heapsortAlgorithm() {
    //budujemy kopiec maksymalny
    for (int i = len / 2 - 1; i >= 0; i--) heapify(arr, len, i);

    // wez element z kopca
    for (int i = len - 1; i >= 0; i--) {
        // zamien wierzcholek z koncowym elementem
        swap(arr[0], arr[i]);

        // wywolaj heapify pomijajac ten ostatni element
        heapify(arr, i, 0);
    }
    return;
}

template <typename T>
void Heapsort<T>::heapify(T arr[], int n, int i) {
    int largest = i; //najwiekszy node na podstawie biezacego indeksu
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // gdy lewe dziecko jest wieksze od roota
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // gdy prawe dziecko jest wieksze od najwiekszego
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // gdy najwiekszy to nie root wywolaj funkcje znowu
    //chcemy zbudowac kopiec maksymalny
    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

template <typename T>
void Heapsort<T>::sort() {
    u.startCounter(); //start timer

    heapsortAlgorithm(); //actual sort

    double stop = u.getCounter();

    cout<<"czy chcesz zobaczyc posortowana tablice?"<<endl;
    cout<<"1. tak"<<endl;
    cout<<"2. nie"<<endl;
    cin>>userChoice;

    if(userChoice == 1) {
        Utilities<T>::printArray(arr, len, "twoja tablica"); //print pre-sorted
    }
    Utilities<T>::printColorText(hConsole, ("\nczas sortowania " + to_string(stop) + " [ms]"), CYAN);
}

template class Heapsort<int>;
template class Heapsort<float>;
template class Heapsort<char>;