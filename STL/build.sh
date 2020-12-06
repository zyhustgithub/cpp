#!/bin/bash

BUILD_PATH=$(cd $(dirname $0) && pwd)
echo "****************************************************************"
echo "BUILD_PATH:$BUILD_PATH"
# g++ $BUILD_PATH/自定义类型内存分配和范围for.cpp -std=gnu++17 -o $BUILD_PATH/test1
# $BUILD_PATH/test1

g++ $BUILD_PATH/自定义allocator.cpp -std=gnu++17 -o $BUILD_PATH/test2
$BUILD_PATH/test2
echo "****************************************************************"
rm $BUILD_PATH/test*
