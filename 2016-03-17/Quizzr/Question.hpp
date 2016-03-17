#ifndef _QUESTION
#define _QUESTION

#include <iostream>
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
};

// Question where user fills in a line of text as the answer, compare to stored answer text
class Essay : public IQuestion
{
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
				cout <<"Is this Answes correct "
				quest[i].Answer[k][1]
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
};

#endif
