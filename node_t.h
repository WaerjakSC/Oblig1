#ifndef NODE_T_H
#define NODE_T_H

#include <string>
#include <sstream>
#include <iostream>

namespace ADS101 {

template<class T>
class Node_t
{
private:
    T m_val;            // Data-del
    Node_t<T>* m_prev;      // Datastruktur-del
public:
    Node_t(T val, Node_t<T>* neste = nullptr)
        : m_val(val), m_prev(neste)
    {
    }
    ~Node_t()
    {
        delete m_prev;
    }
    /**
     * @brief toString
     * @return
     * Read contents of each node into an ostringstream
     */
    std::string toString() const
    {
        std::ostringstream oss;
        oss << m_val;
        return oss.str();
    }
    /**
     * @brief getPrev
     * @return next node in line
     */
    Node_t* getPrev() const { return m_prev; }

    /**
     * @brief printReversed
     * Output contents of nodes in reverse order, useful for collection of chars in a string-like order
     */
    void printReversed() const
    {
        if (m_prev)
            m_prev->printReversed();
        std::cout << m_val << " ";
    }
    /**
     * @brief pop
     * @return
     * Removes the last item entered into the node collection
     * Stack is only a shallow container for the nodes. Owns the top node, every other node is owned by successive nodes
     * Thus any functions that call nodes other than top will need to go deeper and use functions in Node_t
     */
    void pop()
    {
        Node_t<T>* oldTop = m_prev;
        m_val = m_prev->m_val;
        m_prev = m_prev->m_prev;
        oldTop->m_prev = 0;
        delete oldTop;
    }
    /**
     * @brief push
     * @param val
     * Add a new item to the stack
     */
    void push(T val)
    {
        m_prev = new Node_t<T>(m_val, m_prev);
        m_val = val;
    }

    /**
     * @brief getVal
     * @return value contained by current node
     */
    T getVal() const { return m_val; }

    bool isLast() { return m_prev == nullptr; }
    /**
     * @brief getSize
     * @return current size of stack network
     */
    int getSize() const
    {
        int i = 0;
        for (const Node_t<T>* cur = this; cur != nullptr; cur = cur->m_prev, i++){}
        return i;
    }

};
}
#endif // NODE_T_H
