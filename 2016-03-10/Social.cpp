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

void Person::newPost(vector<Post>& wall) {
	Post npost;

	cout << "What is your mood? ";
	cin >> npost.mood;
	cout << endl;
	cout << "Post: ";
	getline(cin, npost.content);
	npost.date = "3.10.16";
	npost.author = name;

}