/*
 * Copyright (C) 2020-2020 RTFSC All rights reserved.
 * Author:zengyong
 * Date:2020-11-25
 * Description:抽象接口实现代码解耦
 */

#ifndef IDEMO_H
#define IDEMO_H

#include <memory>

class IDemo {
public:
    virtual void Process() = 0;
    virtual ~IDemo() = default;
};

using IDemoPtr = std::unique_ptr<IDemo>;

#endif
