#!/bin/bash
set -eou

echo "****************************************************************"
BUILD_PATH=$(cd $(dirname $0) && pwd)
echo ">>>BUILD_PATH:$BUILD_PATH"

# -fsanitize-recover=address \
g++ -fno-stack-protector \
    -fsanitize=address \
    -fno-omit-frame-pointer \
    -O1 -g1 ASAN内存监测.cpp -o asan

SUPP_FILE="detect_asan.log"
# ASAN_OPTIONS="halt_on_error=0:use_sigaltstack=0:detect_leaks=1:malloc_context_size=15:log_path=/Users/zengyongFamily/Desktop/日常编码/cpp/ASAN内存监测/asan.log:suppressions=$SUPP_FILE"
# export LD_PRELOAD="libasan.so.2:libprelib.so"

# run[Mac系统不支持detect_leaks=1]
ASAN_OPTIONS=halt_on_error=0:use_sigaltstack=0:log_path=./asan.log ./asan

# clean
find $BUILD_PATH -type f -name "asan*" | xargs -n1 -I {} rm {}
find $BUILD_PATH -type d -name "asan.*" | xargs -n1 -I {} rm -rf {}

echo "****************************************************************"
