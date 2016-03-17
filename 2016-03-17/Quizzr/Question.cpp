#include "Question.hpp"
#include <iostream>
#include <string>
using namespace std;

MultipleChoice()
{
    string m_question = " ";
    string m_answers[4] = " ";
    int NumQuestions = 0;
}
void MultipleChoice::SetQuestion(string question)
{
    m_question = question;
}
void MultipleChoice::SetAnswers(string answers, int index)
{
    m_answers = answers[index];
}
void MultipleChoice::SetCorrectAnwer(string correct)
{
    m_correct = correct;
}
string MultipleChoice::GetQuestion()
{
    return m_question;
}
string MultipleChoice::GetAnswers(int index)
{
    return m_answers[index];
}
virtual void MultipleChoice::CreateQuestion()
{
    bool done = false;
    while(!done)
    {
        cout << "1. Add Question " << endl;
        cout << "2. Save and quit " << endl;

        int choice;
        cin >> choice;
        while(choice !=1 || choice != 2)
        {
            cout << "Invalid option. Choose again: ";
            cin >> choice;
        }
        if(choice == 1)
        {
            MultipleChoice question;
            MultipleChoice answers[4];
            int Answer;

            cout << "Question: ";
            getline(cin,question);

            for(int i = 0; i < 4; i++)
            {
            cout << "Answer " i + 1 << ": ";
            getline(cin, answers[i]);
            }
            cout << "Correct Answer: ";
            cin >> Answer;
            while(Answer < 0 || Answer > 4)
            {
                cout << "Invalid option. Choose again: ";
                cin >> Answer;
            }
            NumQuestions++;
        }
        else if(choice == 2)
        {
            done = true;
        }

    }
}
virtual void MultipleChoice::Display()
{
    MultipleChoice item;

    cout << item.GetQuestion() << endl;;
        for(int j=0; j < 4; j++)
        {
            cout << "\t" << item.GetAnswers[j] << endl;;
        }
}
virtual bool MultipleChoice::Answer(string answer)
{
    if(answer == m_correct)
    {
        return true;
    }
    return false;
}
