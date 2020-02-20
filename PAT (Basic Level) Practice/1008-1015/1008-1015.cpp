// 1008-1015.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

int main()
{
    // input
    int N, M;
    cin >> N >> M;
    auto num = new int[N];
    for (int i = 0; i < N; i++)
        cin >> num[i];
    // process
    while (M!=0)
    {
        int tmp = num[N - 1];
        for (int i = N - 1; i >= 0; i--)
        {
            num[i] = num[i - 1];
        }
        num[0] = tmp;
        M--;
    }
    // output
    for (int i = 0; i < N; i++)
    {
        cout << num[i];
        if (i != N - 1)
            cout << " ";
    }

}
