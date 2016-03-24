#include "Question.hpp"
#include <iostream>
#include <string>
using namespace std;

//MultipleChoice()
//{
//    string m_question = " ";
//    string m_answers[4] = " ";
//    int NumQuestions = 0;
//}
//void MultipleChoice::SetQuestion(string question)
//{
//    m_question = question;
//}
//void MultipleChoice::SetAnswers(string answers, int index)
//{
//    m_answers = answers[index];
//}
//void MultipleChoice::SetCorrectAnwer(string correct)
//{
//    m_correct = correct;
//}
//string MultipleChoice::GetQuestion()
//{
//    return m_question;
//}
//string MultipleChoice::GetAnswers(int index)
//{
//    return m_answers[index];
//}
//virtual void MultipleChoice::CreateQuestion()
//{
//    bool done = false;
//    while(!done)
//    {
//        cout << "1. Add Question " << endl;
//        cout << "2. Save and quit " << endl;
//
//        int choice;
//        cin >> choice;
//        while(choice !=1 || choice != 2)
//        {
//            cout << "Invalid option. Choose again: ";
//            cin >> choice;
//        }
//        if(choice == 1)
//        {
//            MultipleChoice question;
//            MultipleChoice answers[4];
//            int Answer;
//
//            cout << "Question: ";
//            getline(cin,question);
//
//            for(int i = 0; i < 4; i++)
//            {
//            cout << "Answer " i + 1 << ": ";
//            getline(cin, answers[i]);
//            }
//            cout << "Correct Answer: ";
//            cin >> Answer;
//            while(Answer < 0 || Answer > 4)
//            {
//                cout << "Invalid option. Choose again: ";
//                cin >> Answer;
//            }
//            NumQuestions++;
//        }
//        else if(choice == 2)
//        {
//            done = true;
//        }
//
//    }
//}
//virtual void MultipleChoice::Display()
//{
//    MultipleChoice item;
//
//    cout << item.GetQuestion() << endl;;
//        for(int j=0; j < 4; j++)
//        {
//            cout << "\t" << item.GetAnswers[j] << endl;;
//        }
//}
//virtual bool MultipleChoice::Answer(string answer)
//{
//    if(answer == m_correct)
//    {
//        return true;
//    }
//    return false;
//}
//
//void ThreeBlanks::CreateQuestion() {
//	cout << "Please enter the question below: " << endl;
//	getline(cin, m_question);
//	cout << endl;
//	cout << "Enter the 3 answers" << endl;
//	cout << "A1. ";
//	getline(cin, m_a1);
//	cout << endl;
//	cout << "A2. ";
//	getline(cin, m_a2);
//	cout << endl;
//	cout << "A3. ";
//	getline(cin, m_a3);
//	cout << endl;
//}
//
//void ThreeBlanks::Display() {
//	cout << m_question;
//}
//
//bool ThreeBlanks::Answer() {
//	cout << "Provide each question below." << endl;
//	cout << "A1. ";
//	getline(cin, m_r1);
//	cout << endl;
//	cout << "A2. ";
//	getline(cin, m_r2);
//	cout << endl;
//	cout << "A3. ";
//	getline(cin, m_r3);
//	cout << endl;
//
//	if (m_a1 != m_r1) {
//		return false;
//	}
//	else if (m_a2 != m_r2) {
//		return false;
//	}
//	else if (m_a3 != m_r2) {
//		return false;
//	}
//	else {
//		return true;
//	}
//}



FillInTheBlank::FillInTheBlank()
{
	numberOfQuestions = 10;

	string* Questions = NULL;
	string* Answers = NULL;

	m_question = " ";
	m_answer = " ";
}

FillInTheBlank::~FillInTheBlank()
{
	delete[] Questions;
	delete[] Answers;
	delete[] UserAnswers;

	Questions = NULL;
	Answers = NULL;
	UserAnswers = NULL;
}

void FillInTheBlank::CreateQuestion()
{
	bool checkInput;
	bool addQuestion = true;
	string userValidation;

	string* Questions = new string[numberOfQuestions];
	string* Answers = new string[numberOfQuestions];

	while (addQuestion)
	{
		checkInput = true;
		cout << "Please enter a Fill in the Blank Question: ";
		cin.ignore();
		getline(cin, m_question);
		Questions[numberOfQuestions - 1] = m_question;

		cout << "Answer: ";
		cin >> m_answer;
		Answers[numberOfQuestions - 1] = m_answer;


		while (checkInput)
		{
			cout << "Would you like to add another question? Yes or No ";
			cin >> userValidation;

				if (userValidation == "No" || userValidation == "N" || userValidation == "n")
				{
					addQuestion = false;
					checkInput = false;
					string* UserAnswers = new string[numberOfQuestions];
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