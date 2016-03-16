#ifndef _MENU
#define _MENU

#include "Login.hpp"
#include "CreateAccount.hpp"

void Menu1()
{
	int ans;
	bool loop = false;

	do {
		cout << "Would you like to register a new account, or log in as an existing user.?\n1. Log in\n2. Create new account\n>> ";
		cin >> ans;

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

void Menu2(int index)
{
	for (int i = 0; i < index; i++)
	{
		cout << i + 1 << "." << "\t";
	}
}

#endif
