#ifndef STACK_TEMPLATE_H
#define STACK_TEMPLATE_H

#include "stack_template.h"
#include "charnode.h"

class stack_template
{
public:
    stack_template(char ch = '0');
    void push(char ch);
    char top();
    char pop();
    void empty();
    int size();
    ADS101::CharNode* getHead();
private:
    ADS101::CharNode* head;
};

#endif // STACK_TEMPLATE_H
