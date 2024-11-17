#include "pch.h"

#include "../ContainerLibrary/FILO.h"
#include "../ContainerLibrary/FIFO.h"


class TestHelper
{
public:
    TestHelper(IIntContainer& container, uint32_t size) :
        m_container(container),
        m_size(size)
    {
    }

    void nominalTest()
    {
        // Peek container
        std::cout << "Testing Peek with empty container" << std::endl;
        EXPECT_EQ(_UI32_MAX, m_container.peek());

        // Pop container
        std::cout << "Testing Pop with empty container" << std::endl;
        EXPECT_EQ(_UI32_MAX, m_container.pop());

        // Size with empty container
        std::cout << "Testing size with empty container" << std::endl;
        EXPECT_EQ(0, m_container.size());

        // Push 3 ints into container
        std::cout << "Testing Push with empty container" << std::endl;
        pushHelper(3);

        std::cout << "Testing Size of container after 3 pushes" << std::endl;
        EXPECT_EQ(3, m_container.size());

        // Pop container
        std::cout << "Testing Pop with 3 items in container" << std::endl;
        m_container.pop();

        std::cout << "Testing Size of container after pop" << std::endl;
        EXPECT_EQ(2, m_container.size());

        std::cout << "Boundary Testing container" << std::endl;
        limitTest();
    }

    void maxMinTest()
    {
        // Pop container
        std::cout << "Testing Pop with empty container" << std::endl;
        EXPECT_EQ(_UI32_MAX, m_container.pop());

        // Size with empty container
        std::cout << "Testing size with empty container" << std::endl;
        EXPECT_EQ(0, m_container.size());

        std::cout << "Pushing 10 items into 10 length container" << std::endl;
        for (uint8_t i = 0; i < m_size; ++i)
        {
            m_container.push(i);
        }
        EXPECT_EQ(m_size, m_container.size());

        std::cout << "Pushing 1 more item into 10 length container" << std::endl;
        m_container.push(11);

        std::cout << "Testing Size of container after 1 more push" << std::endl;
        EXPECT_EQ(m_size, m_container.size());

        std::cout << "Testing push did not overwrite" << std::endl;
        EXPECT_EQ(m_size - 1, m_container.peek());

        std::cout << "Popping all off the container" << std::endl;
        for (uint8_t i = 0; i < m_size; ++i)
        {
            m_container.pop();
        }
        EXPECT_EQ(0, m_container.size());

        std::cout << "Popping one more off the container" << std::endl;
        m_container.pop();
        EXPECT_EQ(0, m_container.size());
    }

    void pushHelper(uint32_t length)
    {
        for (uint8_t i = 0; i < length; ++i)
        {
            m_container.push(i);
        }
    }

    void popHelper(uint32_t length)
    {
        for (uint8_t i = 0; i < length; ++i)
        {
            m_container.pop();
        }
    }

    void limitTest()
    {
        popLimitTest();
        pushLimitTest();
        popLimitTest();
    }

    void pushLimitTest()
    {
        // Push more than the size of the container
        for (uint32_t i = 0; i < m_size + m_extraTries; ++i)
        {
            m_container.push(i);
        }
        std::cout << "Testing Size of container after > max pushes" << std::endl;
        EXPECT_EQ(m_size, m_container.size());
    }

    void popLimitTest()
    {
        // Pop more than the size of the container
        for (uint32_t i = 0; i < m_size + m_extraTries; ++i)
        {
            m_container.pop();
        }
        std::cout << "Testing Size of container after > max pops" << std::endl;
        EXPECT_EQ(0, m_container.size());
    }

private:
    static const uint32_t m_extraTries = 10;
    IIntContainer& m_container;
    uint32_t m_size;
};


/// \brief Test nominal container behavior
TEST(FILOTests, TestNominal)
{
    const uint32_t filoSize = 10;
    // Create a container of small size
    FILO container(filoSize);

    TestHelper helper(container, filoSize);

    std::cout << "Running FILO nominal test" << std::endl;
    helper.nominalTest();
}

/// \brief Test nominal container behavior
TEST(FILOTests, TestPop)
{
    const uint32_t filoSize = 10;
    // Create a container of small size
    FILO container(filoSize);

    TestHelper helper(container, filoSize);

    helper.pushHelper(5);

    EXPECT_EQ(4, container.pop());
    EXPECT_EQ(3, container.pop());
    EXPECT_EQ(2, container.pop());

    helper.popHelper(10);

    helper.pushHelper(20);
    EXPECT_EQ(9, container.pop());
    EXPECT_EQ(8, container.pop());
    EXPECT_EQ(7, container.pop());    
}

/// \brief Test nominal container behavior
TEST(FILOTests, TestPeek)
{
    const uint32_t filoSize = 10;
    // Create a container of small size
    FILO container(filoSize);

    TestHelper helper(container, filoSize);

    EXPECT_EQ(_UI32_MAX, container.peek());

    helper.pushHelper(5);
    EXPECT_EQ(4, container.peek());
    container.pop();
    EXPECT_EQ(3, container.peek());
    container.pop();
    EXPECT_EQ(2, container.peek());
}

/// \brief Test filling up container and emptying
TEST(FILOTests, TestMaxMinSize)
{
    const uint32_t filoSize = 10;
    // Create a container of small size
    FILO container(filoSize);

    std::cout << "Running FILO MaxMin test" << std::endl;
    TestHelper helper(container, filoSize);
    helper.maxMinTest();
}
