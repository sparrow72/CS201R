#include "MultipleChoice.hpp"

#include <iostream>
#include <string>
using namespace std;

MultipleChoice::MultipleChoice()
{
    string m_question = " ";
    string m_answers[4] = " ";
    int NumQuestions = 0;
}
void MultipleChoice::SetQuestion(string question)
{
    m_question = question;
}
void MultipleChoice::SetAnswers(string answers, int index)
{
    // answers[index] is a character because answers is a string.
    //m_answers = answers[index];
}
string MultipleChoice::GetQuestion()
{
    return m_question;
}
string MultipleChoice::GetAnswers(int index)
{
    return m_answers[index];
}
void MultipleChoice::CreateQuestion()
{
    bool done = false;
    while(!done)
    {
        cout << "1. Add Question " << endl;
        cout << "2. Save and quit " << endl;

        int choice;
        cin >> choice;
        while(choice !=1 || choice != 2)
        {
            cout << "Invalid option. Choose again: ";
            cin >> choice;
        }
        if(choice == 1)
        {
            // You're already writing a function for inside the
            // MultipleChoice class; you don't need to create
            // a MultipleChoice inside of MultipleChoice in this case.
            // MULTIPLE-CHOICE-INCEPTION!
            MultipleChoice question;
            string Quest;

            cout << "Question: ";
            getline(cin,Quest);

            question.SetQuestion(Quest);

             int index;
            string answers;

            for(int i = 0; i < 4; i++)
                {
                cout << "Answer " << i + 1 << ": ";
                getline(cin, answers);
                question.SetAnswers(answers, i);
                }

                int answer;
                cout << "Correct Answer: ";
                cin >> index;
                //question.CorrectAnswer(index-1);
//                while(Answer < 0 || Answer > 4)
//                {
//                    cout << "Invalid option. Choose again: ";
//                    cin >> Answer;
//                }


            NumQuestions++;
        }
        else if(choice == 2)
        {
            done = true;
        }

    }
}
void MultipleChoice::Display()
{
    MultipleChoice item[NumQuestions];
    int correct;

//    for(int i = 0; i < NumQuestions; i
//    {
//        cout << item[i].GetQuestion() << endl;;
//        for(int j=0; j < 4; j++)
//        {
//            cout << "\t" << item[i].GetAnswers(j) << endl;;
//        }
//
//    }
}
bool MultipleChoice::Answer()
{
    MultipleChoice item;
    cout << "What is the correct answer? " << endl;

    // correct was not defined in this scope
//    cin >> correct;
//
//    if(item.IsCorrect(correct) == true)
//    {
//        cout << "Correct " << endl;
//    }
//    else
//    {
//        cout << "Incorrect " << endl;
//    }

}
bool MultipleChoice::IsCorrect(int answer)
{
    // since m_question is a string,
    // getting a subscript of a string
    // will give you a char
//    if(m_question[answer] == m_correct)
//    {
//        return true;
//    }
//    return false;
}
void MultipleChoice::CorrectAnswer(int index)
{
    m_correct = m_question[index];
}
