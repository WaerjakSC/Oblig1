#ifndef NODE_T_H
#define NODE_T_H

#include <string>
#include <sstream>
#include <iostream>

namespace ADS101 {

template<class T>
class Node_t
{
private:
    T m_tegn;            // Data-del
    Node_t<T>* m_neste;      // Datastruktur-del
public:
    Node_t(T tegn, Node_t<T>* neste = nullptr)
        : m_tegn(tegn), m_neste(neste)
    {
    }
    ~Node_t()
    {
        delete m_neste;
    }
    Node_t(const Node_t &other) : m_tegn(*other.m_tegn), m_neste(0)
    {
        if (other.m_neste != 0)
        {
            m_neste = new Node_t<T>(*other.tail);
        }
    }
    std::string toString() const
    {
        std::ostringstream oss;
        oss << m_tegn;
        return oss.str();
    }
    Node_t* hentNeste() const { return m_neste; }

    void settNeste(Node_t* c) { m_neste = c; }

    void skrivBaklengs() const
    {
        if (m_neste)
            m_neste->skrivBaklengs();           // Main: liste->skrivBaklengs();
        std::cout << m_tegn << " ";
    }
    Node_t& operator= (const Node_t& other)
    {
        if (this == &other)
        {
            return *this;
        }
        Node_t<T>* oldTop = m_neste;
        m_neste = new Node_t<T>(*other.m_neste);
        delete oldTop;

        m_tegn = other.m_tegn;

        return *this;
    }
    void pop()
    {
        Node_t<T>* oldTop = m_neste;
        m_tegn = m_neste->m_tegn;
        m_neste = m_neste->m_neste;
        oldTop->m_neste = 0;
        delete oldTop;
    }
    void push(T val)
    {
        m_neste = new Node_t<T>(m_tegn, m_neste);
        m_tegn = val;
    }

    T hentData() const { return m_tegn; }

    bool isLast() { return m_neste == nullptr; }
    int getSize() const
    {
        int i = 0;
        for (const Node_t<T>* cur = this; cur != nullptr; cur = cur->m_neste, i++){}
        return i;
    }

};
}
#endif // NODE_T_H
