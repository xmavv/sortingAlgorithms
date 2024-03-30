#include "../Headers/Utilities.h"
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"

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