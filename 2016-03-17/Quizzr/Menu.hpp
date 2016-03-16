/*
Rachel's special "I'M TIRED OF WRITING MENUS"
class object.
*/

#ifndef _MENU
#define _MENU

#include <iostream>
#include <string>
using namespace std;

class MenuOption
{
    public:
    MenuOption() { }

    MenuOption( const string& k, const string& v )
    {
        Setup( k, v );
    }

    void Setup( const string& k, const string& v )
    {
        key = k;
        value = v;
    }

    string key;
    string value;
};

class Menu
{
    public:
    static void Header( const string& header );
    static void ShowMenu( const string options[], int size );
    static void ShowMenu( const MenuOption options[], int size );
    static void ShowMenu( const vector<MenuOption> options );
    static int ShowMenuWithPrompt( const string options[], int size );
    static int ShowMenuWithPrompt( const MenuOption options[], int size );
    static int ShowMenuWithPrompt( const vector<MenuOption> );
    static int GetValidChoice( int min, int max );
    static int GetValidChoice( const string& message, int min, int max );
    static void ClearScreen();
    static void DrawHorizontalBar( int width, char symbol = '-' );

    static string IntToString( int num );
    static int StringToInt( const string& str );

    private:
};

void Menu::DrawHorizontalBar( int width, char symbol )
{
    for ( int i = 0; i < width; i++ )
    {
        cout << symbol;
    }
    cout << endl;
}

void Menu::Header( const string& header )
{
    DrawHorizontalBar( 80 );
    string head = "| " + header + " |";
    cout << " " << head << endl << " ";
    DrawHorizontalBar( head.size() );
    cout << endl;
}

void Menu::ShowMenu( const string options[], int size )
{
    for ( int i = 0; i < size; i++ )
    {
        cout << " " << (i+1) << ".\t" << options[i] << endl;
    }
}

void Menu::ShowMenu( const MenuOption options[], int size )
{
    for ( int i = 0; i < size; i++ )
    {
        cout << " " << (i+1) << ".\t" << options[i].value << endl;
    }
}

void Menu::ShowMenu( const vector<MenuOption> options )
{
    for ( int i = 0; i < options.size(); i++ )
    {
        cout << " " << (i+1) << ".\t" << options[i].value << endl;
    }
}

int Menu::ShowMenuWithPrompt( const string options[], int size )
{
    ShowMenu( options, size );
    int choice = GetValidChoice( 1, size );
    return choice - 1;
}

int Menu::ShowMenuWithPrompt( const MenuOption options[], int size )
{
    ShowMenu( options, size );
    int choice = GetValidChoice( 1, size );
    return choice - 1;
}

int Menu::ShowMenuWithPrompt( const vector<MenuOption> options )
{
    ShowMenu( options );
    int choice = GetValidChoice( 1, options.size() );
    return choice - 1;
}

int Menu::GetValidChoice( int min, int max )
{
    return GetValidChoice( "", min, max );
}

int Menu::GetValidChoice( const string& message, int min, int max )
{
    if ( message != "" )
    {
        cout << endl;
        DrawHorizontalBar( message.size() + 2 );
        cout << " " << message << endl;
    }

    int choice;
    cout << " >> ";
    cin >> choice;

    while ( choice < min || choice > max )
    {
        cout << "Invalid selection. Try again." << endl;
        cout << ">> ";
        cin >> choice;
    }

    return choice;
}

void Menu::ClearScreen()
{
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        system( "cls" );
    #else
        system( "clear" );
    #endif
}

string Menu::IntToString( int num )
{
    return to_string( num );
}

int Menu::StringToInt( const string& str )
{
    return stoi( str );
}

#endif

