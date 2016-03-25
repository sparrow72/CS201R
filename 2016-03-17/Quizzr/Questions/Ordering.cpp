#include "Ordering.hpp"

#include <iostream>
#include <string>
using namespace std;

#include "../Menu.hpp"

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
    bool Correct = false;
    string buffer;

    cout <<"What is your question? ";
    cin.ignore();
    getline(cin,question.Question);
    cout << endl;
    question.Answers.push_back(" ");


    for (int i = 1; i < 5; i++)
        {
            cout << "What is the " << i << "  answers for this question? " << endl;
            //cin.ignore();
            getline(cin, buffer);

            question.Answers.push_back(buffer);
            if (!Correct){
                cout << "Is this answer correct? Y/N ";
                //cin >> buffer;
                getline(cin, buffer);


                if ((buffer == "Y" || buffer == "y"))
                {
                    question.CorrectAnswer = question.Answers[i];
                    Correct = true;
                }
            }
            cout << endl;
        }


    int index = 1;
    int place;
    while (index < 4)
    {
        for (int i = 1; i < 5; i++)
        {
            cout <<i <<") "<< question.Answers[i] << endl;
        }
        cout << "What answer do you want in " << index << " place? ";

        while (true)
        {
            cin >> place;
            if ((ValidChoice(1, 4, place)))
            {
                break;
            }
        }
        swap(question.Answers[index], question.Answers[place]);
        index++;
    }

    Menu::Pause();
}

// Displays the question and answer(s)
void Ordering::Display()
{
    cout << question.Question << endl;
    for (int i = 1; i < 5; i++)
    {
        cout << i << ") " << question.Answers[i] << endl;
    }
    while (true)
    {
        cout << "-->";
        cin >> answer;
        if ((ValidChoice(1, 4, answer)))
        {
            break;
        }
    }
}
bool Ordering::Answer()
{
    if (question.Answers[answer] == question.CorrectAnswer)
    {
        return true;
    }
    else
        return false;
}
