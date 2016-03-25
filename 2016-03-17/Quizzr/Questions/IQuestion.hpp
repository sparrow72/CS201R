#ifndef IQUESTION_HPP
#define IQUESTION_HPP

#include <string>
using namespace std;

class IQuestion
{
public:
	 //Display menus to have user enter question and answer(s)
	virtual void CreateQuestion() = 0;

	 //Displays the question and answer(s)
	virtual void Display() = 0;

	 //Displays menus to have user to enter the answer(s)
	 //Returns true if they answered correctly,
	 //otherwise false
	virtual bool Answer() = 0;

protected:
	string question, answer0, answer1;
};

#endif
