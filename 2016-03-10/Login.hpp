#ifndef _LOGIN
#define _LOGIN

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

#endif
