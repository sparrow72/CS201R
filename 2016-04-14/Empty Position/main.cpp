#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main()
{
    float gpas[] = { 4.0, 3.0, -1, 2.0, 3.0, 3.5, -1, 3.2 };

    float newGpa = 3.4;

    int emptyIndex = -1;
    for ( int i = 0; i < 8; i++ )
    {
        if ( gpas[i] == -1 )
        {
            emptyIndex = i;
            break;
        }
    }

    if ( emptyIndex != -1 )
    {
        gpas[emptyIndex ] = newGpa;
    }

    for ( int i = 0; i < 8; i++ )
    {
        cout << i << ": " << gpas[i] << endl;
    }

    return 0;
}

