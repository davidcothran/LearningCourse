// Application.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 

/*
Notes:

All applications must have a main.
Libraries are utilized by applications.

.lib libraries are static libraries which are compiled at the same time as the application they are used in.
.dll libraries are dynamic link libraries and expose APIs which can be called by an application. They don't have to be compiled together.

*/

#include <iostream>
#include "../ContainerLibrary/IIntContainer.h"
#include "../ContainerLibrary/FILO.h"

class Example
{
public:
    Example(IIntContainer& container, const uint32_t sizeOfContainer) :
        m_container(container),
        m_sizeOfContainer(sizeOfContainer)
    {
        push();

        pop();
    }

    void push()
    {
        const uint32_t extraPushes = 100;
        // Pushes values into the container at a length more than the container
        for (uint32_t i = 0; i < m_sizeOfContainer + extraPushes; ++i)
        {
            m_container.push(i);
        }
    }

    void pop()
    {
        // Calls pop greater than the size of the container
        // Note the magic number, what is 100? Its kinda obvious but sometimes its not, so a const would be better like in the push function :)
        for (uint32_t i = 0; i < m_sizeOfContainer + 100; ++i)
        {
            // Prints the value, expects -1 for invalid pops (0xFFFF_FFFF) but we arent really checking it here. Use the unit tests for that.
            std::cout << m_container.pop() << std::endl;
        }
    }

    IIntContainer& m_container;
    uint32_t m_sizeOfContainer;
};

int main()
{
    // Use consts, avoid "Magic numbers" which are numbers in the middle of code sections
    const uint32_t containerSize = 5;
    std::cout << "Hello World!\n";

    // Create a container
    FILO filo(containerSize);
    FILO filoStack = FILO(containerSize); // The object will live on the stack (similar to above)
    FILO* filoHeap = new FILO(containerSize); // The object will live on the heap. The filoHeap is a pointer to the object on the heap
    FILO& filoRef = *filoHeap; // The filoRef is a reference to the object filoHeap. You dont have to use -> to access member functions.
    // IIntContainer cont; // Illegal, wont compile because it is pure virtual

    // Pass container into Example class. 
    Example ex(filo, containerSize);


    // Clean up our heap
    delete filoHeap;

    std::cout << "Success?" << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
