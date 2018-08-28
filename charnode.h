// ADS101 Algoritmer og datastrukturer H2017-2018

#ifndef CHARNODE_H
#define CHARNODE_H
#include <string>


namespace ADS101 {
    class stack;
    class node_template
    {
    public:
        node_template(char tegn='0', node_template* neste=nullptr);
        std::string toString() const;
        node_template* hentNeste() const;
        void settNeste(node_template* c);
        void skrivBaklengs() const;
        static int hentAntall();
        char hentData() const;
        ~node_template();
    private:
        char m_tegn;            // Data-del
        static int s_antall;
        node_template* m_neste;      // Datastruktur-del
    };
}
#endif // CHARNODE_H
