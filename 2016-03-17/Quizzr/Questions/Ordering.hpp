#ifndef ORDERING_HPP
#define ORDERING_HPP

#include <string>
#include <vector>
using namespace std;

#include "IQuestion.hpp"

// Question with 3 items listed, and user must order them 1 to 3.
class Ordering : public IQuestion
{

private:
	struct QA
	{
		string Question;
		string CorrectAnswer;
		string Answers[5] = {" "," "," "," "," "};
	};

	bool ValidChoice(int min, int max, int choice);

	vector<QA> quest;

public:
	// Display menus to have user enter question and answer(s)
	virtual void CreateQuestion();

	// Displays the question and answer(s)
	virtual void Display();

	virtual bool Answer();

};

#endif


