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
};

// Question where user must type in 3 answers, which will be compared to stored answer text
class ThreeBlanks : public IQuestion
{
};

#endif
