#include "../Headers/Menu.h"
#include "../Headers/Utilities.h"
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"
#include "fstream"

using namespace std;

void Menu::chooseArray() {
    string fileName;

    while(userChoice != 1 || userChoice!= 2) {
        cout<<"witaj w projekcie sortowanie!"<<endl<<endl;
        Utilities::printColorText(hConsole, "--------------------MENU--------------------\n\n", YELLOW);
        cout<<endl<<"wybierz sposob podania danych (korzystaj tylko z cyfr!)"<<endl;
        cout<<"1. wygeneruj losowo dane o zadanej dlugosci"<<endl;
        cout<<"2. wczytaj dane z pliku"<<endl;
        cout<<"0. wyjdz z programu"<<endl;
        cin>>userChoice;

        switch(userChoice) {
            case 1:
                Utilities::printColorText(hConsole, "podaj rozmiar tablicy ", MAGENTA);
                cin>>arrayLength;
                generateRandomArray(arrayLength); //global arrayToSort variable changed, so we can work with it
                chooseAlgorithm();
                break;
            case 2:
                Utilities::printColorText(hConsole, "podaj nazwe pliku (plik tekstowy musi znajodwac sie w tym samym folderze co plik wykonywalny programu!) ", MAGENTA);
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
        *pointer = rand()%2000-1000; //from -100 to 100
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


        Utilities::printColorText(hConsole, "--------------------MENU--------------------\n\n", YELLOW);
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
                Utilities::printColorText(hConsole, "wybrales insertionsort\n", GREEN);

                insertionsort.setArray(arrayCopy, arrayLength);
                algorithm = &insertionsort;
                startAlgorithm(algorithm);

                Utilities::printArray(arrayCopy, arrayLength, "twoja tablica po sortowaniu"); //print sorted
                break;
            case 2:
                Utilities::printColorText(hConsole, "wybrales quicksort\n", GREEN);
                cout<<"wybierz pivot"<<endl;
                cout<<"1. skrajny lewy"<<endl;
                cout<<"2. skrajny prawy"<<endl;
                cout<<"3. srodkowy"<<endl;
                cout<<"4. losowy"<<endl;
                cin>>userChoice;

                quicksort.setArray(arrayCopy, 0, (arrayLength-1), userChoice);
                algorithm = &quicksort;
                startAlgorithm(algorithm);

                Utilities::printArray(arrayCopy, arrayLength, "twoja tablica po sortowaniu");
                break;
            case 3:
                Utilities::printColorText(hConsole, "wybrales shellsort\n", GREEN);
                cout<<"wybierz typ"<<endl;
                cout<<"1. sekwencja marcin ciura"<<endl;
                cout<<"2. sekwencja n/2"<<endl;
                cin>>userChoice;

                shellsort.setArray(arrayCopy, arrayLength, userChoice);
                algorithm = &shellsort;
                startAlgorithm(algorithm);

                Utilities::printArray(arrayCopy, arrayLength, "twoja tablica po sortowaniu");
                break;
            case 4:
                Utilities::printColorText(hConsole, "wybrales heapsort\n", GREEN);

                heapsort.setArray(arrayCopy, arrayLength);
                algorithm = &heapsort;
                startAlgorithm(algorithm);

                Utilities::printArray(arrayCopy, arrayLength, "twoja tablica po sortowaniu");
                break;
            case 5:
                Utilities::printArray(arrayCopy, arrayLength, "twoja aktualna tablica");
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

void Menu::startAlgorithm(Algorithm *a) {
    u.startCounter(); //start timer
    algorithm -> sort(); // sort
    double stop = u.getCounter();
    Utilities::printColorText(hConsole, ("\nczas sortowania " + to_string(stop) + " [s]"), CYAN);
}
