// 1015.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

struct Student
{
	int id;
	int de;
	int cai;
	int grade;
	bool operator>(const Student& s)
	{
		if (this->grade < s.grade)
			return true;
		else if (this->grade > s.grade)
			return false;
		else
		{
			if (this->de + this->cai > s.de + s.cai)
				return true;
			else if (this->de + this->cai < s.de + s.cai)
				return false;
			else
			{
				if (this->de > s.de)
					return true;
				else if (this->de < s.de)
					return false;
				else
				{
					if (this->id < s.id)
						return true;
					else
						return false;
				}
			}
		}
		
	}
	bool operator<(const Student& s)
	{
		if (this->operator>(s))
			return false;
		else
			return true;
	}
};

int main()
{
	// input
	int N, L, H;
	cin >> N >> L >> H;
	vector<Student> Stus;
	for (int i = 0; i < N; i++)
	{
		Student tmp;
		int tmpid, tmpde, tmpcai,tmpgrade;
		cin >> tmpid >> tmpde >> tmpcai;
		if (tmpde >= L&& tmpcai >= L)  // 及格的
		{
			if (tmpde >= H && tmpcai >= H)
				tmpgrade = 1;
			else if (tmpde >= H && tmpcai < H)
				tmpgrade = 2;
			else if (tmpde >= tmpcai)
				tmpgrade = 3;
			else
				tmpgrade = 4;
			tmp.de = tmpde; tmp.cai = tmpcai; tmp.id = tmpid; tmp.grade = tmpgrade;
			if(Stus.size()==0)
				Stus.push_back(tmp);
			else
			{
				bool mark = false;
				for (auto i = Stus.begin(); i < Stus.end(); i++)
				{
					if (tmp > (*i))
					{
						Stus.insert(i, tmp);
						mark = true;
						break;
					}
				}
				if (!mark)
					Stus.push_back(tmp);
			}
		}
	}
	// process BubbleSort
	/*for (int i = 0; i < Stus.size(); i++)
	{
		for (int j = 0; j < Stus.size() - 1 - i; j++)
		{
			if (Stus[j] < Stus[j + 1])
				swap(Stus[j], Stus[j + 1]);
		}
	}*/
	// output
	cout << Stus.size() << endl;
	for (auto i = Stus.begin(); i < Stus.end(); i++)
	{
		cout << i->id << " " << i->de << " " << i->cai;
		if ((i+1) != Stus.end())
			cout << endl;
	}
	return 0;
}

