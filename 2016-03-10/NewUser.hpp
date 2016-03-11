#ifndef _NEWUSER
#define _NEWUSER

void NewUser()
{
	string UserName;
	ofstream fout("User.txt");
	fout.open("User.txt");

	cout << "What is your user name?" << endl;
	cin >> UserName;

	fout << UserName;
}

#endif
