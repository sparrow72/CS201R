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
    IPost();

    void DeletePost();
    virtual void DisplayPost() = 0;
    string GetContent() { return m_content; }

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
    WallPost() : IPost() {}

    void AddLike( IAccount* ptrAccount );
    void WritePost( IAccount* ptrAuthor );
    virtual void DisplayPost();

    private:
    IAccount* m_responseTo;
};

class SponsoredPost : public WallPost
{
    public:
    SponsoredPost() : WallPost() {}

    virtual void DisplayPost();

    private:
    IAccount* m_sponsor;
    string m_url;
};

class PrivatePost : public IPost
{
    public:
    PrivatePost() : IPost() {}
    void WritePost( IAccount* ptrAuthor, IAccount* ptrRecipient );
    virtual void DisplayPost();

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
