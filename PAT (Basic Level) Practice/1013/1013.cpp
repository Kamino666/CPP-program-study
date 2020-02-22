// 1013.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int num);

int main()
{
	// input
	int M, N;
	cin >> M >> N;
	// cal
	vector<int> arr;
	for (int i = 2, count = 0; count != N; i++)
	{
		if (isPrime(i))
		{
			arr.push_back(i);
			count++;
		}
	}
	// output
	bool firstMark = true;
	for (int i = M - 1, count = 0; i <= N - 1; i++, count++)
	{
		if (!firstMark)
		{
			cout << " ";
		}
		firstMark = false;
		cout << arr[i];
		if (count % 10 == 9)
		{
			cout << endl;
			firstMark = true;
		}
	}
	return 0;
}

bool isPrime(int num)
{
	if (num <= 1)
		return false;
	else if (num == 2 || num == 3 || num == 5 || num == 7)
		return true;
	else if (num % 2 == 0 || num % 3 == 0 || num % 5 == 0 || num % 7 == 0)
		return false;
	int sqrtNum = (int)sqrt(num);
	for (int i = num - 1; i >= sqrtNum && i > 1; i--)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}


