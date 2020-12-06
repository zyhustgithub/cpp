/*
 * Copyright (C) 2020-2020 RTFSC All rights reserved.
 * Author:zengyong
 * Date:2020-11-26
 * Description:ASAN内存监测
 */

#include <iostream>
#include <cstdlib>

int HeapUseAfterFree()
{
    int* array = new int[64];
    delete [] array;
    return array[1];
}

int HeapBufferOverflow()
{
    int* array = new int[64];
    int res = array[64];
    delete [] array;
    return res;
}

int StackBufferOverflow()
{
    int array[64];
    int idx = 64;
    return array[idx];
}

std::string MemLeak()
{
    int* array = new int[64];
    return "ERR_MEMLEAK";
}

std::string DoubleFree()
{
    int* array = new int[64];
    delete [] array;
    delete [] array;
    return "ERR_DOUBLE_FREE";
}

#define TEST(target) std::cout << #target" retCode:" << target() << std::endl

int main(int argc, char* argv[])
{
    // TEST(HeapUseAfterFree);
    // TEST(HeapBufferOverflow);
    // TEST(StackBufferOverflow);
    // TEST(MemLeak);
    TEST(DoubleFree);
    return 0;
}
