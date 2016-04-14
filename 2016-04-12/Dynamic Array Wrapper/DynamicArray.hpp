#ifndef DYNAMIC_ARRAY_HPP
#define DYNAMIC_ARRAY_HPP

#include <iostream>
using namespace std;

template<typename T>
class DynamicArray
{
    public:
    DynamicArray( int size )
    {
        m_list = NULL;
        m_list = new T[ size ];
    }

    ~DynamicArray()
    {
        if ( m_list != NULL )
        {
            delete [] m_list;
            m_list = NULL;
        }
    }

    private:
    T* m_list;
};

#endif
