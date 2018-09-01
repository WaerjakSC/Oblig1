#include "charnode.h"
#include "node_t.h"
#include "stack.h"
#include "stack_t.h"
#include <QCoreApplication>
#include <iostream>
#include <stack>

void regularStack();
template <typename T> void printStack(ADS101::stack_t<T> &liste);
template <typename T> void stackReadOut(std::stack<T> liste);
template <typename T> void printStack2(std::stack<T> &liste);

int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);
  regularStack();                // Print the non-template stack
  ADS101::stack_t<int> liste(1); // Initialize and add ints to stack template
  for (int i = 2; i < 6; i++) {
    liste.push(i);
  }
  liste.push(70);

  printStack(liste); // Print template stack of type int

  ADS101::stack_t<char> charliste('h');
  charliste.push('e');
  charliste.push('l');
  charliste.push('p');
  charliste.push('m');
  charliste.push('e');

  printStack(charliste); // Print template stack of type char

  std::cout << "Now doing the same using std::stack:\n";
  std::stack<int> stack; // Initialize and add ints to stack template
  for (int i = 1; i < 6; i++) {
    stack.push(i);
  }
  liste.push(70);
  printStack2(stack);

  std::stack<char> stackchar;
  stackchar.push('h');
  stackchar.push('e');
  stackchar.push('l');
  stackchar.push('p');
  stackchar.push('m');
  stackchar.push('e');

  printStack2(stackchar);
  std::cout << "\n...and done.";
  return a.exec();
}
/**
 * Template version of stack
 * classes Node_t and stack_t
 */
template <typename T> void printStack(ADS101::stack_t<T> &liste) {
  std::cout << "Printing stack...\n";
  std::cout << liste;
  std::cout << "Top is: " << liste.top() << '\n';
  std::cout << "Size of stack: " << liste.size();

  liste.pop();
  liste.pop();
  std::cout << "\nPopped two items...";
  std::cout << liste;
  liste.empty();
  std::cout << "\nEmptied stack... ";
  std::cout << liste;
  std::cout << "\nSize of stack: " << liste.size() << '\n' << '\n';
}

/**
 * Switched to using std::stack instead of my own template
 * Since std::stack doesn't seem to have its own operator overload to print out
 * its contents, I added a small function to do that (stackReadOut())
 */
template <typename T> void printStack2(std::stack<T> &liste) {
  std::cout << "Printing stack...";
  std::cout << "\nCurrent contents of stack: ";
  stackReadOut(liste);
  std::cout << "\nTop is: " << liste.top();
  std::cout << "\nSize of stack: " << liste.size();

  liste.pop();
  liste.pop();
  std::cout << "\nPopped two items...";
  std::cout << "\nCurrent contents of stack: ";
  stackReadOut(liste);
  /* sidenote - it seems I originally misunderstood the purpose of stack's empty
   * function, so in my own versions empty() actually clears the stack instead
   * of returning a bool
   */
  while (!liste.empty()) {
    liste.pop();
  }
  std::cout << "\nEmptied stack... ";
  std::cout << "\nSize of stack: " << liste.size() << '\n' << '\n';
}

template <typename T>
/**
 * @brief stackReadOut
 * @param liste
 * Simply reads out the stack twice
 */
void stackReadOut(std::stack<T> liste) {
  std::vector<T> tempReverse;
  for (auto p = liste; !p.empty(); p.pop()) {
    std::cout << p.top() << " ";
  }
  for (auto p = liste; !p.empty(); p.pop()) {
    tempReverse.insert(tempReverse.begin(), p.top());
  }
  std::cout << "\nWritten backwards: ";
  for (auto temp : tempReverse) {
    std::cout << temp << " ";
  }
}
/**
 * @brief regularStack
 * Non-template stack
 * Takes only chars
 * classes CharNode and stack
 */
void regularStack() {
  std::cout << "Printing stack...\n";
  std::unique_ptr<ADS101::stack> liste(new ADS101::stack('h'));
  liste->push('e');
  liste->push('l');
  liste->push('p');
  liste->push('m');
  liste->push('e');

  std::cout << "Current contents of stack: ";
  for (ADS101::CharNode *p = liste->getHead(); p != nullptr; p = p->hentNeste())
    std::cout << p->hentData();

  std::cout << "\nWritten backwards: ";
  liste->getHead()->skrivBaklengs();
  std::cout << '\n';

  std::cout << "Top is: " << liste->top() << '\n';
  std::cout << "Size of stack: " << liste->size();

  liste->pop();
  liste->pop();
  std::cout << "\nCurrent contents of stack: ";
  for (ADS101::CharNode *p = liste->getHead(); p != nullptr; p = p->hentNeste())
    std::cout << p->hentData();

  std::cout << "\nWritten backwards: ";
  liste->getHead()->skrivBaklengs();
  liste->empty();
  std::cout << "\nEmptied stack... ";
  for (ADS101::CharNode *p = liste->getHead(); p != nullptr; p = p->hentNeste())
    std::cout << p->hentData();
  std::cout << "\nSize of stack: " << liste->size() << '\n' << '\n';
  ;
}
