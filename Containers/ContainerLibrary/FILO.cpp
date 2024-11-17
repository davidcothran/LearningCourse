/* 
Notes:

Implement a basic FILO using the IContainer


*/

#include "FILO.h"

FILO::FILO(const uint32_t length) :
    m_length(length) // This is called an initializer list
{
    // Create heap memory large enough to store the desired FILO
    m_arr = new uint32_t[length];
}

FILO::~FILO()
{
    delete[] m_arr;
}

void FILO::push(const uint32_t valToPush)
{
    // TODO
}

uint32_t FILO::pop()
{
    // TODO
    return 0;
}

uint32_t FILO::peek()
{
    // TODO
    return 0;
}

void FILO::insertAt(const uint32_t offset, const uint32_t val)
{
    // TODO
}

uint32_t FILO::size()
{
    // TODO
    return 0;
}

void FILO::clear()
{
    // TODO
}