#include <QCoreApplication>
#include "charnode.h"
#include "stack.h"
#include "node_t.h"
#include "stack_t.h"
#include <iostream>
void regularStack();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ADS101::stack_t<int> liste(1);
    liste.push(2);
    liste.push(3);
    liste.push(4);
    liste.push(5);

    std::cout << "Current contents of stack: ";
    for (ADS101::Node_t<int>* p = liste.getHead(); p!=nullptr; p=p->hentNeste())
        std::cout << p->hentData();

    std::cout << "\nWritten backwards: ";
    liste.getHead()->skrivBaklengs();
    std::cout <<'\n';

    std::cout << "Top is: " << liste.top() << '\n';
    std::cout << "Size of stack: " << liste.size();

    liste.pop();
    liste.pop();
    std::cout << "\nCurrent contents of stack: ";
    for (ADS101::Node_t<int>* p = liste.getHead(); p!=nullptr; p=p->hentNeste())
        std::cout << p->hentData();


    std::cout << "\nWritten backwards: ";
    liste.getHead()->skrivBaklengs();
    liste.empty();
    std::cout << "\nEmptied stack... ";
    for (ADS101::Node_t<int>* p = liste.getHead(); p!=nullptr; p=p->hentNeste())
        std::cout << p->hentData();
    std::cout << "\nSize of stack: " << liste.size();
    return a.exec();
}

void regularStack()
{

    std::unique_ptr<ADS101::stack> liste(new ADS101::stack('h'));
    liste->push('e');
    liste->push('l');
    liste->push('p');
    liste->push('m');
    liste->push('e');

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
}
