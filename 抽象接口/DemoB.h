/*
 * Copyright (C) 2017-2018 RTFSC All rights reserved.
 * Author:zengyong
 * Date:2020-11-25
 * Description:具体接口实现
 */

#ifndef DEMOB_H
#define DEMOB_H

#include <iostream>
#include "IDemo.h"

class DemoB : public IDemo {
public:
    void Process();
};

#endif
