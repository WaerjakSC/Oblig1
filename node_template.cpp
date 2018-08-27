// ADS101 Algoritmer og datastrukturer H2017-2018

#include <string>
#include <sstream>
#include <iostream>
#include "node_template.h"
#include "stack.h"

namespace ADS101 {
int NodeTemplate::s_antall;

NodeTemplate::NodeTemplate(char tegn, NodeTemplate* neste)
    : m_tegn(tegn), m_neste(neste)
{
    //m_tegn = tegn;
    s_antall ++;

}

std::string NodeTemplate::toString() const
{
    std::ostringstream oss;
    oss << m_tegn;
    return oss.str();
}

NodeTemplate* NodeTemplate::hentNeste() const
{
    return m_neste;
}

void NodeTemplate::settNeste(NodeTemplate* c)
{
    m_neste = c;
}
void NodeTemplate::skrivBaklengs() const
{
    if (m_neste)
        m_neste->skrivBaklengs();           // Main: liste->skrivBaklengs();
    std::cout << m_tegn;
}
int NodeTemplate::hentAntall()
{
    return s_antall;
}

NodeTemplate::~NodeTemplate()
{
    s_antall --;
}

char NodeTemplate::hentData() const
{
    return m_tegn;
}
}
