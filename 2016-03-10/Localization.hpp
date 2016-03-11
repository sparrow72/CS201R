#ifndef _LOCAL
#define _LOCAL

#include <map>
#include <string>
using namespace std;

class Localization
{
public:
	void LoadLanguage(const string& filename, const string& language);
	string& operator[](const string& key);

private:
	map<string, string> m_text;
	string m_language;
};

#endif