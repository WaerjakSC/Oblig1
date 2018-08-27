// ADS101 Algoritmer og datastrukturer H2017-2018

#include <iostream>
#include "charnode.h"
#include <stack>
//using namespace ADS101;
int main()
{
    ADS101::CharNode* liste = new ADS101::CharNode('a');
    liste = new ADS101::CharNode('b', liste);
    liste = new ADS101::CharNode('c', liste);
    liste = new ADS101::CharNode('d', liste);

    for (ADS101::CharNode* p=liste; p!=0; p=p->hentNeste())
        std::cout << p->hentData();

    std::cout << std::endl << "static antall: " << liste->hentAntall();
    std::cout << std::endl;

    std::cout << "Skriver baklengs; ";
    liste->skrivBaklengs();

    // Slette den første i lista
    ADS101::CharNode* ut = liste;
    liste = liste->hentNeste();
    delete ut;

    std::cout << std::endl << "static antall: " << liste->hentAntall() << std::endl;

    return 0;
}


