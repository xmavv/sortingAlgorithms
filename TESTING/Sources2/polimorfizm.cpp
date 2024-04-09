#include <iostream>
#include "stdio.h"
#include "math.h"

//POLIMORFIZM

using namespace std;

class Ksztalt {
public:
    virtual void obliczPole() = 0; //czysta funkcja wirtualna
};

class Kwadrat :public Ksztalt {
    float a;
public:
    Kwadrat(float a){
        this->a = a;
    }

    virtual void obliczPole() {
        cout<<a*a<<endl;
    }
};

class Kolo :public Ksztalt{
    float r;
public:
    Kolo(float r){
        this->r = r;
    }

    virtual void obliczPole() {
        cout<<M_PI*r*r<<endl;
    }
};

void obliczenia(Ksztalt *x){
    x -> obliczPole();
}

//int main() {
//    Kolo k(1);
//    Kwadrat kw(2);
//
//    Ksztalt *wsk;
//
//    wsk = &k;
//    wsk -> obliczPole();
//
//    wsk = &kw;
//    wsk -> obliczPole();
//
//    obliczenia(wsk);
//
//    return 0;
//}