#include "LinkedList.hpp"

#include <iostream>
#include <string>
using namespace std;

int main()
{
    LinkedList<string> nameList;

    nameList.Insert( "asdf" );
    nameList.Insert( "bnm" );
    nameList.Insert( "cvb" );
    nameList.Insert( "qwer" );
    nameList.Insert( "cutio" );

    cout << nameList.GetAt( 3 ) << endl;

    int found = nameList.Find( "aaaaas" );
    cout << "Index: " << found << endl;

    return 0;
}
