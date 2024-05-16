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

// fixujemy nasz kopiec tylko na samym poczatku, potem usuwamy z niego korzen i ten element korzen idzie juz do posortowanej tablicy
// i potem znowu fixujemy po usunieciu (ale to juz jest w algorytmie usuwania korzenia, fixujemy wtedy od lewej) i znowu usuwamy korzen
// gdy juz caly kopiec jest posortowany

//budujemy kopiec maksymalny, zamieniamy korzen z ostatnim elementem, jako juz
//do posortowanej tablicy, i tak rekurencyjnie dla coraz to mniejszych podproblemow

template <typename T>
void Heapsort<T>::heapsortAlgorithm() {
    //budujemy kopiec maksymalny, idziemy od dolu do gory
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
    // budujemy kopiec z drzewa binarnego otrzymanego
    //czyli majac tablice [1, 2, 3] mamy drzewo           1
                                                   // 2       3
// a wiec wywolujemy na roocie ta funkcje, potem gdy naprawimy to drzewo nawieksze, robimy to dla kazdego poddrzewa czyli potem dla elementu 2

    int largest = i;
    int l = 2 * i + 1; //index lewego dziecka
    int r = 2 * i + 2; //index praweo dziecka

    // gdy lewe dziecko jest wieksze od roota
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // gdy prawe dziecko jest wieksze od najwiekszego
    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]); //bierzemy najwieksze z dzieci i zamieniamy z rodzicem

        heapify(arr, n, largest); //sprawdzamy poddrzewa, to jest juz nie dla ostatniego poziomu tylko wyzej, sprawdzamy ze gdy zamienilismy jakis korzen
        // to czy to poddrzewo ktore juz wczesniej zostalo naprawione dalej spelnia warunkji kopca maksymalnego
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