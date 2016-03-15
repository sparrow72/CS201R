#ifndef _POST
#define _POST

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class IAccount;

class IPost
{
    public:
    void DeletePost();

    protected:
    string m_content;
    string m_date;
    IAccount* m_author;
    bool m_deleted;
    vector<IAccount*> m_likedAccountPtrs;
};

class WallPost : public IPost
{
    public:
    void AddLike( IAccount* ptrAccount );
    void WritePost( IAccount* ptrAuthor );

    private:
    IAccount* m_responseTo;
};

class SponsoredPost : public WallPost
{
    public:

    private:
    IAccount* m_sponsor;
    string m_url;
};

class PrivatePost : public IPost
{
    public:
    void WritePost( IAccount* ptrAuthor, IAccount* ptrRecipient );

    private:
    IAccount* m_recipient;
};

//class Post
//{
//public:
//	string content;
//	string mood;
//	string date;
//	string author;
//
//	friend ostream& operator<<(ostream& out, Post& item);
//};

#endif
