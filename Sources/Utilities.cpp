#include "../Headers/Utilities.h"
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"
#include "windows.h"

using namespace std;

template <typename T>
void Utilities<T>::printArray(T *arr, int len, string mes){
    cout<<mes<<": [";

    for (int i = 0; i < len; ++i) {
        i == len-1 ? cout<<*arr : cout<<*arr<<", ";
        arr++;
    }
    cout<<"]"<<endl<<endl<<endl;

    cout<<"nacisnij dowolny klawisz aby kontynuowac..."<<endl;
    cin.ignore();
    cin.get();
}

template <typename T>
void Utilities<T>::copyArray(T *arr,  T arrayCopy[], int len) {
    for (int i = 0; i < len; ++i) {
        arrayCopy[i] = arr[i];
    }
}

template <typename T>
void Utilities<T>::startCounter() {
    PCFreq = 0.0;
    start = 0;

    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
        cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart)/1000.0;

    QueryPerformanceCounter(&li);
    start = li.QuadPart;
}

template <typename T>
double Utilities<T>::getCounter() {
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-start)/PCFreq;
}

template <typename T>
void Utilities<T>::printColorText(HANDLE console, string message, int color) {
    SetConsoleTextAttribute(console, color);
    cout<<endl<<message<<endl<<endl;
    SetConsoleTextAttribute(console, WHITE);
}

template class Utilities<int>;
template class Utilities<float>;
template class Utilities<char>;