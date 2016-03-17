#ifndef _QUESTION
#define _QUESTION

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
};

// Question with either TRUE or FALSE answer, only 1 correct
class TrueFalse : public IQuestion
{
};

// Question with 4 possible answers, only 1 correct
class MultipleChoice : public IQuestion
{
};

// Question with 4 possible answers, 0 to 4 correct
class MultipleAnswer : public IQuestion
{
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
};

// Question with 3 items listed, and user must order them 1 to 3.
class Ordering : public IQuestion
{
};

// Question where user must type in 3 answers, which will be compared to stored answer text
class ThreeBlanks : public IQuestion
{
};

#endif
