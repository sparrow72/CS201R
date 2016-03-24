#ifndef _QUESTION
#define _QUESTION

#include <iostream>
#include <string>


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
	string question, answer0, answer1;
};

// Question with either TRUE or FALSE answer, only 1 correct
class TrueFalse : public IQuestion
{
	/*CreateQuestion() - Allow user to create question text.Answers will be True or False.Allow use to choose whether True or False is the correct answer for this question.
	Display() - Display the question text and True or False.
	Answer() - Have the user enter their answer, and check to see whether it is correct.Return true for correct and false for incorrect.

	Question should display a question in the form of a statement.
	Answers displayed will always be TRUE and FALSE.
	Only one correct answer can be selected.*/
public:
	void CreateQuestion()
	{

		cout << "Create a question: ";
		getline(cin, question);
		cout << "What it the answer: ";
		getline(cin, answer0);
		cout << "What is a fake answer: ";
		getline(cin, answer1);

	}
	void Display()
	{
		cout << "Quiz\nProblem 1: " << question << endl << answer0 << endl << answer1 << "1. True\n2. False";
		int option;
		bool loop = false;
		cout << "Please enter your answer (1/2): ";
		cin >> option;
		
		// switch
		do {
			switch (option) {
			case 1:
				Answer(answer0);
				loop = true;
				break;
			case 2:
				Answer(answer1);
				loop = true;
				break;
			default:
				cout << "Invalid\nPlease try again: ";
				cin >> option;
			}
		} while (!loop);
	}
	
	bool Answer(string a)
	{
		if (a == answer0)
			return true;
		else
			return false;
	}

private:
	
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
		getline(cin,question);
		for (int i = 0; i < 4; i++)
		{
			cout << "Please type a possible answers" << endl << ">> ";
			getline(cin,answers[i]);
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

	virtual ~ FillInTheBlank()
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

private:
	struct QA
	{
		string Question;
		string CorrectAnswer;
		string Answers[5] = {" "," "," "," "," "};
	};
	
	bool ValidChoice(int min, int max, int choice)
	{
		if (choice < min || choice > max)
		{
			cout << "Invalid Choice" << endl;
			return false;
		}
		return true;
	}
	
	vector<QA> quest;

public:
	// Display menus to have user enter question and answer(s)
	virtual void CreateQuestion()
	{
		QA Dummy;
		quest.push_back(Dummy);
		string buffer;
		bool Correct = false;

		for (int i = 1; i < 5; i++)
		{
			QA question;
			cout << "What is your " << i << " question? ";

			cin >> buffer;
			question.Question = buffer;
			for (int i = 1; i < 5; i++)
			{
				cout << "What is the " << i << " posible answers for this question? " << endl;
				cin >> question.Answers[i];
				if (!(Correct)) 
				{
					cout << "Is this answer correct? Y/N ";
					cin >> buffer;
					if ((buffer == "Y" || buffer == "y"))
					{
						question.CorrectAnswer = question.Answers[i];
						Correct = true;
					}
				}
			}
			cout << endl;
			quest.push_back(question);
			Correct = false;
		}
	
		int index = 1;
		int place;
		while (index < 4)
		{
			for (int k = 1; k < 5; k++) { cout << k << ") " << quest[k].Question << endl; }
			cout << "What question do you want in " << index << "st place? ";

			while (true)
			{
				cin >> place;
				if ((ValidChoice(1, 4, place)))
				{
					break;
				}
			}
			swap(quest[index], quest[place]);
			index++;
		}
	}

	// Displays the question and answer(s)
	virtual void Display()
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
	virtual bool Answer()
	{
		return true;
	}

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
