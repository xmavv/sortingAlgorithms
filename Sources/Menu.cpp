#include "../Headers/Menu.h"
#include "../Headers/Utilities.h"
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"
#include "fstream"

using namespace std;

void Menu::start() {
    string fileName;

    while(userChoice != 1 || userChoice!= 2) {
        cout<<"witaj w projekcie sortowanie!"<<endl;
        cout<<endl<<"wybierz sposob podania danych (korzystaj tylko z cyfr!)"<<endl;
        cout<<"1. wygeneruj losowo dane o zadanej dlugosci"<<endl;
        cout<<"2. wczytaj dane z pliku"<<endl;
        cout<<"0. wyjdz z programu"<<endl;
        cin>>userChoice;

        switch(userChoice) {
            case 1:
                cout<<"podaj rozmiar tablicy"<<endl;
                cin>>arrayLength;
                generateRandomArray(arrayLength); //global arrayToSort variable changed, so we can work with it
                chooseAlgorithm();
                break;
            case 2:
                cout<<"podaj nazwe pliku (plik musi znajdowac sie w folderze /cmake-build-debug/!)"<<endl;
                cin>>fileName;
                loadArrayFromFile(fileName); //global arrayToSort variable changed, so we can work with it
                chooseAlgorithm();
                break;
            case 0:
                exit(0);
            default:
                cerr<<"niepoprawny wybor!"<<endl;
                break;
        }
    }
}

void Menu::generateRandomArray(int len){
    arrayToSort = new int [len];
    int *pointer = arrayToSort;

    srand(time(NULL));

    for(int i=0; i<len; i++) {
        *pointer = rand()%200-100; //from -100 to 100
        pointer++;
    }

    Utilities::printArray(arrayToSort, len, "twoja tablica");
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

    Utilities::printArray(arrayToSort, arrayLength, "twoja tablica");
}

void Menu::chooseAlgorithm() {
    int originalArray[arrayLength]; //copying original array to delete the pointer
    Utilities::copyArray(arrayToSort, originalArray, arrayLength);
    delete [] arrayToSort;

    while(userChoice != 0) {
        int arrayCopy[arrayLength]; //copying "original" array each time, so I have access to the one generated or loaded
        Utilities::copyArray(originalArray, arrayCopy, arrayLength);

        cout<<"wybierz algorytm:"<<endl<<endl;
        cout<<"1. insertionsort"<<endl;
        cout<<"2. quicksort"<<endl;
        cout<<"3. shellsort"<<endl;
        cout<<"4. heapsort"<<endl<<endl;
        cout<<"lub: "<<endl<<endl;
        cout<<"5. pokaz aktualna tablice"<<endl;
        cout<<"0. wyjdz do menu"<<endl;
        cin>>userChoice;

        switch (userChoice) {
            case 1:
                cout<<"wybrales 1 algorytm"<<endl;
                algorithm = &insertionsort;
                algorithm -> sort(arrayCopy, arrayLength);
                break;
            case 2:
                cout<<"wybrales 2 algorytm"<<endl;
                algorithm = &quicksort;
                algorithm -> sort(arrayCopy, arrayLength);
                break;
            case 3:
                cout<<"wybrales 3 algorytm"<<endl;
                algorithm = &shellsort;
                algorithm -> sort(arrayCopy, arrayLength);
                break;
            case 4:
                cout<<"wybrales 4 algorytm"<<endl;
                algorithm = &heapsort;
                algorithm -> sort(arrayCopy, arrayLength);
                break;
            case 5:
                Utilities::printArray(arrayCopy, arrayLength, "twoja aktualna tablica");
                break;
            case 0:
                start();
                break;
            default:
                cerr<<"niepoprawny wybor!"<<endl;
                break;
        }
    }

    return;
}