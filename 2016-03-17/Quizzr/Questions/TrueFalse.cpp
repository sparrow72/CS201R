#include "TrueFalse.hpp"

#include <iostream>
using namespace std;

void TrueFalse::CreateQuestion()
{
    cout << "Please type in you question: ";
    cin.ignore();
    getline(cin, question);
    cout << "Is the question true or false (ture/false): ";
    loop = false;
    do {///gets line of answer. repeats if the line does not start with t or f.
        getline(cin, answer);
        string::size_type i = 0;
        switch (tolower(answer[i], loc))
            ///test the first key for correct input
        {
        case 't':
            ans = true;
            loop = true;
            break;
        case 'f':
            ans = false;
            loop = true;
            break;
        default:
            loop = false;
            cout << "Invalid, please try again\nIs the question true or false (ture/false): ";
            break;
        }
    } while (!loop);
}
void TrueFalse::Display()
{
    loop = false;
    cout << "True or false: " << question;
    do {///gets line of answer. repeats if the line does not start with t or f.
        getline(cin, answer);
        string::size_type i = 0;
        switch (tolower(answer[i], loc))
            ///test the first key for correct input
        {
        case 't':
            ans1 = true;
            loop = true;
            break;
        case 'f':
            ans1 = false;
            loop = true;
            break;
        default:
            loop = false;
            cout << "Invalid, please try again\nIs the question true or false (ture/false): ";
            break;
        }
    } while (!loop);
}

bool TrueFalse::Answer()
{
    if (ans == ans1)
        return true;
    else
        return false;
}
