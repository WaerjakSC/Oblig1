#include "stack.h"
#include <memory>
#include <iostream>


namespace ADS101 {
stack::stack(char ch)
{
    head = new CharNode(ch);
}
/**
 * @brief stack::push
 * @param ch
 * Add a new item to the stack
 */
void stack::push(char ch)
{
    CharNode* tmp = new CharNode(ch); // Create a new node with containing the char ch. Constructor sets m_neste to nullptr.
    //  Make tmp's m_neste point to the top of the stack
    head = tmp; // Update the new head in stack class
}
/**
 * @brief stack::top
 * @return
 * Returns the last item entered into the stack
 */
char stack::top()
{
    if (head != nullptr)
    {
        return head->hentData();
    }
    std::cout << "Stack is empty.\n";
    return 0;

}
/**
 * @brief stack::pop
 * @return
 * Removes the last item entered into the stack and reads its contents into a variable if needed
 */
char stack::pop()
{
    if (head != nullptr) // If head is not a nullptr (won't run if stack is empty)
    {
        CharNode* tmp = head; // Create temporary object of type CharNode pointing to stack head
        head = head->hentNeste(); // Set the head of the stack to point to the next item in the stack
        char ch = tmp->hentData(); // store the data in the item into a temporary char
        delete tmp; // delete the last pointer to that address

        return ch; // Return the char in case you want to know what you just deleted
    }

    std::cout << "Stack is empty, nothing to pop.\n";
    return 0;

}

void stack::empty()
{
    CharNode* tmp=head; // Iterative process similar to pop
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
int stack::size()
{
    return head->hentAntall();
}
/**
 * @brief stack::getHead
 * @return Getter for top of stack
 */
CharNode *stack::getHead()
{
    return head;
}
}
