#include "Question.hpp"
#include <iostream>
#include <string>
using namespace std;

MultipleChoice::MultipleChoice()
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

void ThreeBlanks::CreateQuestion() {
	cout << "Please enter the question below: " << endl;
	cin.ignore();
	getline(cin, m_question);
	cout << endl;
	cout << "Enter the 3 answers" << endl;
	cout << "A1. ";
	cin.ignore();
	getline(cin, m_a1);
	cout << endl;
	cout << "A2. ";
	cin.ignore();
	getline(cin, m_a2);
	cout << endl;
	cout << "A3. ";
	cin.ignore();
	getline(cin, m_a3);
	cout << endl;
}

void ThreeBlanks::Display() {
	cout << m_question;
}

bool ThreeBlanks::Answer() {
	cout << "Provide each question below." << endl;
	cout << "A1. ";
	cin.ignore();
	getline(cin, m_r1);
	cout << endl;
	cout << "A2. ";
	cin.ignore();
	getline(cin, m_r2);
	cout << endl;
	cout << "A3. ";
	cin.ignore();
	getline(cin, m_r3);
	cout << endl;

	if (m_a1 != m_r1) {
		return false;
	}
	else if (m_a2 != m_r2) {
		return false;
	}
	else if (m_a3 != m_r2) {
		return false;
	}
	else {
		return true;
	}
}

