#include <iostream>
#include <vector>

using namespace std;

void Show(vector<int> &vecInt)
{
    for (auto i : vecInt) {
        cout << i << " ";
    }
    cout << endl;
}

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

int main(int argc, char *argv[])
{
    // 初始化
    vector<int> vecInt = {1, 2, 3};
    Show(vecInt);
    vector<int> vecCpy(vecInt);
    Show(vecCpy);
    vector<int> vecPosCpy(vecInt.begin() + 1, vecInt.end());
    Show(vecPosCpy);
    vector<int> vecN(3, 1); // vector<int> vecN(3)
    Show(vecN);
    vector<vector<int>> vecDup(3, vecInt); // 二维数组  
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
    Show(vecInt);

    // 赋值
    vecInt[1] = 4;
    vecInt.assign(1, 1);
    Show(vecInt);
    vecInt.assign(vecCpy.begin(), vecCpy.end());
    Show(vecInt);

    // 查找
    auto it = find(vecInt.begin(), vecInt.end(), 2);
    if (it != vecInt.end()) {
        cout << "FOUND:" << *it << endl;
    }

    // 其他
    vecInt.empty() ? cout << "YES" << endl : cout << "NO" << endl;
    vecInt.swap(vecN);
    Show(vecInt);
    swap(vecInt, vecN);
    Show(vecInt);
    swap(vecInt[1], vecInt[2]);
    Show(vecInt);
    sort(vecInt.begin(), vecInt.end());
    Show(vecInt);

    return 0;
}

