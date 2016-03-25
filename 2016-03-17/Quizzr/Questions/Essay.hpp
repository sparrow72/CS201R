#ifndef ESSAY_HPP
#define ESSAY_HPP

#include "IQuestion.hpp"

// Question where user fills in a line of text as the answer, compare to stored answer text
class Essay : public IQuestion
{
public:

	virtual void CreateQuestion();
	virtual void Display();
	virtual bool Answer();

private:
	string Question;
	string correctAnswer;
	string answer;
};

#endif

