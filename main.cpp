#include <QCoreApplication>
#include "charnode.h"
#include "stack.h"
#include "node_template.h"
#include "stack_template.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    stack* liste = new stack('h');
    liste->push('e');
    liste->push('l');
    liste->push('p');
    liste->push('m');
    liste->push('e');

    // TODO: Put these couts into their own functions
    std::cout << "Current contents of stack: ";
    for (ADS101::CharNode* p = liste->getHead(); p!=nullptr; p=p->hentNeste())
        std::cout << p->hentData();


    std::cout << "\nWritten backwards: ";
    liste->getHead()->skrivBaklengs();
    std::cout <<'\n';

    std::cout << "Top is: " << liste->top() << '\n';
    std::cout << "Size of stack: " << liste->size();

    liste->pop();
    liste->pop();
    std::cout << "\nCurrent contents of stack: ";
    for (ADS101::CharNode* p = liste->getHead(); p!=nullptr; p=p->hentNeste())
        std::cout << p->hentData();


    std::cout << "\nWritten backwards: ";
    liste->getHead()->skrivBaklengs();
    liste->empty();
    std::cout << "\nEmptied stack... ";
    for (ADS101::CharNode* p = liste->getHead(); p!=nullptr; p=p->hentNeste())
        std::cout << p->hentData();
    std::cout << "\nSize of stack: " << liste->size();

    //    // Slette den første i lista
    //    ADS101::CharNode* ut = liste;
    //    liste = liste->hentNeste();
    //    delete ut;

    //    std::cout << std::endl << "static antall: " << liste->hentAntall() << std::endl;
    return a.exec();
}
