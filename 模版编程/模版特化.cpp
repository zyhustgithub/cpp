/*
 * Copyright (C) 2020-2020 RTFSC All rights reserved.
 * Author:zengyong
 * Date:2020-12-05
 * Description:具体接口实现
 */

#include <iostream>
#include <memory>
#include <vector>
#include <deque>

/***********************************************************************/
// 主模版
template<typename T, 
    template<typename E, typename Allocator = std::allocator<E>>
    class ContainerType = std::vector>
struct TemplateArgStack
{
    void push(const T& elem)
    {
        elems.push_back(elem);
    }

    T pop()
    {
        if (empty()) {
            throw std::out_of_range("TemplateArgStack<>::pop: empty!");
        }

        auto elem = elems.back();
        elems.pop_back();
        return elem;
    }

    bool empty() const
    {
        return elems.empty();
    }

private:
    ContainerType<T> elems;
};
/***********************************************************************/

/***********************************************************************/
// 自定义数组类型
template<typename T, typename Allocator = std::allocator<T>>
struct MyArray
{
    MyArray() : m_elems(nullptr), m_size(nullptr), m_end(nullptr) {}
    ~MyArray()
    {
        std::cout << "~MyArray(): capacity = " << m_end - m_elems << std::endl;
        if (m_elems != nullptr) {
            while (m_elems != m_size) {
                m_alloc.destroy(--m_size);
            }
            m_alloc.deallocate(m_elems, capacity());
        }

        m_elems = nullptr;
    }

    void append(const T& val);
    T pop();

    size_t size() const
    {
        return m_size - m_elems;
    }

    size_t capacity() const
    {
        return m_end - m_elems;
    }

private:
    void reallocate()
    {
        size_t oldCapacity = capacity();
        size_t newCapacity = (oldCapacity == 0) ? 1 : (oldCapacity * 2);
        T* newElems = m_alloc.allocate(newCapacity);
        if (m_elems != nullptr) {
            std::cout << "reallocate(): capacity = " << m_end - m_elems << std::endl;
            std::uninitialized_copy(m_elems, m_size, newElems);
            while (m_elems != m_size) {
                m_alloc.destroy(--m_size);
            }
            m_alloc.deallocate(m_elems, oldCapacity);
        }
        m_elems = newElems;
        m_size = m_elems + oldCapacity;
        m_end = m_elems + newCapacity;
    }

private:
    static Allocator m_alloc;
    T* m_elems;
    T* m_size;
    T* m_end;
};

template <typename T, typename Allocator>
Allocator MyArray<T, Allocator>::m_alloc;

template<typename T, typename Allocator>
void MyArray<T, Allocator>::append(const T& val)
{
    if (size() == capacity()) {
        reallocate();
    }
    m_alloc.construct(m_size++, val);
}

template<typename T, typename Allocator>
T MyArray<T, Allocator>::pop()
{
    if (m_size == m_elems) {
        throw std::out_of_range("MyArray<>::pop: empty!");
    }
    m_alloc.destroy(--m_size);
    return *m_size;
}
/***********************************************************************/

/***********************************************************************/
// 偏特化
template<typename T>
struct TemplateArgStack<T, MyArray>
{
    void push(const T& elem)
    {
        elems.append(elem);
    }

    T pop()
    {
        auto elem = elems.pop();
        return elem;
    }

private:
    MyArray<T> elems;
};
/***********************************************************************/

/***********************************************************************/
// 全特化
template<>
struct TemplateArgStack<std::string, MyArray>
{
    void push(const std::string& elem)
    {
        std::cout << "TemplateArgStack<std::string, MyArray>:push()" << std::endl;
        elems.append(elem);
    }

    std::string pop()
    {
        auto elem = elems.pop();
        return elem;
    }

private:
    MyArray<std::string> elems;
};
/***********************************************************************/

int main()
{
    /***********************************************************************/
    TemplateArgStack<int, MyArray> intMyArrayTemplateArgStack;
    intMyArrayTemplateArgStack.push(1);
    intMyArrayTemplateArgStack.push(2);
    std::cout << intMyArrayTemplateArgStack.pop() << std::endl;

    TemplateArgStack<std::string, MyArray> strMyArrayTemplateArgStack;
    strMyArrayTemplateArgStack.push("mr");
    strMyArrayTemplateArgStack.push("zy");
    std::cout << strMyArrayTemplateArgStack.pop() << std::endl;

    TemplateArgStack<int, std::deque> intTemplateArgStack;
    intTemplateArgStack.push(3);
    intTemplateArgStack.push(4);
    std::cout << intTemplateArgStack.pop() << std::endl;

    TemplateArgStack<char> charTemplateArgStack;
    charTemplateArgStack.push('A');
    charTemplateArgStack.push('B');
    std::cout << charTemplateArgStack.pop() << std::endl;
    /***********************************************************************/

    return 0;
}