#ifndef _QUESTION
#define _QUESTION

#include <iostream>
#include <string>
#include <locale>
using namespace std;

class IQuestion
{
public:
	// Display menus to have user enter question and answer(s)
	virtual void CreateQuestion() = 0;

	// Displays the question and answer(s)
	virtual void Display() = 0;

	// Displays menus to have user to enter the answer(s)
	// Returns true if they answered correctly,
	// otherwise false
	virtual bool Answer() = 0;

protected:
	string question;
};

// Question with either TRUE or FALSE answer, only 1 correct
class TrueFalse : public IQuestion
{
private:
	string answer;
	bool ans = false, ans1, loop = false;
	locale loc;
public:
	virtual void CreateQuestion()
	{
		cout << "Please typed in you question: ";
		getline(cin, question);
		cout << "Is the question true or false (ture/false): ";

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
	virtual void Display()
	{
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

	virtual bool Answer()
	{
		if (ans == ans1)
			return true;
		else
			return false;
	}
};

// Question with 4 possible answers, only 1 correct
class MultipleChoice : public IQuestion
{
private:
	string m_question;      //
	string m_answers[4];     //change to vector
	int NumQuestions;
	string m_correct;

public:
	MultipleChoice();
	void SetQuestion(string question);
	void SetAnswers(string answers, int index);
	string GetQuestion();
	string GetAnswers(int index);

	virtual void CreateQuestion();
	virtual void Display();
	virtual bool Answer();
};

// Question with 4 possible answers, 0 to 4 correct
class MultipleAnswer : public IQuestion
{
private:
	string answers[4];
	string question;
	bool correct_ans[4];

	void MultipleAnswer::CreateQuestion()
	{

		cout << "Please type the question" << endl << ">> ";
		getline(cin, question);
		for (int i = 0; i < 4; i++)
		{
			cout << "Please type a possible answers" << endl << ">> ";
			getline(cin, answers[i]);
			while (true)
			{
				cout << "Is this a correct answer? (y/n)" << endl << ">> ";
				char y_n;
				cin >> y_n;

				if (y_n == 'y')
				{
					correct_ans[i] = true;
					break;
				}
				else if (y_n == 'n')
				{
					correct_ans[i] = false;
					break;
				}
				else
				{
					cout << "Invalid choice. Please type 'y' or 'n'.";
					continue;
				}
			}

		}
	}
	void MultipleAnswer::Display()
	{
		cout << question << endl;
		for (int i = 0; i < answers[4].size(); i++)
		{
			cout << answers[i] << endl;
		}
	}
	bool MultipleAnswer::Answer()
	{
		cout << "Please enter all answers that are correct." << endl << ">> ";
	}
};

// Question where user fills in one word as answer, compare to stored answer text
class FillInTheBlank : public IQuestion
{
private:
	int numberOfQuestions;
	string* Questions;
	string* Answers;
	string* UserAnswers;

	string m_question;
	string m_answer;
	string m_userAnswer;

public:
	FillInTheBlank()
	{
		numberOfQuestions = 1;

		string* Questions = new string[numberOfQuestions];
		string* Answers = new string[numberOfQuestions];

		m_question = " ";
		m_answer = " ";
	}

	virtual ~FillInTheBlank()
	{
		delete[] Questions;
		delete[] Answers;
		delete[] UserAnswers;

		Questions = NULL;
		Answers = NULL;
		UserAnswers = NULL;
	}

	virtual void CreateQuestion()
	{
		bool checkInput = true;
		bool addQuestion = true;
		string userValidation;

		while (addQuestion)
		{
			cout << "Please enter a Fill in the Blank Question" << endl;
			getline(cin, m_question);
			Questions[numberOfQuestions - 1] = m_question;

			cout << "Answer: " << endl;
			cin >> m_answer;
			Answers[numberOfQuestions - 1] = m_answer;

			cout << "Would you like to add another question? Yes or No";
			cin >> userValidation;

			while (checkInput)
			{
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

	virtual void Display()
	{

		for (int i = 0; i < numberOfQuestions; i++)
		{
			cout << Questions[i] << endl << endl;
		}
	}

	virtual bool Answer()
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
				numberOfCorrectAnswers++;
			}
			else
			{
				cout << endl;
				cout << "Sorry! the answer is " << Answers[i] << endl;
			}
		}
		cout << "You got " << numberOfCorrectAnswers << " out of " << numberOfQuestions << "." << endl;
	}
};

// Question where user fills in a line of text as the answer, compare to stored answer text
class Essay : public IQuestion
{
public:

	virtual void CreateQuestion()
	{
		cout << "Enter a question" << endl;
		cout << ">> ";
		getline(cin, question);
		cout << "Enter the correct answer to your question" << endl;
		cout << ">> ";
		getline(cin, correctAnswer);
	}

	virtual void Display()
	{
		cout << question;
	}

	virtual bool Answer()
	{
		cout << "Enter the correct answer" << endl;
		cout << ">>";
		getline(cin, answer);
		if (answer == correctAnswer)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
private:
	string question;
	string correctAnswer;
	string answer;
};

// Question with 3 items listed, and user must order them 1 to 3.
class Ordering : public IQuestion
{
public:
	// Display menus to have user enter question and answer(s)


	virtual void CreateQuestion()
	{
		struct QA
		{
			string Question;
			string Answer[4][2];
		};

		QA quest[4];

		string input;

		cout << "What are your question?" << endl;
		for (int i = 0; i < 4; i++)
		{
			cout << i + 1 << " ";
			cin >> input;
			cout << endl;
			quest[i].Question = input;
			cout << "What are the answers for this question" << endl;
			for (int k = 0; k < 4; k++)
			{

				cin >> input;
				quest[i].Answer[k][0] = input;
				cout << "Is this Answes correct ";
				quest[i].Answer[k][1];
			}

		}

		for (int i = 0; i < 4; i++)
		{
			cout << "What are your Answers for " << question[i] << endl;
			cin >> input;
		}

	}
	// Displays the question and answer(s)
	virtual void Display();

	// Displays menus to have user to enter the answer(s)
	// Returns true if they answered correctly,
	// otherwise false
	virtual bool Answer();

};

// Question where user must type in 3 answers, which will be compared to stored answer text
class ThreeBlanks : public IQuestion
{
public:
	ThreeBlanks() {};
	void CreateQuestion();
	void Display();
	bool Answer();
private:
	string m_a1;
	string m_a2;
	string m_a3;
	string m_r1;
	string m_r2;
	string m_r3;
	string m_question;
};

#endif