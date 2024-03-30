#include "../Headers/Print.h"
#include "stdio.h"
#include "iostream"
#include "time.h"
#include "cstdlib"

using namespace std;

Print::Print() {

}

void Print::printArray(int *arr, int len, string mes){
    cout<<mes<<": [";

    for (int i = 0; i < len; ++i) {
        i == len-1 ? cout<<*arr : cout<<*arr<<", ";
        arr++;
    }
    cout<<"]"<<endl;

    system("pause");
}