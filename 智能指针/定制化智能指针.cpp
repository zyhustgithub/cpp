#include <iostream>
#include <memory>

using namespace std;

template<typename T>
class AutoFreeMemory {
public:
    AutoFreeMemory() = default;
    ~AutoFreeMemory() = default;
    AutoFreeMemory(const AutoFreeMemory& obj) = delete;
    AutoFreeMemory& operator=(const AutoFreeMemory& obj) = delete;

    void operator()(T* p)
    {
        delete p;
    }
};

class Test {
public:
    Test() { cout << "Test()" << endl; }
    ~Test() { cout << "~Test()" << endl; }
};

using AutoTestPtr = std::unique_ptr<Test, AutoFreeMemory<Test>>;

int main(int argc, char* argv[])
{
    Test* p = new Test();
    AutoTestPtr up(p);
    return 0;
}
