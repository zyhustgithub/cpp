#include <iostream>
#include <string>

using namespace std;

void TestStringUsage()
{
    // 初始化
    int num = 10;
    std::string str1(num, 'A');
    cout << str1 << endl;
    std::string str2 = "ABCD";
    cout << str2 << endl;

    // 子串
    cout << str1.substr(5) << endl;
    cout << str2.substr(1, 2) << endl;

    // 插入
    string str3 = "qwer";
    str3.insert(2, "A"); // 位置索引，插入字符串
    cout << str3 << endl;
    // 删除
    str3.erase(2, 1); // 位置索引，移除个数
    cout << str3 << endl;
}

int main(int argc, char *argv[])
{
    TestStringUsage();
    return 0;
}