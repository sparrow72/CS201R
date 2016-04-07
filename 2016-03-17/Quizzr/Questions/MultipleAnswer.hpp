#ifndef MULTIPLEANSWER_HPP
#define MULTIPLEANSWER_HPP

#include "IQuestion.hpp"

// Question with 4 possible answers, 0 to 4 correct
class MultipleAnswer : public IQuestion
{
private:
	string answers[4];
	string question;
	bool correct_ans[4];

public:
	void CreateQuestion();
	void Display();
	bool Answer();
};

#endif

