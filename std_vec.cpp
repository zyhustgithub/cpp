#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;

struct A {
    uint8_t num;
    string str;
    vector<string> vecStr;
};

struct B {
    vector<A> VecA;
};

void funcB(vector<A> &va)
{
    A a;
    uint8_t n = 5;
    char *s = "haha";
    while (n > 0) {
        memset(&a, 0, sizeof(a));
        a.num = n;
        a.str = s;
        a.vecStr.push_back("hehe");
        a.vecStr.push_back("enen");
        --n;
        va.push_back(a);
    }
}

void funcA(B &b)
{
    funcB(b.VecA);
}

int main(void)
{
    B b;
    funcA(b);
    vector<A> a = b.VecA;
    vector<A>::iterator it = a.begin();
    while (it < a.end()) {
        cout << +it->num << "|" << it->str << "|";
        const vector<string> s = it->vecStr;
        // for(auto its: s) {
        //     cout << its;
        // }
        /* const_iterator */
        vector<string>::const_iterator its = s.begin();
        for (its; its < s.end(); ++its) {
            cout << *its;
        }
        cout << endl;
        ++it;
    }

    /* 数字字符串转数字 */
    string strNum = "123";
    // unsigned char i = stoi(strNum, 0, 10);
    unsigned char i = strtol(strNum.c_str(), nullptr, 10);
    cout << +i << endl;

    return 0;
}