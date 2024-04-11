#include "iostream"
using namespace std;

class Kolo;
class Punkt;

class Punkt {
    string name;
    float x, y;

public:
    Punkt(string = "S", float = 0, float = 0);
    void print();
};






class Kolo :public Punkt { //klasa Kolo dziedziczy publicznie z klasy Punkt
    float r;
    string name;

public:
    Kolo(string = "kolko", string = "S", float = 0, float = 0, float = 1);
    void print();
};