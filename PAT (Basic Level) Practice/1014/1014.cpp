// 1014.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	// input
	string str1, str2, str3, str4;
	cin >> str1 >> str2 >> str3 >> str4;
	// process
	// 1&2
	int count = 0;
	for (int i = 0; i < min(str1.size(), str2.size()); i++)
	{
		if(count == 2)
			break;
		if(str1[i] == str2[i] && count == 0)
		{
			switch (str1[i])
			{
			case 'A':cout << "MON "; count++; break;
			case 'B':cout << "TUE "; count++; break;
			case 'C':cout << "WED "; count++; break;
			case 'D':cout << "THU "; count++; break;
			case 'E':cout << "FRI "; count++; break;
			case 'F':cout << "SAT "; count++; break;
			case 'G':cout << "SUN "; count++; break;
			}
			continue;
		}
		if (str1[i] == str2[i] && count == 1)
		{
			if (isdigit(str1[i]))
			{
				count++;
				cout << "0" << str1[i] << ":";
			}
			else if (str1[i] >= 'A' && str1[i] <= 'N')
			{
				count++;
				cout << str1[i] - 'A' + 10 << ":";
			}
		}
	}
	// 3&4
	for (int i = 0; i < min(str3.size(), str4.size()); i++)
	{
		if (str3[i] == str4[i] && isalpha(str3[i]))
		{
			if (i < 10)
				cout << "0" << i;
			else
				cout << i;
			break;
		}
	}
}

