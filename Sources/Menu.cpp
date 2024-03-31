#include "../Headers/Menu.h"
#include "../Headers/Utilities.h"
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"
#include "fstream"

using namespace std;

template <typename T>
Menu<T>::Menu(int variableType) {
    this -> variableType = variableType;
}

template <typename T>
void Menu<T>::chooseArray() {
    string fileName;

    while(userChoice != 1 || userChoice != 2 || userChoice != 0) {
        u.printColorText(hConsole, "--------------------MENU-2--------------------", YELLOW);
        cout<<endl<<"wybierz sposob podania danych (korzystaj tylko z cyfr!)"<<endl;
        cout<<"1. wygeneruj losowo dane o zadanej dlugosci"<<endl;
        cout<<"2. wczytaj dane z pliku"<<endl;
        cout<<"0. wyjdz do menu-1"<<endl;
        cin>>userChoice;

        switch(userChoice) {
            case 1:
                Utilities<T>::printColorText(hConsole, "podaj rozmiar tablicy ", MAGENTA);
                cin>>arrayLength;
                generateRandomArray(arrayLength); //global arrayToSort variable changed, so we can work with it
                chooseAlgorithm();
                break;
            case 2:
                Utilities<T>::printColorText(hConsole, "podaj nazwe pliku (plik tekstowy musi znajodwac sie w tym samym folderze co plik wykonywalny programu!) ", MAGENTA);
                cin>>fileName;
                loadArrayFromFile(fileName); //global arrayToSort variable changed, so we can work with it
                chooseAlgorithm();
                break;
            case 0:
                break;
            default:
                cerr<<"niepoprawny wybor!"<<endl;
                break;
        }
        return;
    }
    return;
}

template <typename T>
void Menu<T>::generateRandomArray(int len){
    arrayToSort = new T [len];
    T *pointer = arrayToSort;

    srand(time(NULL));

    if(variableType == 1) {
        for(int i=0; i<len; i++) {
            *pointer = rand()%2000-1000; //from -1000 to 1000
            pointer++;
        }
    } else if(variableType == 2) {
        for(int i=0; i<len; i++) {
            *pointer = -1000.0f + static_cast<float>(rand()) / (RAND_MAX / (1000.0f - -1000.0f)); //from -1000 to 1000
            pointer++;
        }
    } else {
        for(int i=0; i<len; i++) {
            *pointer = rand()%255; //from 0 to 255 https://pl.wikipedia.org/wiki/CP852
            pointer++;
        }
    }

    Utilities<T>::printArray(arrayToSort, len, "twoja tablica");
}

template <typename T>
void Menu<T>::loadArrayFromFile(string name) {
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

    arrayToSort = new T [arrayLength];
    T *pointer = arrayToSort;

    if(variableType == 1) {
        while(getline(file, line)) {
            *pointer = stoi(line);
            pointer++;
        }
    } else if(variableType == 2) {
        while(getline(file, line)) {
            cout<<line<<endl;
            *pointer = stof(line);
            pointer++;
        }
    } else {
        while (getline(file, line)) {
            *pointer = line[0];
            pointer++;
        }
    }

    Utilities<T>::printArray(arrayToSort, arrayLength, "twoja tablica");
}

template <typename T>
void Menu<T>::chooseAlgorithm() {
    T originalArray[arrayLength]; //copying original array to delete the pointer
    Utilities<T>::copyArray(arrayToSort, originalArray, arrayLength);
    delete [] arrayToSort;

    while(userChoice != 0) {
        T arrayCopy[arrayLength]; //copying "original" array each time, so I have access to the one generated or loaded
        Utilities<T>::copyArray(originalArray, arrayCopy, arrayLength);

        Utilities<T>::printColorText(hConsole, "--------------------MENU-3--------------------", YELLOW);
        cout<<"wybierz algorytm:"<<endl<<endl;
        cout<<"1. insertionsort"<<endl;
        cout<<"2. quicksort"<<endl;
        cout<<"3. shellsort"<<endl;
        cout<<"4. heapsort"<<endl<<endl;
        cout<<"lub: "<<endl<<endl;
        cout<<"5. pokaz aktualna tablice"<<endl;
        cout<<"0. wyjdz do menu-2"<<endl;
        cin>>userChoice;

        switch (userChoice) {
            case 1:
                Utilities<T>::printColorText(hConsole, "wybrales insertionsort\n", GREEN);

                insertionsort.setArray(arrayCopy, arrayLength);
                algorithm = &insertionsort;
                startAlgorithm(algorithm);

                Utilities<T>::printArray(arrayCopy, arrayLength, "twoja tablica po sortowaniu"); //print sorted
                break;
            case 2:
                Utilities<T>::printColorText(hConsole, "wybrales quicksort\n", GREEN);
                cout<<"wybierz pivot"<<endl;
                cout<<"1. skrajny lewy"<<endl;
                cout<<"2. skrajny prawy"<<endl;
                cout<<"3. srodkowy"<<endl;
                cout<<"4. losowy"<<endl;
                cin>>userChoice;

                quicksort.setArray(arrayCopy, 0, (arrayLength-1), userChoice);
                algorithm = &quicksort;
                startAlgorithm(algorithm);

                Utilities<T>::printArray(arrayCopy, arrayLength, "twoja tablica po sortowaniu");
                break;
            case 3:
                Utilities<T>::printColorText(hConsole, "wybrales shellsort\n", GREEN);
                cout<<"wybierz typ"<<endl;
                cout<<"1. sekwencja marcin ciura"<<endl;
                cout<<"2. sekwencja n/2"<<endl;
                cin>>userChoice;

                shellsort.setArray(arrayCopy, arrayLength, userChoice);
                algorithm = &shellsort;
                startAlgorithm(algorithm);

                Utilities<T>::printArray(arrayCopy, arrayLength, "twoja tablica po sortowaniu");
                break;
            case 4:
                Utilities<T>::printColorText(hConsole, "wybrales heapsort\n", GREEN);

                heapsort.setArray(arrayCopy, arrayLength);
                algorithm = &heapsort;
                startAlgorithm(algorithm);

                Utilities<T>::printArray(arrayCopy, arrayLength, "twoja tablica po sortowaniu");
                break;
            case 5:
                Utilities<T>::printArray(arrayCopy, arrayLength, "twoja aktualna tablica");
                break;
            case 0:
                chooseArray();
                break;
            default:
                cerr<<"niepoprawny wybor!"<<endl;
                break;
        }
    }
    return;
}

template <typename T>
void Menu<T>::startAlgorithm(Algorithm<T> *a) {
    u.startCounter(); //start timer
    algorithm -> sort(); // sort
    double stop = u.getCounter();
    Utilities<T>::printColorText(hConsole, ("\nczas sortowania " + to_string(stop) + " [s]"), CYAN);
}

template class Menu<int>;
template class Menu<float>;
template class Menu<char>;