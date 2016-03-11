#include <iostream>
using namespace std;

#include "Localization.hpp"

int main()
{
	Localization english, esperanto;
	english.LoadLanguage("C:\\CS201R\\2016-03-10\\english.txt", "English");
	esperanto.LoadLanguage("C:\\CS201R\\2016-03-10\\esperanto.txt", "Esperanto");

	cout << english["PROGRAM TITLE"] << endl;
	cout << esperanto["PROGRAM TITLE"] << endl;

	return 0;
}

void Menu2(int index)
{
	for (int i = 0; i < index; i++)
	{
		cout << i + 1 << "." << "\t";
	}
}