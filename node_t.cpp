// ADS101 Algoritmer og datastrukturer H2017-2018

#include <string>
#include <sstream>
#include <iostream>
#include "node_t.h"
#include "stack.h"

namespace ADS101 {
int node_t::s_antall;

node_t::node_t(char tegn, node_t* neste)
    : m_tegn(tegn), m_neste(neste)
{
    //m_tegn = tegn;
    s_antall ++;

}

std::string node_t::toString() const
{
    std::ostringstream oss;
    oss << m_tegn;
    return oss.str();
}

node_t* node_t::hentNeste() const
{
    return m_neste;
}

void node_t::settNeste(node_t* c)
{
    m_neste = c;
}
void node_t::skrivBaklengs() const
{
    if (m_neste)
        m_neste->skrivBaklengs();           // Main: liste->skrivBaklengs();
    std::cout << m_tegn;
}
int node_t::hentAntall()
{
    return s_antall;
}

node_t::~node_t()
{
    s_antall --;
}

char node_t::hentData() const
{
    return m_tegn;
}
}
