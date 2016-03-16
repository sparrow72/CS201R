#include <iostream>
#include <vector>
#include <string>
#include <locale>
#include <fstream>
#include <cstdlib>
using namespace std;

//#include "Localization.hpp"

#include "Menu.hpp"
#include "Login.hpp"
#include "CreateAccount.hpp"
#include "DisplayUsers.hpp"
#include "NewUser.hpp"

#include "Account.hpp"

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








