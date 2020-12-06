/*
 * Copyright (C) 2020-2020 RTFSC All rights reserved.
 * Author:zengyong
 * Date:2020-11-25
 * Description:抽象接口实现代码解耦测试
 */

#include "main.h"
#include "DemoA.h"

void Test::Func()
{
    m_demoPtr = std::make_unique<DemoA>();
    if (m_demoPtr == nullptr) {
        std::cout << "Error:m_demoPtr is nullptr" << std::endl;
    }
    m_demoPtr->Process();
}

int main()
{
    Test::GetInstance().Func();
    return 0;
}
