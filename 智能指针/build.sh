#!/bin/bash

BUILD_PATH=$(cd $(dirname $0) && pwd)
echo "****************************************************************"
echo "PATH:$BUILD_PATH"
g++ $BUILD_PATH/智能指针管理数组.cpp -std=gnu++14 -o $BUILD_PATH/test
$BUILD_PATH/test
echo "****************************************************************"
rm $BUILD_PATH/test
