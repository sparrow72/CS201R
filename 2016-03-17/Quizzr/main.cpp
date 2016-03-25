#include <iostream>
#include <vector>
using namespace std;

#include "Menu.hpp"
#include "Question.hpp"

void CreateQuestion(vector<IQuestion*>& questions);
void RunQuiz(vector<IQuestion*>& questions);
void FreeMemory(vector<IQuestion*>& questions);

int main()
{
<<<<<<< HEAD
	vector<IQuestion*> questions;

	string options[] = {
		"Create new question",
		"Run quiz"
	};

	// Question Creation
	bool creatingQuestions = true;
	while (creatingQuestions)
	{
		Menu::ClearScreen();
		Menu::Header("MAIN MENU");
		int choice = Menu::ShowMenuWithPrompt(options, 2);

		if (choice == 0)
		{
			CreateQuestion(questions);
		}
		else if (choice == 1)
		{
			creatingQuestions = false;
		}
	}

	// Display Quiz
	RunQuiz(questions);

	// Clear
	FreeMemory(questions);

	Menu::Pause();
	return 0;
=======
    vector<IQuestion*> questions;

    string options[] = {
        "Create new question",
        "Run quiz"
    };

    // Question Creation
    bool creatingQuestions = true;
    while ( creatingQuestions )
    {
        Menu::ClearScreen();
        Menu::Header( "MAIN MENU" );
        int choice = Menu::ShowMenuWithPrompt( options, 2 );

        if ( choice == 0 )
        {
            CreateQuestion( questions );
        }
        else if ( choice == 1 )
        {
            creatingQuestions = false;
        }
    }

    // Display Quiz
    RunQuiz( questions );

    // Clear
    FreeMemory( questions );

	Menu::Pause();
    return 0;
>>>>>>> 6b643963c97133edb1d5a99b686c3aab27542aa2
}

void CreateQuestion(vector<IQuestion*>& questions)
{
<<<<<<< HEAD
	MenuOption questionTypes[] = {
		MenuOption("TRUE_FALSE", "True/False"),
		MenuOption("MULTI_CHOICE", "Multiple Choice"),
		MenuOption("MULTI_ANSWER", "Multiple Answer"),
		MenuOption("BLANK", "Fill in the blank"),
		MenuOption("ESSAY", "Essay"),
		MenuOption("ORDER", "Ordering"),
		MenuOption("BLANK3", "Fill in 3")
	};

	Menu::ClearScreen();
	Menu::Header("QUESTION TYPE");
	Menu::ShowMenu(questionTypes, 7);
	int choice = Menu::GetValidChoice("What kind of question do you want to create?", 1, 7) - 1;

	IQuestion* question = NULL;
	if (questionTypes[choice].key == "TRUE_FALSE")
	{
		question = new TrueFalse;
	}
	else if (questionTypes[choice].key == "MULTI_CHOICE")
	{
		question = new MultipleChoice;
	}
	else if (questionTypes[choice].key == "MULTI_ANSWER")
	{
		question = new MultipleAnswer;
	}
	else if (questionTypes[choice].key == "BLANK")
	{
		question = new FillInTheBlank;
	}
	else if (questionTypes[choice].key == "ESSAY")
	{
		question = new Essay;
	}
	else if (questionTypes[choice].key == "ORDER")
	{
		question = new Ordering;
	}
	else if (questionTypes[choice].key == "BLANK3")
	{
		question = new ThreeBlanks;
	}


	if (question == NULL)
	{
		cout << "Error: Did not create a question type." << endl;
		Menu::Pause();
	}
	else
	{
		question->CreateQuestion();
		questions.push_back(question);
		cout << "Question added" << endl;
		Menu::Pause();
	}
=======
    MenuOption questionTypes[] = {
        MenuOption( "TRUE_FALSE", "True/False" ),
        MenuOption( "MULTI_CHOICE", "Multiple Choice" ),
        MenuOption( "MULTI_ANSWER", "Multiple Answer" ),
        MenuOption( "BLANK", "Fill in the blank" ),
        MenuOption( "ESSAY", "Essay" ),
        MenuOption( "ORDER", "Ordering" ),
        MenuOption( "BLANK3", "Fill in 3" )
    };

    Menu::ClearScreen();
    Menu::Header( "QUESTION TYPE" );
    Menu::ShowMenu( questionTypes, 7 );
    int choice = Menu::GetValidChoice( "What kind of question do you want to create?", 1, 7 ) - 1;

    IQuestion* question = NULL;
    if ( questionTypes[ choice ].key == "TRUE_FALSE" )
    {
        question = new TrueFalse;
    }
    else if ( questionTypes[ choice ].key == "MULTI_CHOICE" )
    {
        question = new MultipleChoice;
    }
    else if ( questionTypes[ choice ].key == "MULTI_ANSWER" )
    {
        question = new MultipleAnswer;
    }
    else if ( questionTypes[ choice ].key == "BLANK" )
    {
        question = new FillInTheBlank;
    }
    else if ( questionTypes[ choice ].key == "ESSAY" )
    {
		question = new Essay;
    }
    else if ( questionTypes[ choice ].key == "ORDER" )
    {
		question = new Ordering;
	}
    else if ( questionTypes[ choice ].key == "BLANK3" )
    {
        question = new ThreeBlanks;
    }


    if ( question == NULL )
    {
        cout << "Error: Did not create a question type." << endl;
        Menu::Pause();
    }
    else
    {
        question->CreateQuestion();
        questions.push_back( question );
        cout << "Question added" << endl;
        Menu::Pause();
    }
>>>>>>> 6b643963c97133edb1d5a99b686c3aab27542aa2
}

void RunQuiz(vector<IQuestion*>& questions)
{
<<<<<<< HEAD
	int score = 0;
	for (int i = 0; i < questions.size(); i++)
	{
		Menu::Header("Question " + Menu::IntToString(i + 1));
		questions[i]->Display();
		if (questions[i]->Answer() == true)
		{
			score++;
		}
	}

	if (questions.size() > 0)
	{
		int result = score / questions.size() * 100;
		cout << "Your score: " << result << "%" << endl;
	}
=======
    int score = 0;
    for ( int i = 0; i < questions.size(); i++ )
    {
        Menu::Header( "Question " + Menu::IntToString( i+1 ) );
        questions[i]->Display();
        if ( questions[i]->Answer() == true )
        {
            score++;
        }
    }

    if ( questions.size() > 0 )
    {
        int result = score / questions.size() * 100;
        cout << "Your score: " << result << "%" << endl;
    }
>>>>>>> 6b643963c97133edb1d5a99b686c3aab27542aa2
	Menu::Pause();
}

void FreeMemory(vector<IQuestion*>& questions)
{
	for (int i = 0; i < questions.size(); i++)
	{
		delete questions[i];
	}
}