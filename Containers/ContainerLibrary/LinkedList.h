#ifndef LL_H
#define LL_H

#include "IIntContainer.h"

class Node
{
public:
    Node(uint32_t val, Node* next, Node* prev) :
        m_val(val),
        m_next(next),
        m_prev(prev)
    {
    }

    Node* m_next;
    Node* m_prev;
    uint32_t m_val;
};

/// \class LinkedList
/// \brief This mimics behavior of a LinkedList
///     Each time push() is called, it will create a Node at the end of the previous node and become the new tail
///     Each time pop() is called, it will remove the last node in the chain (the tail)
///     Notes:
///         Keep track of news and deletes. Don't create memory leaks.
class LinkedList : public IIntContainer
{
public:
    /// \brief Construcotr
    LinkedList();

    /// \brief Destructor
    ~LinkedList() = default;

    /// \brief This function pushes the argument into the container
    /// \param [in] valToPush The value to push into the object
    /// return void
    virtual void push(const uint32_t valToPush) override;

    /// \brief This function pops the argument from the container, removing and returning it
    ///     Note: Check for an empty container
    /// return uint32_t the value popped from the container
    virtual uint32_t pop() override;

    /// \brief This function checks the next value which can be popped but does not remove it
    ///     Note: Check for empty container
    /// return Next value to be popped
    virtual uint32_t peek() override;

    /// \brief Insert a value at the offest
    ///     Note: If you have a container of size 10, assuming an array of arr[10] you could insert a value at arr[5]
    ///         This shouldn't overwrite the value, but instead insert between the existing 4 and 5 unless the container is full
    /// return void
    virtual void insertAt(const uint32_t offset, const uint32_t val) override;

    /// \brief Returns the current size of the container
    /// return Size of the container
    virtual uint32_t size() override;

    /// \brief Clears the container
    /// return void
    virtual void clear() override;

protected:
    uint32_t m_currLength;
    Node* m_head;
    Node* m_tail;

private:

};

#endif

