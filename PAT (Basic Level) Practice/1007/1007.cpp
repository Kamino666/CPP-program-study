// 1007.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int num);

int main()
{
    // input
    int N;
    cin >> N;
    // process
    int count = 0;
    for (int i = 5; i <= N; i++)
    {

        if (isPrime(i) && isPrime(i - 2))  // core
            count++;
    }
    // output
    cout << count;
}

bool isPrime(int num)
{
    int sqNum;  //sqrt
    sqNum = (int)sqrt((double)num);
    for (int i = 2; i <=sqNum; i++)
        if (num % i == 0)
            return false;
    return true;
}
