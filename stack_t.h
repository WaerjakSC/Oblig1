#ifndef STACK_T_H
#define STACK_T_H

#include "node_t.h"
#include "stack.h"
#include <memory>
#include <iostream>

namespace ADS101{

template<class T>
class stack_t
{
private:
    Node_t<T>* head;
    int m_size{ 1 };
public:
    stack_t(const T& ch)
    {

        head = new Node_t<T>(ch);
    }
    /**
     * @brief push
     * @param ch
     * Add a new item to the stack
     * Why does this make the template go crazy? Something to do with Node_t or stack_t?
     */
    void push(const T& ch)
    {
        m_size++;
        std::unique_ptr<Node_t<T>> tmp(new Node_t<T>(ch)); // Create a new node with containing the char ch. Constructor sets m_neste to nullptr.
        //  Make tmp's m_neste point to the top of the stack
        head = tmp.get(); // Update the new head in stack class
    }

    /**
     * @brief top
     * @return
     * Returns the last item entered into the stack
     */
    T top()
    {
        if (head != nullptr)
        {
            return head->hentData();
        }
        std::cout << "Stack is empty.\n";
        return 0;
    }
    Node_t<T>* getHead() { return head; }
    /**
     * @brief pop
     * @return
     * Removes the last item entered into the stack and reads its contents into a variable if needed
     */
    T pop()
    {
        if (head != nullptr) // If head is not a nullptr (won't run if stack is empty)
        {
            Node_t<T>* tmp = head; // Create temporary object of type CharNode pointing to stack head
            head = head->hentNeste(); // Set the head of the stack to point to the next item in the stack
            T ch = tmp->hentData(); // store the data in the item into a temporary container
            delete tmp; // delete the last pointer to that address

            return ch; // Return ch in case you want to know what you just deleted
        }
        std::cout << "Stack is empty, nothing to pop.\n";
        return 0;
    }
    void empty()
    {
        Node_t<T>* tmp=head; // Iterative process similar to pop
        while(tmp != nullptr)
        {
            head=head->hentNeste(); // Switch head to point to the next latest item in stack
            delete tmp; // Delete/free up the address tmp is attached to (leaving no pointers to that address)
            tmp= head; // repeat process
        }
    }
    /**
     * @brief stack::size
     * @return Returns the total size of the stack
     */
    int size() { return m_size; }
    /**
     * @brief stack::getHead
     * @return Getter for top of stack
     */
    template<typename T2>
    friend std::ostream& operator<< (std::ostream &out, const stack_t<T2> &stack)
    {
        out << "\nCurrent contents of stack: ";
        for (Node_t<T2>* p = stack.head; p!=nullptr; p=p->hentNeste())
            out << p->hentData();

        out << "\nWritten backwards: ";
        stack.head->skrivBaklengs();
        out <<'\n';
        return out;
    }

};
}

#endif // STACK_T_H
