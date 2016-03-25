#ifndef FILLINTHEBLANK_HPP
#define FILLINTHEBLANK_HPP

#include <string>
using namespace std;

#include "IQuestion.hpp"

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
	FillInTheBlank();

	virtual ~FillInTheBlank();

	virtual void CreateQuestion();

	virtual void Display();

	virtual bool Answer();

};

#endif

