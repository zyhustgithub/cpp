/*
 * Copyright (C) 2020-2020 RTFSC All rights reserved.
 * Author:zengyong
 * Date:2020-12-06
 * Description:具体接口实现
 */

#include <iostream>

template<typename T>
struct PointerOf
{
    using Result = T*;
};

#define __pointer(...) typename PointerOf<__VA_ARGS__>::Result

template<typename T>
struct Pointer2Of
{
    using Result = __pointer(__pointer(T));
};

int main()
{
    int* p;
    Pointer2Of<int>::Result pp = &p;
    std::cout << std::hex << pp << std::endl;
    return 0;
}
