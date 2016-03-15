#include "Post.hpp"

#include <iostream>
using namespace std;

IPost::IPost()
{
    m_deleted = false;
}

void IPost::DeletePost()
{
    m_deleted = true;
}

void WallPost::DisplayPost()
{
    cout << m_content << endl;
    cout << m_date << endl;
}

void SponsoredPost::DisplayPost()
{
    WallPost::DisplayPost();
    cout << "SPONSORED POST" << endl;
}

void PrivatePost::DisplayPost()
{
    cout << "FROM: " << m_author->GetUsername()
        << "\tTO: " << m_recipient->GetUsername() << endl;
    cout << m_content << endl;
    cout << m_date << endl;
}
