/*
 * Copyright (C) 2020-2020 RTFSC All rights reserved.
 * Author:zengyong
 * Date:2020-12-06
 * Description:具体接口实现
 */

#include <iostream>

/***********************************************************************/
template<typename T, int MAX_SIZE>
struct Stack{
    void push(const T& val)
    {
        if (size == MAX_SIZE) {
            throw std::out_of_range("Stack<>::push: full!");
        }
        elems[size++] = val;
    }

    T pop()
    {
        if (size == 0) {
            throw std::out_of_range("Stack<>::pop: empty!");
        }
        return elems[--size];
    }

private:
    T elems[MAX_SIZE];
    int size = 0;
};
/***********************************************************************/

/***********************************************************************/
template<const char* MyName>
struct Token
{
    std::string name{MyName};
};
/***********************************************************************/

const char str[] = "Hello";   // 正确
// const char* str = "Hello"; // 错误 

int main()
{
    constexpr int stackSize = 8;
    Stack<int, stackSize> st;
    st.push(1);
    st.push(2);
    int top = st.pop();
    std::cout << top << std::endl;

    Token<str> token;
    std::cout << token.name << std::endl;
    return 0;
}