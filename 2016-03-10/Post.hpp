#ifndef _POST
#define _POST

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

#endif
