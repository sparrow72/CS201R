#ifndef TRUEFALSE_HPP
#define TRUEFALSE_HPP

#include <locale>
using namespace std;

#include "IQuestion.hpp"

// Question with either TRUE or FALSE answer, only 1 correct
class TrueFalse : public IQuestion
{
private:
	string answer;
	bool ans = false, ans1, loop = false;
	locale loc;

public:
	virtual void CreateQuestion();
	virtual void Display();
	virtual bool Answer();
};

#endif



