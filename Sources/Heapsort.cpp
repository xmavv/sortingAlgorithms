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

template <typename T>
void Heapsort<T>::heapsortAlgorithm() {
    for (int i = len / 2 - 1; i >= 0; i--) heapify(arr, len, i);

    // One by one extract an element from heap
    for (int i = len - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
    return;
}

template <typename T>
void Heapsort<T>::heapify(T arr[], int n, int i) {
    int largest = i; // Initialize largest as root Since we are using 0 based indexing
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
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