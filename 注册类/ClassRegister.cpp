#include <iostream>
#include <map>
#include <string>

typedef void *(*instance)();
std::map<std::string, instance>& GetClass()
{
    static std::map<std::string, instance> classMap;
    return classMap;
}

class ClassFactory {
public:
    static void *GetInstance(const std::string &className)
    {
        if (GetClass().find(className) == GetClass().end()) {
            std::cout << "[ClassFactory]->Haven't Register Class: " << className << std::endl;
            return nullptr;
        }
        return GetClass()[className]();
    }
    static void RegisterClass(const std::string &className, instance ins) {
        if (GetClass().find(className) != GetClass().end()) {
            std::cout << "[ClassFactory]->Have Registered Class: " << className << std::endl;
            return;
        }
        GetClass().insert(std::make_pair(className, ins));
        std::cout << "[ClassFactory]->Register Class: " << className << std::endl;
    }
};

/*******************************************************************************/
/* 静态注册类 */
// class Register {
// public:
//     Register(const std::string className, instance ins)
//     {
//         ClassFactory::RegisterClass(className, ins);
//     }
// };

// #define REGISTER(className) \
//     class Register##className {\
//     public:\
//         static void *instance()\
//         {\
//             return new className;\
//         }\
//     private:\
//         static const Register interface;\
//     };\
//     const Register Register##className::interface(#className, Register##className::instance);
/*******************************************************************************/

/*******************************************************************************/
/* 运行时注册类 */
template<typename T>
void *Instance()
{
    return new T;
}

class Register {
public:
    Register(const std::string className, instance ins)
    {
        ClassFactory::RegisterClass(className, ins);
    }
};

#define REGISTER(className) \
    static const Register Register##className(#className, Instance<className>)

// #define REGISTER(className) \
//     ClassFactory::RegisterClass(#className, Instance<className>)
/*******************************************************************************/

#define INSTANCE(className) \
    ClassFactory::GetInstance(className)

class TestA {
public:
    TestA() {}
    void CallA()
    {
        std::cout << "[TestA]->TestA Class" << std::endl;
    }
};

class TestB {
public:
    TestB() {}
    void CallB()
    {
        std::cout << "[TestB]->TestB Class" << std::endl;
    }
};

// REGISTER(TestA);
// REGISTER(TestB);

int main(int argc, char *argv[])
{
    std::cout << GetClass().size() << std::endl;
    REGISTER(TestA);
    REGISTER(TestB);
    TestA *testClassA = (TestA *)INSTANCE("TestA");
    testClassA->CallA();
    TestB *testClassB = (TestB *)INSTANCE("TestB");
    testClassB->CallB();
    std::cout << GetClass().size() << std::endl;
    return 0;
}