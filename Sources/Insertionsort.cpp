#include "../Headers/Insertionsort.h"
#include "iostream"

using namespace std;

Insertionsort::Insertionsort() {

}

void Insertionsort::sort(int *arr, int len, int left, int right) {
    u.startCounter();

    int i, key, j;
    for (i = 1; i < len; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    SetConsoleTextAttribute(hConsole, MAGENTA); //colors
    cout<<"czas sortowania: "<<u.getCounter()<<" [s]"<<endl;
    SetConsoleTextAttribute(hConsole, WHITE); //colors

    return;
}