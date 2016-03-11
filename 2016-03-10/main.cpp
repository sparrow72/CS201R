#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "Localization.hpp"


void DisplayUsers(vector people);



int main()
{
	Localization english, esperanto;
	english.LoadLanguage("C:\\CS201R\\2016-03-10\\english.txt", "English");
	esperanto.LoadLanguage("C:\\CS201R\\2016-03-10\\esperanto.txt", "Esperanto");

	cout << english["PROGRAM TITLE"] << endl;
	cout << esperanto["PROGRAM TITLE"] << endl;

	return 0;
}


void DisplayUsers(vector people)
{
	for (int i = 0; i <, i++)
	{
		cout << people[i] < endl;
	}
}
