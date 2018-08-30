#include <QCoreApplication>
#include "charnode.h"
#include "stack.h"
#include "node_t.h"
#include "stack_t.h"
#include <iostream>
void regularStack();
template<typename T>
void printStack(ADS101::stack_t<T> &liste);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    regularStack(); // Print the non-template stack
    ADS101::stack_t<int> liste(1); // Initialize and add ints to stack template
    for (int i = 2; i<6; i++)
    {
        liste.push(i);
    }
    liste.push(70);

    printStack(liste); // Print template stack of type int

    ADS101::stack_t<char> charliste('h'); // Initialize and add chars to stack template
    charliste.push('e');
    charliste.push('l');
    charliste.push('p');
    charliste.push('m');
    charliste.push('e');

    printStack(charliste); // Print template stack of type char


    return a.exec();
}
/**
 * Template version of stack
 * classes Node_t and stack_t
 */
template<typename T>
void printStack(ADS101::stack_t<T> &liste)
{
    std::cout << "Printing stack:\n";
    std::cout << "Top is: " << liste.top() << '\n';
    std::cout << "Size of stack: " << liste.size();
    std::cout << liste;

    liste.pop();
    liste.pop();
    std::cout << "\nPopped two items...";
    std::cout << liste;
    liste.empty();
    std::cout << "\nEmptied stack... ";
    std::cout << liste;
    std::cout << "\nSize of stack: " << liste.size() << '\n'<< '\n';

}
/**
 * @brief regularStack
 * Non-template stack
 * Takes only chars
 * classes CharNode and stack
 */
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
    std::cout << "\nSize of stack: " << liste->size() << '\n'<< '\n';;
}
