#ifndef FILLINTHEBLANK_HPP
#define FILLINTHEBLANK_HPP

#include <string>
#include <vector>
using namespace std;

#include "IQuestion.hpp"

// Question where user fills in one word as answer, compare to stored answer text

class FillInTheBlank : public IQuestion
{
private:
	string m_question;
	string m_answer;
	string m_userAnswer;
	int m_numberOfQuestions;

	vector<string> Questions;
	vector<string> Answers;
	vector<string> userAnswers;
	

public:
	FillInTheBlank();

	virtual void CreateQuestion();

	virtual void Display();

	virtual bool Answer();

};

#endif

