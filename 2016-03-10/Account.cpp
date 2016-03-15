#include "Account.hpp"

void IAccount::AddPost( Post* ptrPost )
{
    m_postPtrs.push_back( ptrPost );
}

void IAccount::DisplayPosts()
{
    for ( int i = 0; i < m_postPtrs.size(); i++ )
    {
        cout << m_postPtrs[i]->content << endl << endl;
    }
}
