#include "iostream"
#include "../Headers/App.h"
#include "../Headers/Menu.h"
#include "../Headers/Insertionsort.h"

using namespace std;

void App::run() {
//    int variableType;
//
//    while(true) {
//        cout << "witaj w projekcie sortowanie! poruszając się po menu korzystaj tylko z cyfr!" << endl << endl;
//        cout << "--------------------MENU-1--------------------" << endl << endl;
//        cout << endl << "wybierz typ danych na ktorym chcesz pracowac" << endl;
//        cout << "1. int" << endl;
//        cout << "2. float" << endl;
//        cout << "3. char" << endl<<endl;
//        cout<<"lub: "<<endl<<endl;
//        cout << "0. wyjdz z programu" << endl;
//        cin>>variableType;
//
//        if(variableType == 1) {
//            Menu<int> menu1(variableType);
//            menu1.chooseArray();
//        } else if(variableType == 2) {
//            Menu<float> menu2(variableType);
//            menu2.chooseArray();
//        } else if(variableType == 3) {
//            Menu<char> menu3(variableType);
//            menu3.chooseArray();
//        } else if(variableType == 0) {
//            exit(0);
//        } else {
//            cerr << "nieprawidlowy wybor!" << endl;
//        }
//    }
}

void App::test() {
    double sum = 0;
    int length = 10000;
    int iterations = 100;

    for(int i=0; i<iterations; i++) {
        Menu<int> menu1(1); //1 int, 2 float, 3 char

        int *arrayToSort = menu1.generateRandomArray(length); //genrate random array each time
        int arrayCopy[length];

        Utilities<int>::copyArray(arrayToSort, arrayCopy, length); //menus, returning time
        double time = menu1.choosePreSort(arrayCopy);

        cout<<time<<endl;

        sum+=time;
    }

    cout<<endl<<endl<<endl<<"srednia: [ms] "<<sum/iterations;
}