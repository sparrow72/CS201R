#ifndef _NEWUSER
#define _NEWUSER

void NewUser()
{
	string UserName;
	float Balance;
	ofstream fout("User.txt");



	fout.open("User.txt", std::ios_base::app);
	
	cout << "What is your user name >> ";
	cin >> UserName;
	cout << endl;

	cout << "What is your balance >> ";
	cin >> Balance;


	fout << UserName << "        $. " << Balance;

}

#endif
