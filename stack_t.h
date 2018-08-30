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
    stack_t(const stack_t &other) : head()
    {
        if (other.isEmpty())
        { return; }

        head = new Node_t<T>(*other.head);
    }
    ~stack_t() {
        delete head;
    }

    stack_t &operator= (const stack_t &other)
    {
        if (this == &other){
            return *this;
        }

        Node_t<T>* newTop = nullptr;
        if (!other.isEmpty()){
            newTop = new Node_t<T>(*other.head);
        }
        delete head;
        head = newTop;

        return *this;
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
        return head->hentData();
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

    void empty()
    {
        for(int i = -2; i <= head->getSize(); i++)
        {
            if (head == nullptr)
            { break; }
            if (head->hentNeste() == nullptr){ // if this is the last item to pop, delete the pointer and set head to a nullptr
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
            for (Node_t<T>* p = stack.head; p!=nullptr; p=p->hentNeste())
                out << p->hentData() << " ";

            out << "\nWritten backwards: ";
            stack.head->skrivBaklengs();
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
