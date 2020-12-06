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
    using Type = T*;
};

int main()
{
    PointerOf<const char>::Type s = "Hello world!";
    std::cout << s << std::endl;
    return 0;
}
