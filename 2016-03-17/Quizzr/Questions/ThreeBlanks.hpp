#ifndef THREEBLANKS_HPP
#define THREEBLANKS_HPP

#include "IQuestion.hpp"

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
