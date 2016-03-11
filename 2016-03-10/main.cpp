#include <iostream>
using namespace std;
#include "Social.hpp"
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

void viewWall(Post post)
{
	cout << post;
}