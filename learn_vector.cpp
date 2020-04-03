#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

// 打印一维数组
template<typename T>
void Show(vector<T> &vec)
{
    for (auto i : vec) {
        cout << i << " ";
    }
    cout << endl;
}
// 打印二维数组
void ShowDup(vector<vector<int>> &vecDup)
{
    vector<vector<int>>::iterator it = vecDup.begin();
    while (it < vecDup.end()) {
        vector<int>::iterator tmpIt = it->begin();
        while (tmpIt < it->end()) {
            cout << *tmpIt << " ";
            ++tmpIt;
        }
        cout << endl;
        ++it;
    }
}

/************************************************************************************/
void TestBasicUsage()
{
    // 初始化
    vector<int> vecInt = {1, 2, 3};
    Show<int>(vecInt);
    vector<int> vecCpy(vecInt);
    Show<int>(vecCpy);
    vector<int> vecPosCpy(vecInt.begin() + 1, vecInt.end());
    Show<int>(vecPosCpy);
    vector<int> vecN(3, 1); // vector<int> vecN(3)
    Show<int>(vecN);
    vector<vector<int>> vecDup(3, vecInt); // 二维数组 
    // vector<vector<int>> vecDup(3, vector<int>(3, 0)); // 初始化3 x 3矩阵为0
    ShowDup(vecDup);

    // 访问
    cout << vecInt.front() << " = " << *vecInt.begin() << " = " << *(vecInt.rend() - 1) << endl;
    cout << vecInt.back() << " = " << *(vecInt.end() - 1) << " = " << *vecInt.rbegin() << endl;
    cout << vecInt[1] << " = " << vecInt.at(1) << endl;

    // 插入与删除
    vecInt.push_back(4);
    vecInt.pop_back();
    vecInt.insert(vecInt.end(), 4);
    vecInt.erase(vecInt.end() - 1);
    vecInt.insert(vecInt.end(), 3, 4);
    vecInt.erase(vecInt.end() - 3, vecInt.end());
    vecInt.insert(vecInt.end(), vecCpy.begin(), vecCpy.end());
    vecInt.erase(vecInt.end() - vecCpy.size(), vecInt.end());
    Show<int>(vecInt);

    // 赋值
    vecInt[1] = 4;
    vecInt.assign(1, 1);
    Show<int>(vecInt);
    vecInt.assign(vecCpy.begin(), vecCpy.end());
    Show<int>(vecInt);

    // 查找
    auto it = find(vecInt.begin(), vecInt.end(), 2);
    if (it != vecInt.end()) {
        cout << "FOUND:" << *it << endl;
    }

    // 其他
    vecInt.empty() ? cout << "YES" << endl : cout << "NO" << endl;
    vecInt.swap(vecN);
    Show<int>(vecInt);
    swap(vecInt, vecN);
    Show<int>(vecInt);
    swap(vecInt[1], vecInt[2]);
    Show<int>(vecInt);
    sort(vecInt.begin(), vecInt.end());
    Show<int>(vecInt);
}
/************************************************************************************/

/************************************************************************************/
// vector 排序
void ShowVecPair(vector<pair<int, int>> &vecPair)
{
    for (auto x : vecPair) {
        cout << "(" << x.first << "," << x.second << ") ";
    }
    cout << endl;
}

bool PairCmp(const pair<int, int> &a, const pair<int, int> &b)
{
    // std::tie 的头文件: #include <tuple>
    return tie(a.first, a.second) < tie(b.first, b.second);
}

void TestSort()
{
    // 内置方法：字符串排序
    vector<string> vecStr;
    vecStr.push_back("abcd");
    vecStr.insert(vecStr.begin(), "abbd");
    vecStr.insert(vecStr.begin() + 1, "accd");
    Show<string>(vecStr);
    sort(vecStr.begin(), vecStr.end());
    Show<string>(vecStr);

    // 自定义方法：元组排序
    vector<pair<int, int>> vecPair = {{4, 9}, {4, 3}};
    vecPair.push_back(pair<int, int>(10, 4));
    ShowVecPair(vecPair);
    // sort(vecPair.begin(), vecPair.end(), PairCmp);
    sort(vecPair.begin(), vecPair.end(),
        [](const pair<int, int> &a, const pair<int, int> &b) mutable -> bool
        { return tie(a.first, a.second) < tie(b.first, b.second); }
    );
    ShowVecPair(vecPair);
}
/************************************************************************************/

int main(int argc, char *argv[])
{
    // TestBasicUsage();
    TestSort();

    return 0;
}

