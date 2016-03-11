#include <iostream>
#include <vector>
#include <string>
#include <locale>
#include <fstream>
#include <cstdlib>
using namespace std;

#include "Localization.hpp"

#include "Menu.hpp"
#include "Login.hpp"
#include "CreateAccount.hpp"
#include "DisplayUsers.hpp"
#include "NewUser.hpp"

int main()
{
	Localization english, esperanto;
	english.LoadLanguage("C:\\CS201R\\2016-03-10\\english.txt", "English");
	esperanto.LoadLanguage("C:\\CS201R\\2016-03-10\\esperanto.txt", "Esperanto");

	cout << english["PROGRAM TITLE"] << endl;
	cout << esperanto["PROGRAM TITLE"] << endl;

	return 0;
}







