#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main()
{
    string dogBreeds = {
        "corgi", "labrador", "bulldog", "beagle", "poodle", "boxer"
        };

    string searchFor;
    cout << "Search for what term? ";
    cin >> searchFor;

    int foundIndex = -1;
    for ( int i = 0; i < 6; i++ )
    {
        if ( dogBreeds[i] == searchFor )
        {
            foundIndex = i;
        }
    }

    if ( foundIndex == -1 )
    {
        cout << "Not found" << endl;
    }
    else
    {
        cout << "Found" << endl;
    }

    return 0;
}
