#!/bin/bash

BUILD_PATH=$(cd $(dirname $0) && pwd)
echo "****************************************************************"
echo "BUILD_PATH:$BUILD_PATH"
# g++ $BUILD_PATH/模版参数.cpp -std=gnu++17 -o $BUILD_PATH/test1
# $BUILD_PATH/test1

# g++ $BUILD_PATH/模版特化.cpp -std=gnu++17 -o $BUILD_PATH/test2
# $BUILD_PATH/test2

# g++ $BUILD_PATH/模版的非类型参数.cpp -std=gnu++17 -o $BUILD_PATH/test3
# $BUILD_PATH/test3

# g++ $BUILD_PATH/模版编译期数据计算.cpp -std=gnu++17 -o $BUILD_PATH/test4
# $BUILD_PATH/test4

# g++ $BUILD_PATH/模版编译期类型计算.cpp -std=gnu++17 -o $BUILD_PATH/test5
# $BUILD_PATH/test5

# g++ $BUILD_PATH/模版元编程-递归.cpp -std=gnu++17 -o $BUILD_PATH/test6
# $BUILD_PATH/test6

g++ $BUILD_PATH/模版元编程-元函数.cpp -std=gnu++17 -o $BUILD_PATH/test7
$BUILD_PATH/test7
echo "****************************************************************"
rm $BUILD_PATH/test*
