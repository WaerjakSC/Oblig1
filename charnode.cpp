// ADS101 Algoritmer og datastrukturer H2017-2018

#include <string>
#include <sstream>
#include <iostream>
#include "charnode.h"
#include "stack.h"

namespace ADS101 {
int node_template::s_antall;

node_template::node_template(char tegn, node_template* neste)
    : m_tegn(tegn), m_neste(neste)
{
    //m_tegn = tegn;
    s_antall ++;

}

std::string node_template::toString() const
{
    std::ostringstream oss;
    oss << m_tegn;
    return oss.str();
}

node_template* node_template::hentNeste() const
{
    return m_neste;
}

void node_template::settNeste(node_template* c)
{
    m_neste = c;
}
void node_template::skrivBaklengs() const
{
    if (m_neste)
        m_neste->skrivBaklengs();           // Main: liste->skrivBaklengs();
    std::cout << m_tegn;
}
int node_template::hentAntall()
{
    return s_antall;
}

node_template::~node_template()
{
    s_antall --;
}

char node_template::hentData() const
{
    return m_tegn;
}
}
