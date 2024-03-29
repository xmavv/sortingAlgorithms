#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"
using namespace std;
int ile;
clock_t start, stop;
double czas;

void howToUsePointers() {
    int liczba = 144;
    int *w;
    w = &liczba;
    cout<<w<<endl;
    cout<<*w<<endl;
    cout<<"witam"<<endl;
}

void howMany() {
    cout<<"ile liczb w tablicy"; cin>>ile;

    int *tablica;
    tablica = new int [ile];

    for(int i=0; i<ile; i++){
        cout<<tablica<<endl;
        tablica++; //przesuwamy wskaznik
    }

    delete [] tablica;
}

void compare() {
    cout<<"ile liczb w tablicy"; cin>>ile;

    int *tablica;
    tablica = new int [ile];

    start = clock();

    for(int i=0; i<ile; i++){
        tablica[i] = i;
        tablica[i]+=50;
    }

    stop = clock(); // to liczy liczbe cykli
    czas = (double)(stop-start)/CLOCKS_PER_SEC; //c++ pobiera ta stala srodowiskowa ile cykli nasz procesor wykonuje na sekunde
    cout<<czas<<endl;

    delete [] tablica;




    int *tablica2;
    tablica2 = new int [ile];
    int *wsk = tablica2;

    start = clock();

    for(int i=0; i<ile; i++){
        *wsk = i;
        *wsk+=50;
        wsk++;
    }

    stop = clock();
    czas = (double)(stop-start)/CLOCKS_PER_SEC;
    cout<<"ze wskaznikiem"<<czas<<endl;

    delete [] tablica2;
}

float avg(float *array, int ile){
    float suma =0;

    for(int i=0; i<ile; i++){
        suma+=*array;
        *array = 999;
        array++;
    }

    return suma/ile;
}

int main() {
    float tablica[3];

    tablica[0] = 1.5;
    tablica[1] = 2.3;
    tablica[2] = 0.75;

    cout<<"srednia"<<avg(tablica, 3);

    cout<<tablica[0]<<endl;
    cout<<tablica[1]<<endl;
    cout<<tablica[2]<<endl;

    return 0;
}