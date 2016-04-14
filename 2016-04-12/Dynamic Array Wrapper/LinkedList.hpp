#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
using namespace std;

template <typename T>
class Node
{
    public:
    Node()
    {
        ptrNext = nullptr;
    }

    ~Node()
    {
        if ( ptrNext != nullptr )
        {
            delete ptrNext;
            ptrNext = nullptr;
        }
    }

    T data;
    Node* ptrNext;
};

template <typename T>
class LinkedList
{
    public:
    LinkedList()
    {
        m_ptrFirst = nullptr;
        m_size = 0;
    }

    ~LinkedList()
    {
        if ( m_ptrFirst == nullptr )
        {
            delete m_ptrFirst;
            m_ptrFirst = nullptr;
        }
    }

    bool Insert( T data )
    {
        cout << "insert data " << data << endl;
        Node<T>* newNode = new Node<T>;
        newNode->data = data;

        // Empty List
        if ( m_ptrFirst == nullptr )
        {
            cout << "Insert to first" << endl;
            m_ptrFirst = newNode;
        }

        // Not-empty list
        else
        {
            Node<T>* ptrCurrent = m_ptrFirst;
            while ( ptrCurrent->ptrNext != nullptr )
            {
                ptrCurrent = ptrCurrent->ptrNext;
            }

            ptrCurrent->ptrNext = newNode;
        }

        m_size++;

        return true;
    }

    T GetAt( int index )
    {
        if ( index >= m_size )
        {
            return NULL;
        }

        int counter = 0;

        Node<T>* ptrCurrent = m_ptrFirst;
        while ( counter++ != index )
        {
            ptrCurrent = ptrCurrent->ptrNext;
        }

        return ptrCurrent->data;
    }

    int Find( T searchObject )
    {
        int index = 0;
        return Find( searchObject, m_ptrFirst, index );
    }

    private:
    int Find( T searchObject, Node<T>* ptr, int index )
    {
        if ( searchObject == ptr->data )
        {
            return index;
        }
        if ( index + 1 == m_size )
        {
            return -1;
        }
        return Find( searchObject, ptr->ptrNext, index+1 );
    }

    Node<T>* m_ptrFirst;
    int m_size;
};

#endif
