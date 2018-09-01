#ifndef STACK_H
#define STACK_H

#include "charnode.h"
#include <memory>

namespace ADS101 {
class stack {
public:
  stack(char ch = '0');
  void push(char ch);
  char top();
  char pop();
  void empty();
  int size();
  CharNode *getHead();

private:
  CharNode *head;
};
} // namespace ADS101
#endif // STACK_H
