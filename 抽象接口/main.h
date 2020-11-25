/*
 * Copyright (C) 2017-2018 RTFSC All rights reserved.
 * Author:zengyong
 * Date:2020-11-25
 * Description:抽象接口实现代码解耦测试
 */

#ifndef MAIN_H
#define MAIN_H

#include "IDemo.h"

class Test {
public:
    static Test& GetInstance()
    {
        static Test instance;
        return instance;
    }

    Test(const Test& obj) = delete;
    Test& operator=(const Test& obj) = delete;
    void Func();

private:
    Test() = default;
    ~Test() = default;

private:
    IDemoPtr m_demoPtr = nullptr;
};

#endif
