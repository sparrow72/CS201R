#include "FillInTheBlank.hpp"

#include <iostream>
using namespace std;

FillInTheBlank::FillInTheBlank()
{
	string m_question = " ";
	string m_answer = " ";
	string m_userAnswer = " ";
}


void FillInTheBlank::CreateQuestion()
{
	bool checkInput;
	bool addQuestion = true;
	string userValidation;


	while (addQuestion)
	{
		checkInput = true;
		cout << "Please enter a Fill in the Blank Question: ";
		cin.ignore();
		getline(cin, m_question);
		Questions.push_back(m_question);

		cout << "Answer: ";
		cin >> m_answer;
		Answers.push_back(m_answer);


		while (checkInput)
		{
			cout << "Would you like to add another question? Yes or No ";
			cin >> userValidation;

				if (userValidation == "No" || userValidation == "N" || userValidation == "n")
				{
					addQuestion = false;
					checkInput = false;
				}
				else if ((userValidation == "Yes" || userValidation == "Y" || userValidation == "y"))
				{
					addQuestion = true;
					checkInput = false;
					numberOfQuestions++;
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

	for (int i = 0; i < numberOfQuestions; i++)
	{
		cout << Questions[i] << endl << endl;
	}

}

bool FillInTheBlank::Answer()
{
	int numberOfCorrectAnswers = 0;
	cout << "Please enter your answers:";
	for (int i = 0; i < numberOfQuestions; i++)
	{
		cout << (i + 1) + ". ";
		cin >> UserAnswers[i];

		if (UserAnswers[i] == Answers[i])
		{
			cout << endl;
			cout << "Correct!" << endl;
			return true;
		}
		else
		{
			cout << endl;
			cout << "Sorry! the answer is " << Answers[i] << endl;
			return false;
		}
	}
}
