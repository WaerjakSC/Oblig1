#ifndef NODE_T_H
#define NODE_T_H

#include <string>
#include <sstream>
#include <iostream>
#include "stack_t.h"

namespace ADS101 {

template<class T>
class Node_t
{
private:
    T m_tegn;            // Data-del
    static int s_antall;
    Node_t* m_neste;      // Datastruktur-del
public:
    Node_t(T tegn, Node_t* neste)
        : m_tegn(tegn), m_neste(neste)
    {
        //m_tegn = tegn;
        s_antall ++;
    }
    ~Node_t()
    {
        s_antall --;
    }
    std::string toString() const
    {
        std::ostringstream oss;
        oss << m_tegn;
        return oss.str();
    }

    Node_t* hentNeste() const
    {
        return m_neste;
    }

    void settNeste(Node_t* c)
    {
        m_neste = c;
    }

    void skrivBaklengs() const
    {
        if (m_neste)
            m_neste->skrivBaklengs();           // Main: liste->skrivBaklengs();
        std::cout << m_tegn;
    }

    int hentAntall()
    {
        return s_antall;
    }

    T hentData() const
    {
        return m_tegn;
    }

};
}
#endif // NODE_T_H
