#ifndef STACK_H
#define STACK_H

#include "charnode.h"


class stack
{
public:
    stack(char ch = '0');
    void push(char ch);
    char top();
    char pop();
    void empty();
    int size();
    ADS101::CharNode* getHead();
private:
    ADS101::CharNode* head;
};

#endif // STACK_H
