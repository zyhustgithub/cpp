#!/bin/bash

BUILD_PATH=$(cd $(dirname $0) && pwd)
echo "****************************************************************"
echo "PATH:$BUILD_PATH"
g++ $BUILD_PATH/智能指针管理数组.cpp -std=gnu++14 -o $BUILD_PATH/test1
$BUILD_PATH/test1

g++ $BUILD_PATH/定制化智能指针.cpp -std=gnu++14 -o $BUILD_PATH/test2
$BUILD_PATH/test2
echo "****************************************************************"
rm $BUILD_PATH/test*
