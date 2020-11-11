#include <iostream>
#include <memory>

using namespace std;

class Demo {
public:
    Demo() { cout << "Demo()" << endl; }
    Demo(int val) : data(val) { cout << "Demo()" << endl; }
    ~Demo() { cout << "~Demo()" << endl; }

private:
    int data{0};
};

int main(int argc, char *argv[])
{
    constexpr uint32_t ARRAY_SIZE = 4;
    auto uPtr = make_unique<Demo[]>(ARRAY_SIZE); // 智能指针管理数组
    return 0;
}
