#include "MultipleChoice.hpp"

#include <iostream>
#include <string>
using namespace std;

MultipleChoice::MultipleChoice()
{
    string m_question = " ";
    string m_answers[4] = " ";
    int NumQuestions = 0;
}

string MultipleChoice::GetQuestion()
{
    return m_question;
}
string MultipleChoice::GetAnswers(int index)
{
    return m_answers[index];
}
void MultipleChoice::CreateQuestion()
{
        string Question;
        cout << "Question: ";
        cin.ignore();
        getline(cin,Question);
        m_question = Question;

        int index;
        string answers;

        for(int i = 0; i < 4; i++)
            {
            cout << "Answer " << i + 1 << ": ";
            getline(cin, answers);
            m_answers[i] = answers;
            }
            cout << "Correct Answer: ";
            cin >> index;
            while(index < 1 || index > 5)
            {
                cout << "Invalid option. Choose again: ";
               cin >> index;
           }
           m_correct = m_answers[index-1];

        NumQuestions++;

}

void MultipleChoice::Display()
{
    cout << m_question << endl;;
    for(int j=0; j < 4; j++)
    {
        cout << j+1 << " \t" << m_answers[j] << endl;;
    }
}
bool MultipleChoice::Answer()
{
    int correct;
    cout << "What is the correct answer? " << endl;
        cin >> correct;
        while(correct < 1 || correct > 5 )
        {
            cout << "Invalid option, choose again: ";
            cin >> correct;
        }
    if(m_correct == m_answers[correct-1])
    {
        cout << "Correct " << endl;
        return true;
    }
    else
    {
       cout << "Incorrect " << endl;
        return false;
    }
}
