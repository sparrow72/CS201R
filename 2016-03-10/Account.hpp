#ifndef _ACCOUNT
#define _ACCOUNT

#include <string>
#include <vector>
#include <iostream>
using namespace std;

#include "Post.hpp"

class IAccount
{
    public:
    string GetUsername()                    { return m_username; }
    void SetUsername( const string& val )   { m_username = val; }

    virtual string AccountType() = 0;
    void AddPost( IPost* ptrPost );
    void DisplayPosts();

    protected:
    string m_username;
    vector<IPost*> m_postPtrs;
};

class UserAccount : public IAccount
{
    public:
    virtual string AccountType() { return "USER"; }
};

class AdAccount : public IAccount
{
    public:
    virtual string AccountType() { return "ADVERT"; }
};

class AdminAccount : public IAccount
{
    public:
    virtual string AccountType() { return "ADMIN"; }
};

#endif




//	string name;
//	vector<Post> posts;
//	Post& operator[](const int index);
//	void newPost(vector<Post>& wall);
