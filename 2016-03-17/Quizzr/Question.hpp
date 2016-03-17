#ifndef _QUESTION
#define _QUESTION

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
private:
    string m_question;
    string m_answers[4];
    int NumQuestions;
    string m_correct;

public:
    MultipleChoice();
    void SetQuestion(string question);
    void SetAnswers(string answers, int index);
    string GetQuestion();
    string GetAnswers(int index);

    virtual void CreateQuestion();
    virtual void Display();
    virtual bool Answer();
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
};

#endif
