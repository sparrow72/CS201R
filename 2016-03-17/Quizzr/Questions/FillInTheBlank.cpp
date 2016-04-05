#include "FillInTheBlank.hpp"

#include <iostream>
using namespace std;

FillInTheBlank::FillInTheBlank()
{

	m_question = " ";
	m_answer = " ";
	m_userAnswer = " ";
	m_numberOfQuestions = 1;
}


void FillInTheBlank::CreateQuestion()
{
	bool checkInput;
	bool addQuestion = true;
	string userValidation;


	while (addQuestion)
	{
		checkInput = true;
		cout << "Question " << m_numberOfQuestions << " : ";
		cin.ignore();
		getline(cin, m_question);
		Questions.push_back(m_question);

		cout << "Answer: ";
		cin >> m_answer;
		Answers.push_back(m_answer);


		while (checkInput)
		{
			cout << endl;
			cout << "Would you like to add another question? (Yes or No) ";
			cin >> userValidation;

				if (userValidation == "No" || userValidation == "no" || userValidation == "N" || userValidation == "n")
				{
					addQuestion = false;
					checkInput = false;
				}
				else if ((userValidation == "Yes" || userValidation == "yes" || userValidation == "Y" || userValidation == "y"))
				{
					addQuestion = true;
					checkInput = false;
					m_numberOfQuestions++;
				}
				else
				{
					cout << "Please add a valid response (Yes or No)" << endl;
				}
			}
		}

}

void FillInTheBlank::Display()
{

	for (int i = 0; i < m_numberOfQuestions; i++)
	{
		cout << Questions[i] << endl << endl;
	}

}

bool FillInTheBlank::Answer()
{
	cout << "Please enter your answers: " << endl;
	for (int i = 0; i < m_numberOfQuestions; i++)
	{
		cout << (i + 1) << ". ";
		cin >> m_userAnswer;
		userAnswers.push_back(m_userAnswer);
	}

	bool everythingCorrect = true;
	for (int i = 0; i < m_numberOfQuestions; i++)
	{
		if (userAnswers[i] != Answers[i])
		{
			return false;
		}
	}
	return true;
}

