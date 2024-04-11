#include "iostream"
#include "../Headers2/Przyjaciele.h"
#include "math.h"

using namespace std;

Punkt::Punkt(string name, float x, float y) {
    this->name = name;
    this->x = x;
    this->y = y;
}

void Punkt::print() {
    cout<<name<<endl;
    cout<<x<<endl;
    cout<<y<<endl;
}

Kolo::Kolo(string name, string nameP, float x, float y, float r): Punkt(nameP, x, y) {
    this->name = name;
    this->r = r;
}

void Kolo::print() {
    cout<<"kolo o nazwie "<<name<<endl;
    cout<<"srodek kola "<<endl;
    Punkt::print();
    cout<<"radius "<<r<<endl;
    cout<<"pole kola "<<M_PI*r*r<<endl;
}