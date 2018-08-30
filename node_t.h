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
    Node_t* m_neste;      // Datastruktur-del
public:
    Node_t(T tegn = 0, Node_t* neste = nullptr)
        : m_tegn(tegn), m_neste(neste)
    {
    }
    ~Node_t()
    {
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
        std::cout << m_tegn;
    }
    T hentData() const { return m_tegn; }

};
}
#endif // NODE_T_H
