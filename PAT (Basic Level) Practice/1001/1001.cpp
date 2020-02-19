// 1001.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

int main()
{
    //Input
    int n;
    cin >> n;
    //Process
    int count = 0;
    while (n!=1)
    {
        if (n % 2 == 0)  // if is not odd
        {
            n /= 2;
        }
        else
        {
            n = (3 * n + 1) / 2;
        }
        count++;
    }
    cout << count;
}

