/*
 * Copyright (C) 2020-2020 RTFSC All rights reserved.
 * Author:zengyong
 * Date:2020-12-05
 * Description:具体接口实现
 */

#include <iostream>
#include <stdexcept>
#include <memory>
#include <vector>
#include <deque>

/***********************************************************************/
// 模版
template<typename T>
struct NormalStack
{
    void push(const T& elem)
    {
        elems.push_back(elem);
    }

    T pop()
    {
        if (empty()) {
            throw std::out_of_range("NormalStack<>::pop: empty!");
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
    std::vector<T> elems;
};
/***********************************************************************/

/***********************************************************************/
// 模版设置默认参数
template<typename T, typename ContainerType = std::vector<T>>
struct DefaultStack
{
    void push(const T& elem)
    {
        elems.push_back(elem);
    }

    T pop()
    {
        if(empty()) throw std::out_of_range("DefaultStack<>::pop: empty!");

        auto elem = elems.back();
        elems.pop_back();
        return elem;
    }

    bool empty() const
    {
        return elems.empty();
    }

private:
    ContainerType elems;
};
/***********************************************************************/

/***********************************************************************/
// 模版设置模版参数
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

int main()
{
    /***********************************************************************/
    NormalStack<int> intNormalStack;
    intNormalStack.push(1);
    intNormalStack.push(2);
    std::cout << intNormalStack.pop() << std::endl;

    NormalStack<char> charNormalStack;
    charNormalStack.push('A');
    charNormalStack.push('B');
    std::cout << charNormalStack.pop() << std::endl;
    /***********************************************************************/

    /***********************************************************************/
    DefaultStack<int, std::deque<int>> intDefaultStack;
    intDefaultStack.push(1);
    intDefaultStack.push(2);
    std::cout << intDefaultStack.pop() << std::endl;

    DefaultStack<char> charDefaultStack;
    charDefaultStack.push('A');
    charDefaultStack.push('B');
    std::cout << charDefaultStack.pop() << std::endl;
    /***********************************************************************/

    /***********************************************************************/
    TemplateArgStack<int, std::deque> intTemplateArgStack;
    intTemplateArgStack.push(1);
    intTemplateArgStack.push(2);
    std::cout << intTemplateArgStack.pop() << std::endl;

    TemplateArgStack<char> charTemplateArgStack;
    charTemplateArgStack.push('A');
    charTemplateArgStack.push('B');
    std::cout << charTemplateArgStack.pop() << std::endl;
    /***********************************************************************/

    return 0;
}
