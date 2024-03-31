#include "../Headers/Insertionsort.h"
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"
#include "windows.h"

using namespace std;

Insertionsort::Insertionsort() {

}

void Insertionsort::sort(int *arr, int len) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

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

    SetConsoleTextAttribute(hConsole, 13); //colors
    cout<<"czas sortowania: "<<u.getCounter()<<" [s]"<<endl;
    SetConsoleTextAttribute(hConsole, 7); //colors

    return;
}