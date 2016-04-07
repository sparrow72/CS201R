#ifndef MULTIPLECHOICE_HPP
#define MULTIPLECHOICE_HPP

#include "IQuestion.hpp"

class MultipleChoice : public IQuestion
{
private:
	string m_question;
	string m_answers[4];
	int NumQuestions;
	string m_correct;

public:
	MultipleChoice();
	string GetQuestion();
	string GetAnswers(int index);

	virtual void CreateQuestion();
	virtual void Display();
	virtual bool Answer();
};

#endif

