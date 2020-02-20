// 1006.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

int main()
{
    // input
    int number;
    cin >> number;
    // parse
    int num[3] = {0};
    for (int i = 2; i >= 0; i--)
    {
        num[i] = number % 10;
        number /= 10;
    }
    // process
    for (int i = 0; i < num[0]; i++)
    {
        cout << "B";
    }
    for (int i = 0; i < num[1]; i++)
    {
        cout << "S";
    }
    for (int i = 0; i < num[2]; i++)
    {
        cout << i + 1;
    }
}

