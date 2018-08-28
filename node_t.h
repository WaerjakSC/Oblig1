// ADS101 Algoritmer og datastrukturer H2017-2018

#ifndef NODE_TEMPLATE_H
#define NODE_TEMPLATE_H

#include <string>

namespace ADS101 {
    class node_t
    {
    public:
        node_t(char tegn='0', node_t* neste=nullptr);
        std::string toString() const;
        node_t* hentNeste() const;
        void settNeste(node_t* c);
        void skrivBaklengs() const;
        static int hentAntall();
        char hentData() const;
        ~node_t();
    private:
        char m_tegn;            // Data-del
        static int s_antall;
        node_t* m_neste;      // Datastruktur-del
    };
}
#endif // NODE_TEMPLATE_H
