#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main()
{
	string dogBreeds = { "corgi labrador bulldog beagle poodle boxer" };

	string searchFor;
	cout << "Search for what term? ";
	cin >> searchFor;

	size_t found = dogBreeds.find(searchFor);
	if (found != string::npos)

	{
		cout << "Found" << endl;
	}
	else
	{
		cout << "Not found" << endl;
	}
	system("pause");
	return 0;
}
