#include "../Headers/Utilities.h"
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"
#include "windows.h"

using namespace std;

Utilities::Utilities() {

}

void Utilities::printArray(int *arr, int len, string mes){
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

void Utilities::copyArray(int *arr,  int arrayCopy[], int len) {
    for (int i = 0; i < len; ++i) {
        arrayCopy[i] = arr[i];
    }
}

void Utilities::startCounter() {
    PCFreq = 0.0;
    start = 0;

    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
        cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart)/1000.0;

    QueryPerformanceCounter(&li);
    start = li.QuadPart;
}
double Utilities::getCounter() {
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-start)/PCFreq;
}