#ifndef FIFO_H
#define FIFO_H

#include "IIntContainer.h"

/// \class FIFO
/// \brief This mimics behavior in a vector (kind of). 
///     Notes: A normal vector will dynamically allocate space and if the limit is reached it will create more space
///             behind the scenes. Dont worry about that for now, get the base functionality
class FIFO : public IIntContainer
{
public:
    /// \brief Construcotr
    /// \param [in] length Length of the FIFO
    FIFO(uint32_t length);

    /// \brief Destructor
    ~FIFO() = default;

    /// \brief This function pushes the argument into the container
    /// \param [in] valToPush The value to push into the object
    /// return void
    virtual void push(const uint32_t valToPush) = 0;

    /// \brief This function pops the argument from the container, removing and returning it
    ///     Note: Check for an empty container
    /// return uint32_t the value popped from the container
    virtual uint32_t pop() = 0;

    /// \brief This function checks the next value which can be popped but does not remove it
    ///     Note: Check for empty container
    /// return Next value to be popped
    virtual uint32_t peek() = 0;

    /// \brief Insert a value at the offest
    ///     Note: If you have a container of size 10, assuming an array of arr[10] you could insert a value at arr[5]
    ///         This shouldn't overwrite the value, but instead insert between the existing 4 and 5 unless the container is full
    /// return void
    virtual void insertAt(const uint32_t offset, const uint32_t val) = 0;

    /// \brief Returns the current size of the container
    /// return Size of the container
    virtual uint32_t size() = 0;

protected:

private:
    uint32_t m_length;

};

#endif