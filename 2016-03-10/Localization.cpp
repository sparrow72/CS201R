#include "Localization.hpp"

#include <fstream>
using namespace std;

void Localization::LoadLanguage(const string& filename, const string& language)
{
	m_language = language;
	ifstream input(filename.c_str());

	string key, value, blank;
	while (getline(input, key))
	{
		getline(input, value);
		m_text[key] = value;
		getline(input, blank);
	}

	input.close();
}

string& Localization::operator[](const string& key)
{
	return m_text[key];
}
