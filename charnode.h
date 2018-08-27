// ADS101 Algoritmer og datastrukturer H2017-2018

#ifndef CHARNODE_H
#define CHARNODE_H

#include <string>

namespace ADS101 {
    class CharNode
    {
    public:
        CharNode(char tegn='0', CharNode* neste=nullptr);
        std::string toString() const;
        CharNode* hentNeste() const;
        void settNeste(CharNode* c);
        void skrivBaklengs() const;
        static int hentAntall();
        char hentData() const;
        ~CharNode();
    private:
        char m_tegn;            // Data-del
        static int s_antall;
        CharNode* m_neste;      // Datastruktur-del
    };
}
#endif // CHARNODE_H
