#include "stack.h"
#include <iostream>
#include <memory>

namespace ADS101 {
stack::stack(char ch) { head = new CharNode(ch); }
/**
 * @brief stack::push
 * @param ch
 * Add a new item to the stack
 */
void stack::push(char ch) {
  auto *tmp = new CharNode(ch, head);
  head = tmp;
}
/**
 * @brief stack::top
 * @return
 * Returns the last item entered into the stack
 */
char stack::top() {
  if (head != nullptr) {
    return head->hentData();
  }
  // Else...
  std::cout << "Stack is empty.\n";
  return 0;
}
/**
 * @brief stack::pop
 * @return
 * Removes the last item entered into the stack and reads its contents into a
 * variable if needed
 */
char stack::pop() {
  if (head != nullptr) {
    CharNode *tmp = head;
    head = head->hentNeste();

    char ch = tmp->hentData();
    delete tmp;

    return ch; // Return the char in case you want to know what you just deleted
  }
  // Else...
  std::cout << "Stack is empty, nothing to pop.\n";
  return 0;
}
/**
 * @brief stack::empty
 * Empties the stack (in hindsight should probably have been just a bool to
 * check if stack is empty, but I'm leaving it as it is)
 */
void stack::empty() {
  CharNode *tmp = head;
  while (tmp != nullptr) {
    head = head->hentNeste();
    delete tmp;
    tmp = head;
  }
}
/**
 * @brief stack::size
 * @return Returns the total size of the stack
 */
int stack::size() { return head->hentAntall(); }
/**
 * @brief stack::getHead
 * @return Getter for top of stack
 */
CharNode *stack::getHead() { return head; }
} // namespace ADS101
