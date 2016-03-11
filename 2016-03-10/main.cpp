#include <iostream>
<<<<<<< HEAD
#include <vector>
#include <string>
=======
#include <locale>
#include <fstream>
>>>>>>> 7a270323f9ee83bf830bc5130681e46643ec5c38
using namespace std;

#include "Localization.hpp"
void Menu1();
void login();
void createAcct();

<<<<<<< HEAD

void DisplayUsers(vector people);



=======
void NewUser();
>>>>>>> 7a270323f9ee83bf830bc5130681e46643ec5c38
int main()
{
	Localization english, esperanto;
	english.LoadLanguage("C:\\CS201R\\2016-03-10\\english.txt", "English");
	esperanto.LoadLanguage("C:\\CS201R\\2016-03-10\\esperanto.txt", "Esperanto");

	cout << english["PROGRAM TITLE"] << endl;
	cout << esperanto["PROGRAM TITLE"] << endl;
	
	return 0;
<<<<<<< HEAD
}

<<<<<<< HEAD

void DisplayUsers(vector people)
{
	for (int i = 0; i <, i++)
	{
		cout << people[i] < endl;
	}
}
=======
void Menu2(int index)
{
	for (int i = 0; i < index; i++)
	{
		cout << i + 1 << "." << "\t";
	}
>>>>>>> 20c2f9dee90c39b53f464c0f503c2065c1cab134
=======


}
void Menu1()
{
	int ans;
	bool loop = false;

	do {
		cout << "Would you like to register a new account, or log in as an existing user.?\n1. Log in\n2. Create new account\n>> ";
		

		switch (ans)
		{
		case 1:
			login();
			loop = true;
			break;
		case 2:
			createAcct();
			loop = false;
			break;
		default:
			cout << "Invalid, please try again\n";
			break;
		}
	} while (!loop);
}

void login()
{
	int count = 0;
	string answer, pass;
	bool loop = false;
	locale loc;

	do {
		cout << "Username: ";
		getline(cin, answer);
		cout << "Password: ";
		getline(cin, pass);
		///set bool loop to true if they match, false if they dont match
		
		
			count++;
			if (count > 3)
			{
				system("cls");
				cout << "Invalid, you have now been locked out . . .\n";
				system("pause");
				return;
			}
			else if (count == 3)
			{
				cout << "\nAnother invalid responce shall result in termination!\n";
			}
			else if (count == 2)
			{
				cout << "\nre-evaluating...\n";
			}
			else
				cout << "Invalid, please try again\n";
		
	} while (!loop);
}
void createAcct()
{

}
void NewUser()
{	
	string UserName;
	ofstream fout("User.txt");
	fout.open("User.txt");
	
	cout << "What is your user name?" << endl;
	cin >> UserName;

	fout << UserName;

<<<<<<< HEAD
}
>>>>>>> 7a270323f9ee83bf830bc5130681e46643ec5c38
=======
>>>>>>> 7a270323f9ee83bf830bc5130681e46643ec5c38
}
>>>>>>> 20c2f9dee90c39b53f464c0f503c2065c1cab134
