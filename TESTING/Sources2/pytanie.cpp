#include "iostream"
#include "../Headers2/pytanie.h"
#include "fstream"
#include "iosfwd"

using namespace std;

void Question::getQuestion(){
    fstream file;
    file.open("../Sources2/quiz.txt",ios::in); //program jest executable wiec jest w cmake-build-debug

    if(!file.is_open()){
        cerr<<"nie udalo sie otworzyc pliku!"<<endl;
        exit(1);
    }
    int lineNumber = (qNumber-1)*6+1;
    int currNumber = 1;
    string line;

    while(getline(file, line)){
        if(currNumber == lineNumber) title = line;
        if(currNumber == lineNumber+1) a = line;
        if(currNumber == lineNumber+2) b = line;
        if(currNumber == lineNumber+3) c = line;
        if(currNumber == lineNumber+4) d = line;
        if(currNumber == lineNumber+5) rightAnswer = line;
        currNumber++;
    }

    file.close();
};

void Question::printAndValidateAnswer(){
    point = 0;

    cout<<endl<<title<<endl;
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    cout<<d<<endl;
    cout<<endl<<"======================================="<<endl;

    cout<<"Your answer: ";
    cin>>userAnswer;
};

void Question::checkAnswer(){
    if(userAnswer == rightAnswer) {
        cout<<"mega jestes ziomek"<<endl;
        point = 1;
    } else {
        cout<<"zle xddd"<<endl;
    }
};