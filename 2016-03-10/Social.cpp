#include "Social.hpp"

ostream& operator<<(ostream& out, Post& item)
{
	out << item.content << endl << item.mood
		<< endl << item.date << endl << item.author;
	return out;
}

Post& Person::operator[](const int index)
{
	return posts[index];
}