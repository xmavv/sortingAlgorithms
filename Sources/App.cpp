#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"
#include "../Headers/Menu.h"
#include "../Headers/App.h"

using namespace std;

void App::run() {
    int variableType = 1;

    while(true) {
        cout << "witaj w projekcie sortowanie!" << endl << endl;
        cout << "--------------------MENU-1--------------------" << endl << endl;
        cout << endl << "wybierz typ danych na ktorym chcesz pracowac" << endl;
        cout << "1. int" << endl;
        cout << "2. float" << endl;
        cout << "3. char" << endl;
        cout << "0. wyjdz z programu" << endl;
        cin>>variableType;

        if(variableType == 1) {
            Menu<int> menu1(variableType);
            menu1.chooseArray();
        } else if(variableType == 2) {
            Menu<float> menu2(variableType);
            menu2.chooseArray();
        } else if(variableType == 3) {
            Menu<char> menu3(variableType);
            menu3.chooseArray();
        } else if(variableType == 0) {
            exit(0);
        } else {
            cerr<<"nieprawidlowy wybor!"<<endl;
        }
    }
}