#include <iostream>
#include <fstream>
using namespace std;

#include "Localization.hpp"

void NewUser();
int main()
{
	Localization english, esperanto;
	english.LoadLanguage("C:\\CS201R\\2016-03-10\\english.txt", "English");
	esperanto.LoadLanguage("C:\\CS201R\\2016-03-10\\esperanto.txt", "Esperanto");

	cout << english["PROGRAM TITLE"] << endl;
	cout << esperanto["PROGRAM TITLE"] << endl;

	return 0;
}
void NewUser()
{	
	string UserName;
	ofstream fout("User.txt");
	fout.open();
	
	cout << "What is your user name?" << endl;
	cin >> UserName;

	fout.app << UserName;

}