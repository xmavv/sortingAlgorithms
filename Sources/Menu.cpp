#include "../Headers/Menu.h"
#include "../Headers/Utilities.h"
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"
#include "fstream"
#include "algorithm"

using namespace std;

template <typename T>
Menu<T>::Menu(int variableType) {
    this -> variableType = variableType;
}

template <typename T>
void Menu<T>::chooseArray() {
    string fileName;

    while(true) {
        u.printColorText(hConsole, "--------------------MENU-2--------------------", YELLOW);
        cout<<endl<<"wybierz sposob podania danych"<<endl;
        cout<<"1. wygeneruj losowo dane o zadanej dlugosci"<<endl;
        cout<<"2. wczytaj dane z pliku"<<endl<<endl;
        cout<<"lub: "<<endl<<endl;
        cout<<"9. wyjdz do menu-1"<<endl;
        cout<<"0. wyjdz z programu"<<endl;
        cin>>userChoice;

        switch(userChoice) {
            case 1:
                Utilities<T>::printColorText(hConsole, "podaj rozmiar tablicy ", MAGENTA);
                cin>>arrayLength;
                generateRandomArray(arrayLength); //global arrayToSort variable changed, so we can work with it
                choosePreSort();
                break;
            case 2:
                Utilities<T>::printColorText(hConsole, "podaj nazwe pliku (plik tekstowy musi znajodwac sie w tym samym folderze co plik wykonywalny programu!) ", MAGENTA);
                cin>>fileName;
                loadArrayFromFile(fileName);
                choosePreSort();
                break;
            case 9:
                return;
            case 0:
                exit(0);
            default:
                cerr<<"niepoprawny wybor!"<<endl;
        }

        if(userChoice == 0) return;
    }
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
void Menu<T>::choosePreSort() {
    T originalArray[arrayLength]; //copying original array to delete the pointer
    Utilities<T>::copyArray(arrayToSort, originalArray, arrayLength);
    delete [] arrayToSort;

    while(userChoice != 0) {
        T arrayCopy[arrayLength]; //copying "original" array each time, so I have access to the one generated or loaded
        Utilities<T>::copyArray(originalArray, arrayCopy, arrayLength);

        Utilities<T>::printColorText(hConsole, "--------------------MENU-3--------------------", YELLOW);
        cout<<"wybierz pre-sort:"<<endl<<endl;
        cout<<"1. nie zmieniam aktualnej tablicy"<<endl;
        cout<<"2. posortowana rosnaco"<<endl;
        cout<<"3. posortowana malejaco"<<endl;
        cout<<"4. 33% sort"<<endl;
        cout<<"5. 66% sort"<<endl<<endl;
        cout<<"lub: "<<endl<<endl;
        cout<<"6. pokaz aktualna tablice"<<endl;
        cout<<"9. wyjdz do menu-2"<<endl;
        cout<<"0. wyjdz z programu"<<endl;
        cin>>userChoice;

        switch (userChoice) {
            case 1:
                chooseAlgorithm(arrayCopy);
                break;
            case 2:
                Utilities<T>::printColorText(hConsole, "wybrales sortowanie rosnoca\n", GREEN);

                std::sort(arrayCopy, arrayCopy + arrayLength);

                Utilities<T>::printArray(arrayCopy, arrayLength, "twoja tablica po pre-sortowaniu"); //print pre-sorted
                chooseAlgorithm(arrayCopy);
                break;
            case 3:
                Utilities<T>::printColorText(hConsole, "wybrales sortowanie malejace\n", GREEN);

                std::sort(arrayCopy, arrayCopy + arrayLength, std::greater<int>());

                Utilities<T>::printArray(arrayCopy, arrayLength, "twoja tablica po pre-sortowaniu"); //print pre-sorted
                chooseAlgorithm(arrayCopy);
                break;
            case 4:
                Utilities<T>::printColorText(hConsole, "wybrales sortowanie 33%\n", GREEN);

                presort.preSortPart(arrayCopy, arrayLength, userChoice);

                Utilities<T>::printArray(arrayCopy, arrayLength, "twoja tablica po pre-sortowaniu"); //print pre-sorted
                chooseAlgorithm(arrayCopy);
                break;
            case 5:
                Utilities<T>::printColorText(hConsole, "wybrales sortowanie 66%\n", GREEN);

                presort.preSortPart(arrayCopy, arrayLength, userChoice);

                Utilities<T>::printArray(arrayCopy, arrayLength, "twoja tablica po pre-sortowaniu"); //print pre-sorted
                chooseAlgorithm(arrayCopy);
                break;
            case 6:
                Utilities<T>::printArray(arrayCopy, arrayLength, "twoja aktualna tablica");
                break;
            case 9:
                chooseArray();
                break;
            case 0:
                exit(0);
            default:
                cerr<<"niepoprawny wybor!"<<endl;
                break;
        }
    }
    return;
}

template <typename T>
void Menu<T>::chooseAlgorithm(T *originalArray) {
    while(userChoice != 0) {
        T arrayCopy[arrayLength]; //copying "original" array each time, so I have access to the one generated or loaded
        Utilities<T>::copyArray(originalArray, arrayCopy, arrayLength);

        Utilities<T>::printColorText(hConsole, "--------------------MENU-4--------------------", YELLOW);
        cout<<"wybierz algorytm:"<<endl<<endl;
        cout<<"1. insertionsort"<<endl;
        cout<<"2. quicksort"<<endl;
        cout<<"3. shellsort"<<endl;
        cout<<"4. heapsort"<<endl<<endl;
        cout<<"lub: "<<endl<<endl;
        cout<<"5. pokaz aktualna tablice"<<endl;
        cout<<"9. wyjdz do menu-3"<<endl;
        cout<<"0. wyjdz z programu"<<endl;
        cin>>userChoice;

        switch (userChoice) {
            case 1:
                Utilities<T>::printColorText(hConsole, "wybrales insertionsort\n", GREEN);

                insertionsort.setArray(arrayCopy, arrayLength);
                algorithm = &insertionsort;

                startAlgorithm(algorithm);
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
                break;
            case 4:
                Utilities<T>::printColorText(hConsole, "wybrales heapsort\n", GREEN);

                heapsort.setArray(arrayCopy, arrayLength);
                algorithm = &heapsort;
                startAlgorithm(algorithm);
                break;
            case 5:
                Utilities<T>::printArray(arrayCopy, arrayLength, "twoja aktualna tablica");
                break;
            case 9:
                choosePreSort();
                break;
            case 0:
                exit(0);
            default:
                cerr<<"niepoprawny wybor!"<<endl;
                break;
        }
    }
    return;
}

template <typename T>
void Menu<T>::startAlgorithm(Algorithm<T> *a) {
    algorithm -> sort(); // sort
}

template class Menu<int>;
template class Menu<float>;
template class Menu<char>;