#ifndef STACK_T_H
#define STACK_T_H

#include "node_t.h"
#include "stack.h"
#include <memory>
#include <stdexcept>
#include <iostream>

namespace ADS101{

template<class T>
class stack_t
{
private:
    Node_t<T>* head;
    bool isEmpty() const { return head == nullptr; }
public:
    stack_t() : head(){}
    stack_t(const T& ch)
    {

        head = new Node_t<T>(ch);
    }

    ~stack_t() {
        delete head;
    }

    /**
     * @brief push
     * @param ch
     * Add a new item to the stack
     */
    void push(const T& ch)
    {
        if (isEmpty()) // If stack is empty, set head variable to point to a node with value ch
        {
            head = new Node_t<T>(ch);
        }
        else // otherwise, go deeper and have the node use its own push to add it from there
        {
            head->push(ch);
        }
    }

    /**
     * @brief top
     * @return
     * Returns the last item entered into the stack
     */
    T top()
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty.\n";
            return 0;
        }
        return head->getVal();
    }
    /**
     * @brief pop
     * @return
     * Removes the last item entered into the stack and reads its contents into a variable if needed
     * Stack is only a shallow container for the nodes. Owns the top node, every other node is owned by successive nodes
     * Thus any functions that call nodes other than top will need to go deeper and use functions in Node_t
     */
    T pop(){
        T result = top();

        if (head->isLast()){ // if this is the last item to pop, delete the pointer and set head to a nullptr
            delete head;
            head = nullptr;
        }
        else { // Else follow head to the Node_t class and pop it from there
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
    void empty()
    {
        // Not sure exactly why I needed to set int i to -2, but otherwise it wouldn't check if hentNeste() was a nullptr
        for(int i = -2; i <= head->getSize(); i++)
        {
            if (head == nullptr)
            { break; }
            if (head->getPrev() == nullptr){ // if this is the last item to pop, delete the pointer and set head to a nullptr
                delete head;
                head = nullptr;
            }
            else { // Else follow head to the Node_t class and pop it from there
                head->pop();
            }
        }
    }
    /**
     * @brief size
     * @return Returns the total size of the stack
     */
    int size() const{
        if (isEmpty()){ return 0; }
        return head->getSize();
    }

    // Overload the << operator so that using "stackName" in cout will use this function instead
    friend std::ostream& operator<< (std::ostream &out, const stack_t<T> &stack)
    {
        if (stack.head != nullptr)
        {
            out << "\nCurrent contents of stack: ";
            for (Node_t<T>* p = stack.head; p!=nullptr; p=p->getPrev())
                out << p->getVal() << " ";

            out << "\nWritten backwards: ";
            stack.head->printReversed();
            out <<'\n';
            return out;
        }
        else {
            out << "\nStack is empty!";
            return out;
        }

    }

};
}

#endif // STACK_T_H
