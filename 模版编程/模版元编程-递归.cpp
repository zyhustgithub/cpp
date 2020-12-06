/*
 * Copyright (C) 2020-2020 RTFSC All rights reserved.
 * Author:zengyong
 * Date:2020-12-06
 * Description:具体接口实现
 */

#include <iostream>

template<int N>
struct Factorial {
    enum {
        Value = N * Factorial<N - 1>::Value
    };
};

template<>
struct Factorial<1> {
    enum {
        Value = 1
    };
};

int main()
{
    std::cout << Factorial<5>::Value << std::endl;
    return 0;
}
