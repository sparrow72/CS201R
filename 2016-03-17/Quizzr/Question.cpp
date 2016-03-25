#include "Question.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//<<<<<<< HEAD
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




//=======
//MultipleChoice::MultipleChoice()
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
//string MultipleChoice::GetQuestion()
//{
//    return m_question;
//}
//string MultipleChoice::GetAnswers(int index)
//>>>>>>> fd18fe56776a50f74343f27df813ac23a92feb36
//{
//	numberOfQuestions = 10;
//
//	string* Questions = NULL;
//	string* Answers = NULL;
//
//	m_question = " ";
//	m_answer = " ";
//}
//<<<<<<< HEAD

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
//=======
//void MultipleChoice::CreateQuestion()
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
//            string Quest;
//
//            cout << "Question: ";
//            getline(cin,Quest);
//
//            question.SetQuestion(Quest);
//
//             int index;
//            string answers;
//
//            for(int i = 0; i < 4; i++)
//                {
//                cout << "Answer " << i + 1 << ": ";
//                getline(cin, answers);
//                question.SetAnswers(answers, i);
//                }
//
//                int answer;
//                cout << "Correct Answer: ";
//                cin >> index;
//                question.CorrectAnswer(index-1);
//                while(index < 1 || index > 5)
//                {
//                    cout << "Invalid option. Choose again: ";
//                    cin >> index;
//                }
//
//
//            NumQuestions++;
//        }
//        else if(choice == 2)
//        {
//            done = true;
//        }
//
//    }
//}
//void MultipleChoice::Display()
//{
//    MultipleChoice item[NumQuestions];
//    int correct;
//
//    for(int i = 0; i < NumQuestions; i
//    {
//        cout << item[i].GetQuestion() << endl;;
//        for(int j=0; j < 4; j++)
//        {
//            cout << "\t" << item[i].GetAnswers(j) << endl;;
//        }
//
//    }
//}
//bool MultipleChoice::Answer()
//{
//    MultipleChoice item;
//    cout << "What is the correct answer? " << end;
//    cin >> correct;
//
//        if(item.IsCorrect(correct) == true)
//        {
//            cout << "Correct " << endl;
//        }
//        else
//        {
//            cout << "Incorrect " << endl;
//        }
//
//}
//bool MultipleChoice::IsCorrect(int answer)
//{
//    if(m_question[answer] == m_correct)
//    {
//        return true;
//    }
//    return false;
//}
//void MultipleChoice::CorrectAnswer(int index)
//{
//    m_correct = m_question[index];
//}

//void ThreeBlanks::CreateQuestion() {
	//cout << "Please enter the question below: " << endl;
	//getline(cin, m_question);
	/*cout << endl;
	cout << "Enter the 3 answers" << endl;
	cout << "A1. ";
	getline(cin, m_a1);
	cout << endl;
	cout << "A2. ";
	getline(cin, m_a2);
	cout << endl;
	cout << "A3. ";
	getline(cin, m_a3);
	cout << endl;
>>>>>>> fd18fe56776a50f74343f27df813ac23a92feb36
}


<<<<<<< HEAD
}
=======
	else if (m_a2 != m_r2) {
		return false;
	}
	else if (m_a3 != m_r2) {
		return false;
	}
	else {
		return true;
	}
}*/

//>>>>>>> fd18fe56776a50f74343f27df813ac23a92feb36
