#ifndef _SOCIAL
#define _SOCIAL

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Post
{
public:
	string content;
	string mood;
	string date;
	string author;

	friend ostream& operator<<(ostream& out, Post& item);
};

class Person
{
	string name;
	vector<Post> posts;
	Post& operator[](const int index);
	void newPost(vector<Post>& wall);
};

#endif