#include "Person.hpp"

void Person::DiplayFriends()
{
    for(int i = 0; i < 50; i++)
    {
        cout << i+1 << friendsList[i] << endl;
    }
     cout << "Would you like to remove anyone from your friends list? (y/n) " << endl;
    char option;
    cin >> option;
    if(option == 'y'|| option == 'Y')
       {
        cout << "Who would you like to remove from your friends list? : ";
        RemoveFriend(option);
       }
}

void Person::Remove(int index)
{
    int choice;
    cin >> choice;
    remove friendsList[choice];
}
