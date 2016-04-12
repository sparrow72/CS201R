#include <iostream>
#include <string>
using namespace std;

int Find( const string& value, string arr[], int size )
{
    for ( int i = 0; i < size; i++ )
    {
        if ( value == arr[ i ] )
            return i;
    }
    return -1;
}

int main()
{
    string animals[5] = { "cat", "dog", "ferret", "snake", "bird" };

    int index1 = Find( "cat", animals, 5 );
    int index2 = Find( "skunk", animals, 5 );

    cout << "Cat at " << index1 << endl;
    cout << "Skunk at " << index2 << endl;

    cout << "End" << endl;

    return 0;
}
