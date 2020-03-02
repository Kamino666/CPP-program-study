// P02.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// #1 数组方法

#include <iostream>
#include <vector>

using namespace std;

struct Term
{
	Term(int c, int e)
	{
		this->coef = c; this->exp = e;
	}
	int coef;
	int exp;
};

using Polynomail = vector<Term>;
Polynomail addPolys(const Polynomail& A, const Polynomail& B);
Polynomail multiPolys(const Polynomail& A, const Polynomail& B);

int main()
{
	Polynomail PolyA, PolyB;
	// input
	int aNum, bNum;
	cin >> aNum;
	for (int i = 0, tmpCoef, tmpExp; i < aNum; i++)
	{
		cin >> tmpCoef >> tmpExp;
		PolyA.emplace_back(tmpCoef, tmpExp);
	}
	cin >> bNum;
	for (int i = 0, tmpCoef, tmpExp; i < bNum; i++)
	{
		cin >> tmpCoef >> tmpExp;
		PolyB.emplace_back(tmpCoef, tmpExp);
	}
	// process
	Polynomail C = addPolys(PolyA, PolyB);
	Polynomail D = multiPolys(PolyA, PolyB);
	// output
	int zeroCount = 0;
	for (int i = 0; i < D.size(); i++)
	{
		if (D[i].coef != 0)
		{
			if (i != 0)
				cout << " ";
			cout << D[i].coef << " " << D[i].exp;
		}
		else
			zeroCount++;
	}
	if (zeroCount == D.size()) 
		cout << "0 0";
	cout << endl;

	zeroCount = 0;
	for (int i = 0; i < C.size(); i++)
	{
		if (C[i].coef != 0)
		{
			if (i != 0)
				cout << " ";
			cout << C[i].coef << " " << C[i].exp;
		}
		else
			zeroCount++;
	}
	if (zeroCount == C.size())
		cout << "0 0";
	return 0;
}

Polynomail addPolys(const Polynomail& A, const Polynomail& B)
{
	Polynomail rslt;
	auto Aptr = A.begin(), Bptr = B.begin();
	while (Aptr!=A.end() && Bptr != B.end())
	{
		if ((*Aptr).exp > (*Bptr).exp)
		{
			rslt.push_back(*Aptr);
			Aptr++;
		}
		else if ((*Aptr).exp < (*Bptr).exp)
		{
			rslt.push_back(*Bptr);
			Bptr++;
		}
		else
		{
			rslt.emplace_back((*Aptr).coef + (*Bptr).coef, (*Aptr).exp);
			Aptr++; Bptr++;
		}
	}
	if (Aptr != A.end())
		while (Aptr!=A.end())
		{
			rslt.push_back(*Aptr);
			Aptr++;
		}
	if (Bptr != B.end())
		while (Bptr != B.end())
		{
			rslt.push_back(*Bptr);
			Bptr++;
		}
	return rslt;
}

Polynomail multiPolys(const Polynomail& A, const Polynomail& B)
{
	vector<Polynomail> midRslt;
	for (auto tmpATerm : A)
	{
		Polynomail tmpPoly;
		for (auto tmpBTerm : B)
		{
			tmpPoly.emplace_back(tmpATerm.coef * tmpBTerm.coef, tmpATerm.exp + tmpBTerm.exp);

		}
		midRslt.push_back(tmpPoly);
	}
	for (auto i = ++midRslt.begin(); i < midRslt.end(); i++)
	{
		midRslt[0] = addPolys(midRslt[0], *i);
	}
	return midRslt[0];
}