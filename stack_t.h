#ifndef STACK_TEMPLATE_H
#define STACK_TEMPLATE_H

#include "charnode.h"

namespace ADS101{
class stack_t
{
public:
    stack_t(char ch = '0');
    void push(char ch);
    char top();
    char pop();
    void empty();
    int size();
    node_template* getHead();
private:
    node_template* head;
};
}
#endif // STACK_TEMPLATE_H
