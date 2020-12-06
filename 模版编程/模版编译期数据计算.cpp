/*
 * Copyright (C) 2020-2020 RTFSC All rights reserved.
 * Author:zengyong
 * Date:2020-12-06
 * Description:具体接口实现
 */

#include <iostream>

template<int X, int Y>
struct Caculate {
    enum {
        SUM = X + Y,
        DEC = X - Y,
        MUL = X * Y,
        DIV = X / Y
    };
};

template<int Value>
struct Print {
    operator char()
    {
        return 0xFF + Value; // 会触发overflow告警
    }
};

#define _JOIN(symbol1, symbol2) symbol1##symbol2
#define UNIQUE_NAME(prefix) _JOIN(prefix, __LINE__)
#define __print(...) char UNIQUE_NAME(print_value_) = Print<__VA_ARGS__>()
__print(Caculate<3, 4>::MUL);

int main()
{
    std::cout << Caculate<3, 4>::MUL << std::endl;
    return 0;
}
