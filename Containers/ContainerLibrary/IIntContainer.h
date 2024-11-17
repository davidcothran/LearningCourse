#ifndef ICONTAINER_H
#define ICONTAINER_H

#include <stdint.h>

/* 
Notes:
    /// \class or \brief is a doxygen style comment which allows a static analysis tool to parse solutions and generate documentation

    Instead of making this a templated class, I opted for uint32_t types

    Using uint32_t is superior to data types like int for portability

    Setting a function to "= 0" makes a pure virtual function and makes the class pure virtual
        This class cannot be instantiated

    General note: Passing ints by reference isnt beneficial but passing classes or complex objects is very beneficial

    This is a good general principles of designing Object Oriented Programming projects
        https://en.wikipedia.org/wiki/SOLID
*/

/// \class IIntContainer
/// \brief This is an interface (pure virtual) class which defines the methods for each derived class. It is
///     intended to be used for any container (such as a FIFO/FILO/vector/deque)
class IIntContainer
{
public:
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

    /// \brief Clears the container
    /// return void
    virtual void clear() = 0;

protected:
};


#endif // !ICONTAINER_H




