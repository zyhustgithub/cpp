#!/bin/bash

echo "****************************************************************"
BUILD_PATH=$(cd $(dirname $0) && pwd)
echo ">>>BUILD_PATH:$BUILD_PATH"

CLS=false
ACT=""
RUN=false
# 解析参数
while [[ $# -ge 1 ]]; do
    case $1 in
        clean)
            CLS=true
            shift
            ;;
        -t|--target)
            if [ $# -lt 2 ]; then
                echo ">>>Error:Please Assign a Target for Option[$1]."
                exit 1
            fi
            ACT=$2
            shift 2
            ;;
        run)
            RUN=true
            shift
            ;;
        -h|--help)
            echo "[Usage]"
            echo "    sh build.sh -h[--help]"
            echo "    sh build.sh clean"
            echo "    sh build.sh compile [run]"
            exit 0
            ;;
        *)
            echo ">>>Error:Unknown Option[$1]."
            exit 1
    esac
done

echo "[OPTIONS]"
echo "    CLS:$CLS"
echo "    ACT:$ACT"
echo "    RUN:$RUN"

# 清空
if [[ $CLS == true ]]; then
    echo ">>>Clean dir..."
    [ -f $BUILD_PATH/test ] && rm $BUILD_PATH/test
    find $BUILD_PATH -type f -name "*.so" | xargs -n1 -I {} rm {}
    exit 0
fi

# 编译
if [[ "$ACT" == "A" ]]; then
    g++ $BUILD_PATH/DemoA.cpp -std=gnu++14 -shared -fPIC -o $BUILD_PATH/libdemoA.so
    g++ $BUILD_PATH/main.cpp -std=gnu++14 -L$BUILD_PATH -ldemoA -o $BUILD_PATH/test
elif [[ "$ACT" == "B" ]]; then
    g++ $BUILD_PATH/DemoB.cpp -std=gnu++14 -shared -fPIC -o $BUILD_PATH/libdemoB.so
fi

# 执行
if [[ $RUN == true ]]; then
    $BUILD_PATH/test
fi
echo "****************************************************************"
