#include <iostream>
#include <string>
#include <map>

using namespace std;

/************************************************************************************/
// map 按照 key 排序

typedef std::function<void()> CALLBACK;

void Show(std::string str)
{
    std::cout << str << std::endl;
}

struct Key
{
    std::string strA;
    std::string strB;

    Key(std::string s1, std::string s2):strA(s1), strB(s2) {}

    // 方法一
    // bool operator < (const Key & cmp) const
    // {
    //     if ((strA == cmp.strA) && (strB == cmp.strB)) {
    //         return false;
    //     }
    //     return true;
    // }
};

// 方法二、需传入比较方法对象
struct KeyCmp
{
    bool operator () (const Key &a, const Key &b) const
    {
        if (a.strA == b.strA && a.strB == b.strB) {
            return false;
        } else {
            return true;
        }
    }
};

// 方法三、无需传入比较方法对象
// template <>
// struct std::less<Key> : public binary_function<Key, Key, bool> {
// public:
//     bool operator () (const Key &a, const Key &b) const
//     {
//         if (a.strA == b.strA && a.strB == b.strB) {
//             return false;
//         } else {
//             return true;
//         }
//     }
// };

// 测试 map 自定义 key 查找
void TestMapKeyFind()
{
    // std::map中key的比较是双向的，即 (cmp(a, b) | cmp(b, a)) == false 时才返回停止查找
    std::map<Key, CALLBACK, KeyCmp> procTable = {
        {Key("a", "a"), [&] () { Show("b"); }},
        {Key("c", "c"), [&] () { Show("c"); }}
    };
    Key f("c", "c");
    auto itera = procTable.find(f);
    if (itera == procTable.end()) {
        std::cout << "Not find" << std::endl;
    } else {
        itera->second();
    }

    // std::pair 作为 std::map 的 key 使用
    // typedef std::pair<std::string, std::string> Pos;
    // std::map<std::pair<std::string, std::string>, CALLBACK> table = {
    //     {{"a", "b"}, [&] () { Show("a"); }}
    // };
    // std::pair<std::string, std::string> p("a", "b");
    // auto iterb = table.find(p);
    // if (iterb == table.end()) {
    //     std::cout << "not find" << std::endl;
    // } else {
    //     iterb->second();
    // }
}
/************************************************************************************/

/************************************************************************************/
// 反向遍历
void TestReverseTraverse()
{
    map<int, string> T = {
        {1, "A"},
        {2, "B"}
    };
    
    map<int, string>::reverse_iterator it = T.rbegin();
    for (; it != T.rend(); ++it) {
        cout << it->first << ":" << it->second << endl;
    }
}
/************************************************************************************/

int main()
{
    TestMapKeyFind();
    TestReverseTraverse();
    return 0;
}