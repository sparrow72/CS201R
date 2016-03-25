#include "Menu.hpp"

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

void Menu::Pause()
{
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        cout << "Press a key to continue..." << endl;
        system( "pause" );
    #else
        cout << "Press ENTER to continue..." << endl;
        cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );
    #endif
}

string Menu::IntToString( int num )
{
    stringstream ss;
    ss << num;
    return ss.str();
}

int Menu::StringToInt( const string& str )
{
    istringstream ss( str );
    int val;
    ss >> val;
    return val;
}
