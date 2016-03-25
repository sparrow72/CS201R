#include "Ordering.hpp"

#include <iostream>
using namespace std;

bool Ordering::ValidChoice(int min, int max, int choice)
{
    if (choice < min || choice > max)
    {
        cout << "Invalid Choice" << endl;
        return false;
    }
    return true;
}

void Ordering::CreateQuestion()
{

}

// Displays the question and answer(s)
void Ordering::Display()
{
    int answer;
    for (int i = 1; i < 5; i++)
    {
        cout << i << ") Question " << quest[i].Question << endl;
        for (int k = 1; k < 5; k++)
        {
            cout <<"    "<< k << ") " << quest[i].Answers[k] << endl;
        }
        while (true)
        {
            cin >> answer;
            if ((ValidChoice(1, 4, answer)))
            {
                break;
            }
        }

    }
}
bool Ordering::Answer()
{
    return true;
}
