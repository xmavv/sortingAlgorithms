#ifndef PROJEKT_SORTOWANIE_EVENT_H
#define PROJEKT_SORTOWANIE_EVENT_H

#endif //PROJEKT_SORTOWANIE_EVENT_H

#include "iostream"

using namespace std;

class Event {
    int day, month, year;
    int hour, minutes;
    string name;

public: //udostepniam interaface taki
    Event(string="brak", int=1,int=1,int=2015,int=12,int=0);
    ~Event();
    void load();
    void show();
};
