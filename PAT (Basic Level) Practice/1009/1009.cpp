// 1009.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<string> sent;
    string tmp;
    while (cin >> tmp)
    {
        sent.push_back(tmp);
    }
    for (int i = sent.size() - 1; i >= 0; i--)
    {
        cout << sent[i];
        if (i != 0)
            cout << " ";
    }
}