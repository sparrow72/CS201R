#include "Essay.hpp"

#include <iostream>
using namespace std;

void Essay::CreateQuestion()
{
    cout << "Enter a question  >> ";
    cin.ignore();
    getline(cin, Question);

    cout << "\n" << "Enter the correct answer to your question  >> ";
    cin.ignore();
    getline(cin, correctAnswer);

}

void Essay::Display()
{
    cout << Question << endl;
}

bool Essay::Answer()
{
    cout << "Enter the correct answer  >> ";
    cin.ignore();
    getline(cin, answer);


    if (answer == correctAnswer)
    {
        return true;
    }
    else
    {
        return false;
    }
}
