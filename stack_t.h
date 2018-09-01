#ifndef STACK_T_H
#define STACK_T_H

#include "node_t.h"
#include "stack.h"
#include <iostream>
#include <memory>
#include <stdexcept>

namespace ADS101 {
/** Stack is only a shallow container for the nodes. Owns the top node, every
 * other node is owned by successive nodes. Any function that calls nodes
 * other than top will need to go deeper and use functions in Node_t
 */
template <class T> class stack_t {
public:
  stack_t() : head() {}
  stack_t(const T &ch) { head = new Node_t<T>(ch); }

  ~stack_t() { delete head; }

  /**
   * @brief push
   * @param ch
   * Add a new item to the stack
   */
  void push(const T &ch) {
    if (isEmpty()) {
      head = new Node_t<T>(ch);
    } else {
      head->push(ch);
    }
  }

  /**
   * @brief top
   * @return
   * Returns the last item entered into the stack
   */
  T top() const {
    if (isEmpty()) {
      std::cout << "Stack is empty.\n";
      return 0;
    }
    return head->getVal();
  }
  /**
   * @brief pop
   * @return item popped in case function was right-value for variable
   * Removes the last item entered into the stack and reads its contents into a
   * variable if needed
   */
  T pop() {
    T result = top();
    /* if this is the last item to pop, delete the pointer and set head to a
     * nullptr
     */
    if (head->isLast()) {
      delete head;
      head = nullptr;
    } else { // Else follow head to the Node_t class and pop it from there
      head->pop();
    }
    // returns item popped in case function was right-value for variable
    return result;
  }

  /**
   * @brief empty
   * Self-explanatory name
   * Just a bunch of successive pop() calls
   */
  void empty() {
    // Not sure exactly why I needed to set int i to -2, but otherwise it
    // wouldn't check if hentNeste() was a nullptr
    for (int i = -2; i <= head->getSize(); i++) {
      if (head == nullptr) {
        break;
      }
      if (head->getPrev() == nullptr) {
        delete head;
        head = nullptr;
      } else { // Else follow head to the Node_t class and pop it from there
        head->pop();
      }
    }
  }
  /**
   * @brief size
   * @return Returns the total size of the stack
   */
  int size() const {
    if (isEmpty()) {
      return 0;
    }
    return head->getSize();
  }

  /**
   * @desc Overload the << operator so that using "stackName" in cout will use
   * this function instead
   * @param out
   * @param stack
   * @return
   */
  friend std::ostream &operator<<(std::ostream &out, const stack_t<T> &stack) {
    if (stack.head != nullptr) {
      out << "\nCurrent contents of stack: ";
      for (Node_t<T> *p = stack.head; p != nullptr; p = p->getPrev())
        out << p->getVal() << " ";

      out << "\nWritten backwards: ";
      stack.head->printReversed();
      out << '\n';
      return out;
    } else {
      out << "\nStack is empty!";
      return out;
    }
  }

private:
  Node_t<T> *head;
  bool isEmpty() const { return head == nullptr; }
};
} // namespace ADS101

#endif // STACK_T_H
