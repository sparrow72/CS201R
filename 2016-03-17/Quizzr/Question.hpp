#ifndef _QUESTION
#define _QUESTION

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
