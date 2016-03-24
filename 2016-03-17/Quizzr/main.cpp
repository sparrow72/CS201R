#include <iostream>
#include <vector>
using namespace std;

#include "Menu.hpp"
#include "Question.hpp"

void CreateQuestion( vector<IQuestion*>& questions );
void RunQuiz( vector<IQuestion*>& questions );
void FreeMemory( vector<IQuestion*>& questions );

int main()
{
    vector<IQuestion*> questions;

    string options[] = {
        "Create new question",
        "Run quiz"
    };

     Question Creation

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

     Display Quiz

    RunQuiz( questions );

     Clear

    FreeMemory( questions );

	system("pause");
    return 0;
}

void CreateQuestion( vector<IQuestion*>& questions )
{
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
<<<<<<< HEAD
//       question = new TrueFalse;
=======
       /*question = new TrueFalse;*/
>>>>>>> 2302c4b953085a8b86b443d89f2e99b0174d5f24
    }
    else if ( questionTypes[ choice ].key == "MULTI_CHOICE" )
    {
        question = new MultipleChoice;
<<<<<<< HEAD
        question->CreateQuestion();
        question->Answer();
        question->Display();
=======
>>>>>>> 2302c4b953085a8b86b443d89f2e99b0174d5f24
    }
    else if ( questionTypes[ choice ].key == "MULTI_ANSWER" )
    {
        question = new MultipleAnswer;
    }
    /*else if ( questionTypes[ choice ].key == "BLANK" )
    {
<<<<<<< HEAD
//  question = new FillInTheBlank;
    }
    else if ( questionTypes[ choice ].key == "ESSAY" )
    {
	/*	question = new Essay;
		question->CreateQuestion();
		question->Display();
		question->Answer();*/
=======
        question = new FillInTheBlank;
    }*/
   /* else if ( questionTypes[ choice ].key == "ESSAY" )
    {
		question = new Essay;
<<<<<<< HEAD
		question->CreateQuestion();
		question->Display();
		question->Answer();
    }*/
   /* else if ( questionTypes[ choice ].key == "ORDER" )
=======
>>>>>>> 2302c4b953085a8b86b443d89f2e99b0174d5f24
    }
    else if ( questionTypes[ choice ].key == "ORDER" )
>>>>>>> 5ce5200194588082cd5133286d4943e60efab188
    {
<<<<<<< HEAD
		//question = new Ordering;
=======
<<<<<<< HEAD
		//question = new Ordering;
		
=======
		question = new Ordering;
<<<<<<< Updated upstream
>>>>>>> 2302c4b953085a8b86b443d89f2e99b0174d5f24

>>>>>>> origin/master
	}

=======
		
	}*/
    
>>>>>>> Stashed changes
    else if ( questionTypes[ choice ].key == "BLANK3" )
    {
//        question = new ThreeBlanks;
    }


    if ( question == NULL )
    {
        cout << "Error: Did not create a question type. Press a key to continue." << endl;
        string a;
        cin >> a;
    }
    else
    {
        question->CreateQuestion();
        questions.push_back( question );
    }
}

void RunQuiz( vector<IQuestion*>& questions )
{
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

    int result = score / questions.size() * 100;
    cout << "Your score: " << result << "%" << endl;
	system("pause");
}

void FreeMemory( vector<IQuestion*>& questions )
{
    for ( int i = 0; i < questions.size(); i++ )
    {
        delete questions[i];
    }
}
