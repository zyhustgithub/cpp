/*
 * Copyright (C) 2020-2020 RTFSC All rights reserved.
 * Author:zengyong
 * Date:2020-11-25
 * Description:具体接口实现
 */

#ifndef DEMOA_H
#define DEMOA_H

#include <iostream>
#include "IDemo.h"

class DemoA : public IDemo {
public:
    void Process();
};

#endif
