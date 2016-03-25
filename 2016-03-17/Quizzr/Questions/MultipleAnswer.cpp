#include "MultipleAnswer.hpp"

#include <iostream>
using namespace std;

void MultipleAnswer::CreateQuestion()
{

    cout << "Please type the question" << endl << ">> ";

    cin.ignore();
    getline(cin, question);
    for (int i = 0; i < 4; i++)
    {

        cout << "Please type a possible answers" << endl << ">> ";
        getline(cin, answers[i]);
        cout << "Is this a correct answer? (y/n)" << endl << ">> ";
        char y_n;
        cin >> y_n;
        cin.ignore();

        if (y_n == 'y')
        {
            correct_ans[i] = true;
        }
        else if (y_n == 'n')
        {
            correct_ans[i] = false;
        }
        else
        {
            cout << "Invalid choice. Please type 'y' or 'n'.";
        }



    }
}
void MultipleAnswer::Display()
{
    cout << question << endl;
    for (int i = 0; i < answers[4].size(); i++)
    {
        cout << i+1<<answers[i] << endl;
    }
}
bool MultipleAnswer::Answer()
{
    while (true)
    {
        cout << "What is your answer?" << endl << ">>";
        char user_answer;
        cin >> user_answer;
        cout << "Add another answer?" << endl << ">>";

        // y_n not declared in this scope.
//        if (y_n == 'y')
//        {
//            continue;
//        }
//        else if (y_n == 'n')
//        {
//            break;
//        }
//        else
//        {
//            cout << "Invalid choice. Please type 'y' or 'n'.";
//        }
    }

    return true;
}
