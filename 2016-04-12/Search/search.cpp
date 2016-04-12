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

int Find( const string& value, string arr[], int size, int index )
{
    if ( value == arr[index] )
    {
        return index;
    }
    if ( index + 1 == size )
    {
        return -1;
    }

    return Find( value, arr, size, index+1 );
}

void Display( string arr[], int size )
{
    for ( int i = 0; i < size; i++ )
    {
        cout << arr[i] << endl;
    }
}

// Recursive
void Display( string arr[], int size, int index )
{
    cout << arr[index] << endl;

    if ( index + 1 == size )
    {
        return;
    }
    Display( arr, size, index+1 );
}

int main()
{
    string animals[5] = { "cat", "dog", "ferret", "snake", "bird" };

    Display( animals, 5, 0 );

    cout << endl << endl;

    int index1 = Find( "cat", animals, 5 );
    int index2 = Find( "skunk", animals, 5 );

    cout << "Cat at " << index1 << endl;
    cout << "Skunk at " << index2 << endl;

    int index3 = Find( "cat", animals, 5, 0 );
    int index4 = Find( "skunk", animals, 5, 0 );

    cout << "Cat at " << index3 << endl;
    cout << "Skunk at " << index4 << endl;

    cout << "End" << endl;

    return 0;
}
