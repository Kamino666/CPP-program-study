// 1002.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<string> NUMBER{ "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };

int main()
{
	//Input
	string numStr;
	cin >> numStr;
	//Process
	int sum = 0;
	for (auto numC : numStr)
	{
		sum += numC - '0';
	}
	//output
	string sumStr = to_string(sum);
	bool is_first = true;
	for (auto sumC : sumStr)
	{
		if (!is_first)
			cout << ' ';
		is_first = false;
		cout << NUMBER[sumC - '0'];
	}
}
