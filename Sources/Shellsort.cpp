#include <vector>
#include "../Headers/Shellsort.h"
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"

using namespace std;

template <typename T>
void Shellsort<T>::setArray(T *arr, int len, int type) {
    this -> arr = arr;
    this -> len = len;
    this -> type = type;
}

template <typename T>
void Shellsort<T>::sort() {
    type == 1 ? shellsortMarcinciur(arr, len) : shellsortN2(arr, len);

    if(type == 1) {
        u.startCounter(); //start timer

        shellsortMarcinciur(arr, len);

        double stop = u.getCounter();

        cout<<"czy chcesz zobaczyc posortowana tablice?"<<endl;
        cout<<"1. tak"<<endl;
        cout<<"2. nie"<<endl;
        cin>>userChoice;

        if(userChoice == 1) {
            Utilities<T>::printArray(arr, len, "twoja tablica"); //print pre-sorted
        }
        Utilities<T>::printColorText(hConsole, ("\nczas sortowania " + to_string(stop) + " [ms]"), CYAN);
    } else {
        u.startCounter(); //start timer

        shellsortN2(arr, len);

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

    return;
}

template <typename T>
void Shellsort<T>::shellsortN2(T *arr, int len) {
    //zmniejszamy nasz gap o polowe w kazdej iteracji zaczynajac od polowy dlugosci tablicy
    for (int gap = len/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < len; i++)
        {
            T temp = arr[i];
            //sprawdzam zawsze z elementem oddalonym o "jeden gap" w lewo i potem ide znowu i++
            //czyli [0, 1, 2, 3, 4] sprawdze dla 2 z 0 potem dla 3 z 1 potem dla 4 z 2 czyli ta dwojka zostanie i tak poruszona i tak caly czas
            int j; //idziemy w lewo i sprawdzamy czy element oddalony od gap jest wiekszy, jezeli tak to go zamieniamy
            // j >= gap gdyby tak nie bylo wyszlibysmy poza zakres tablicy
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) arr[j] = arr[j - gap]; //za kazdym razem musze sprawdzac max w lewo czy nie zamienic elementow ze soba
                                                                                            //w sensie elementu po prawej ktory jest najmniejszy to musze przejsc
                                                                                            //przez cale gapy w lewo az zamienie

            arr[j] = temp; //cos jak key w insertionsort
        }
    }
}

template <typename T>
void Shellsort<T>::shellsortMarcinciur(T *arr, int len) {
    // juz wczesniej wyznaczona tablica odlegosci
    int gaps[] = {701, 301, 132, 57, 23, 10, 4, 1};

    for (int gap : gaps) {
        for (int i = gap; i < len; i++) {
            T temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

template class Shellsort<int>;
template class Shellsort<float>;
template class Shellsort<char>;