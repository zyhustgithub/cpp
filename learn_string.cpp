#include <iostream>
#include <string>

using namespace std;

void TestStringUsage()
{
    // 初始化
    std::string str1(10, 'A');
    cout << str1 << endl;
    std::string str2 = "ABCD";
    cout << str2 << endl;

    // 子串
    cout << str1.substr(5) << endl;
    cout << str2.substr(1, 2) << endl;
}

int main(int argc, char *argv[])
{
    TestStringUsage();
    return 0;
}