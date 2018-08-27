// ADS101 Algoritmer og datastrukturer H2017-2018

#ifndef NODE_TEMPLATE_H
#define NODE_TEMPLATE_H

#include <string>

namespace ADS101 {
    class NodeTemplate
    {
    public:
        NodeTemplate(char tegn='0', NodeTemplate* neste=nullptr);
        std::string toString() const;
        NodeTemplate* hentNeste() const;
        void settNeste(NodeTemplate* c);
        void skrivBaklengs() const;
        static int hentAntall();
        char hentData() const;
        ~NodeTemplate();
    private:
        char m_tegn;            // Data-del
        static int s_antall;
        NodeTemplate* m_neste;      // Datastruktur-del
    };
}
#endif // NODE_TEMPLATE_H
