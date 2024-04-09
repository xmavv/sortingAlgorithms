#include "iostream"
#include "../Headers2/event.h"
using namespace std;

void Event::load(){
    cout<<endl<<"nazwa: ";
    cin>>name;
    cout<<endl<<"dzien: ";
    cin>>day;
    cout<<endl<<"miesiac: ";
    cin>>month;
    cout<<endl<<"rok: ";
    cin>>year;
    cout<<endl<<"godzina: ";
    cin>>hour;
    cout<<endl<<"minuta: ";
    cin>>minutes;
}

void Event::show() {
    cout<<endl<<name<<" "<<day<<"."<<month<<"."<<year<<" "<<hour<<":"<<minutes<<endl;
}

Event::Event(string n, int d, int m , int y, int h, int mins){
    name = n;
    day = d;
    month = m;
    year = y;
    hour = h;
    minutes = mins;
}

Event::~Event() {
    cout<<endl<<"destruktor dziala";
}