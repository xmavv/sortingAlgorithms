#include "../Headers/Menu.h"
#include "../Headers/Print.h"
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"
#include "fstream"

using namespace std;

void Menu::start() {
    cout<<"witaj w projekcie sortowanie!"<<endl;
    cout<<endl<<"wybierz sposob podania danych"<<endl;
    cout<<"1. wygeneruj losowo dane o zadanej dlugosci"<<endl;
    cout<<"2. wczytaj dane z pliku"<<endl;
    cin>>userChoice;

    if(userChoice == 1) {
        cout<<"podaj rozmiar tablicy"<<endl;
        cin>>arrayLength;
        this->generateRandomArray(arrayLength); //global arrayToSort variable changed, so we can work with it
        this->chooseAlgorithm();
    } else if(userChoice == 2) {
        string fileName;

        cout<<"podaj nazwe pliku (plik musi znajdowac sie w folderze /cmake-build-debug/!)"<<endl;
        cin>>fileName;
        this->loadArrayFromFile(fileName); //global arrayToSort variable changed, so we can work with it
        this->chooseAlgorithm();
    } //validation
}

void Menu::generateRandomArray(int len){
    arrayToSort = new int [len];
    int *pointer = arrayToSort;

    srand(time(NULL));

    for(int i=0; i<len; i++) {
        *pointer = rand()%200-100; //from -100 to 100
        pointer++;
    }

    Print::printArray(arrayToSort, len, "twoja tablica");
}

void Menu::loadArrayFromFile(string name) {
    fstream file;
    file.open(name,ios::in);

    if(!file.is_open()){
        cerr<<"nie udalo sie otworzyc pliku!"<<endl;
        exit(1);
    }

    string line;

    if(getline(file, line)) {
        arrayLength = stoi(line); //StringTOInt
    }

    arrayToSort = new int [arrayLength];
    int *pointer = arrayToSort;

    while(getline(file, line)) {
        *pointer = stoi(line);
        pointer++;
    }

    Print::printArray(arrayToSort, arrayLength, "twoja tablica");
}

void Menu::chooseAlgorithm() {
    cout<<"wybierz algorytm"<<endl;
    cout<<"1. insertionsort"<<endl;
    cout<<"2. quicksort"<<endl;
    cout<<"3. shellsort"<<endl;
    cout<<"4. heapsort"<<endl;
    cin>>userChoice;

    if(userChoice == 1) {
        algorithm = &insertionsort;
        algorithm -> sort(arrayToSort, arrayLength);
        cout<<"wybrales"<<userChoice<<"algorytm"<<endl;
    } else if (userChoice == 2) {
        algorithm = &quicksort;
        algorithm -> sort(arrayToSort, arrayLength);
        cout<<"wybrales"<<userChoice<<"algorytm"<<endl;
    } else if (userChoice == 3) {
        algorithm = &shellsort;
        algorithm -> sort(arrayToSort, arrayLength);
        cout<<"wybrales"<<userChoice<<"algorytm"<<endl;
    } else if (userChoice == 4) {
        algorithm = &heapsort;
        algorithm -> sort(arrayToSort, arrayLength);
        cout<<"wybrales"<<userChoice<<"algorytm"<<endl;
    } //validation
}