#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
    map<int, string> T = {
        {1, "A"},
        {2, "B"}
    };
    // 反向遍历
    map<int, string>::reverse_iterator it = T.rbegin();
    for (; it != T.rend(); ++it) {
        cout << it->first << ":" << it->second << endl;
    }
    return 0;
}