#include "../Headers/Insertionsort.h"
#include "iostream"

using namespace std;

template <typename T>
void Insertionsort<T>::setArray(T *arr, int len) {
    this -> arr = arr;
    this -> len = len;
}

template <typename T>
void Insertionsort<T>::insertionsortAlgorithm() {

    int i, j;
    double key;

    //porownujemy kolejne elementy
    for (i = 1; i < len; i++) {
        key = arr[i];
        j = i - 1;

        //gdy sa w zlej kolejnosci, cofamy sie z tym elementem
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        //na koniec zamieniamy element ze zmienna key
        arr[j + 1] = key;
    }
    return;
}

template <typename T>
void Insertionsort<T>::sort() {
    u.startCounter(); //start timer

    insertionsortAlgorithm(); // actual sort
    double stop = u.getCounter();

    Utilities<T>::printArray(arr, len, "twoja tablica po sortowaniu"); //print sorted
    Utilities<T>::printColorText(hConsole, ("\nczas sortowania " + to_string(stop) + " [s]"), CYAN);
}

template class Insertionsort<int>;
template class Insertionsort<float>;
template class Insertionsort<char>;