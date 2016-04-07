/*
Rachel's special "I'M TIRED OF WRITING MENUS"
class object.
*/

#ifndef _MENU
#define _MENU

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <limits>
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
    static void Pause();
    static void DrawHorizontalBar( int width, char symbol = '-' );

    static string IntToString( int num );
    static int StringToInt( const string& str );

    private:
};

#endif

