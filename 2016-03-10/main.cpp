#include <iostream>
#include <vector>
#include <string>
#include <locale>
#include <fstream>
#include <cstdlib>
using namespace std;
<<<<<<< HEAD
#include "Social.hpp"
#include "Localization.hpp"
void Menu1();
void login();
void createAcct();
=======

//#include "Localization.hpp"
>>>>>>> origin/master

#include "Menu.hpp"
#include "Login.hpp"
#include "CreateAccount.hpp"
#include "DisplayUsers.hpp"
#include "NewUser.hpp"

<<<<<<< HEAD
	cout << english["PROGRAM TITLE"] << endl;
	cout << esperanto["PROGRAM TITLE"] << endl;
	
	return 0;
<<<<<<< HEAD
}

void viewWall(Post post)
{
	cout << post;
=======
=======
#include "Account.hpp"
>>>>>>> origin/master

vector<IPost*>      m_posts;
vector<IAccount*>       m_accounts;

int main()
{
    cout << "1. User account" << endl;
    cout << "2. Admin account" << endl;
    cout << "3. Advert account" << endl;
    cout << ">> ";

    int choice;
    cin >> choice;

    IAccount* currentUser = NULL;

    if ( choice == 1 )
    {
        currentUser = new UserAccount;
    }
    else if ( choice == 2 )
    {
        currentUser = new AdminAccount;
    }
    else if ( choice == 3 )
    {
        currentUser = new AdAccount;
    }

    cout << "Username: ";
    string username;
    cin >> username;
    currentUser->SetUsername( username );
	if (choice == 2)
	{
		char c;
		cout << "Display all posts?" << endl;
		cin >> c;
		if (c == 'y')
		{
			// For loop to display posts in vector for certain user
			// Get option of post to delete
			// Set option to deleted calling the deleted function
		}
	}

//    char another = 'y';
//    while ( another == 'y' )
//    {
//
//        // Add Post
//        IPost newPost;
//        cout << "Post: ";
//        cin >> newPost.content;
//        newPost.author = currentUser->GetUsername();
//
//        m_posts.push_back( newPost );
//
//        currentUser->AddPost( &m_posts[ m_posts.size() - 1 ] );
//
//        cout << "Add another? ";
//        cin >> another;
//
//   }

    currentUser->DisplayPosts();




    delete currentUser;

	return 0;
}
<<<<<<< HEAD
void NewUser()
{	
	string UserName;
	ofstream fout("User.txt");
	fout.open("User.txt");
	
	cout << "What is your user name?" << endl;
	cin >> UserName;

	fout << UserName;

>>>>>>> 7a270323f9ee83bf830bc5130681e46643ec5c38
}
=======








>>>>>>> origin/master
