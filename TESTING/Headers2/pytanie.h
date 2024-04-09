#include "iostream"
using namespace std;

class Question{
public:
    int qNumber;
    int point; //1 lub 0

    void getQuestion(); //printing quesion from file
    void printAndValidateAnswer();
    void checkAnswer();
private:
    string title;
    string a, b, c, d;
    string rightAnswer;
    string userAnswer;
};