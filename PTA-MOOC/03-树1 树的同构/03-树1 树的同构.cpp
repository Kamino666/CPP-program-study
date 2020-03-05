#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct TreeNode
{
	TreeNode(char a,int b, int c):info(a),left(b),right(c){}
	TreeNode() :info(0), left(0), right(0) {}
	char info;
	int left;
	int right;
};
using Tree = vector<TreeNode>;
bool isSimilar(Tree& T1, int h1, const Tree& T2, int h2);

int main()
{
	// input
	int N1,N2;
	cin >> N1;
	Tree T1, T2;
	set<int> h1f, h2f;
	for (int i = 0; i < N1; i++)
	{
		char info;
		int l, r;
		cin >> info;
		if (!(cin >> l)) l = -1;
		cin.sync(); cin.clear();
		if (!(cin >> r)) r = -1;
		cin.sync(); cin.clear();  // 重置cin状态、清空缓冲区
		if (l != -1)h1f.insert(l);
		if (r != -1)h1f.insert(r);  // h1f用来找根
		T1.emplace_back(info, l, r);
	}
	cin >> N2;
	for (int i = 0; i < N2; i++)
	{
		char info;
		int l, r;
		cin >> info;
		if (!(cin >> l)) l = -1;
		cin.sync(); cin.clear();
		if (!(cin >> r)) r = -1;
		cin.sync(); cin.clear();
		if (l != -1)h2f.insert(l);
		if (r != -1)h2f.insert(r);
		T2.emplace_back(info, l, r);
	}
	// process
	if (N1 != N2)
	{
		cout << "No";
		return 0;  
	}
	if (N1 == 0)
	{
		cout << "Yes";
		return 0;
	}
	// find head
	int h1=0, h2=0;
	for (auto i = h1f.begin(); i != h1f.end(); i++, h1++)
	{
		if ((*i) != h1)break;
	}
	for (auto i = h2f.begin(); i != h2f.end(); i++, h2++)
	{
		if ((*i) != h2)break;
	}
	// traverse 
	if (T1[h1].info == T2[h2].info)
	{
		bool mark = isSimilar(T1, h1, T2, h2);
		if (mark)
			cout << "Yes";
		else
			cout << "No";
	}
	else
		cout << "No";
	return 0;
}

bool isSimilar(Tree& T1, int h1, const Tree& T2, int h2)
{
	int lson1 = T1[h1].left, rson1 = T1[h1].right;
	int lson2 = T2[h2].left, rson2 = T2[h2].right;
	int count1 = 0, count2 = 0;
	if (lson1 == -1)count1++;
	if (rson1 == -1)count1++;
	if (lson2 == -1)count2++;
	if (rson2 == -1)count2++;
	// 如果儿子数目不同
	if (count1 != count2)
		return false;
	// 如果是尾巴
	else if (lson1 == -1 && rson1 == -1 && lson2 == -1 && rson2 == -1)
		return true;
	// 如果有一支且同向
	else if (lson1 == -1 && rson1 != -1 && lson2 == -1 && rson2 != -1)
	{
		if (T1[rson1].info == T2[rson2].info)
			return isSimilar(T1, rson1, T2, rson2);
		else
			return false;
	}
	else if (lson1 != -1 && rson1 == -1 && lson2 != -1 && rson2 == -1)
	{
		if (T1[lson1].info == T2[lson2].info)
			return isSimilar(T1, lson1, T2, lson2);
		else
			return false;
	}
	//如果有有一支且不同向
	else if (lson1 != -1 && rson1 == -1 && lson2 == -1 && rson2 != -1)
	{
		if (T1[lson1].info == T2[rson2].info)
			return isSimilar(T1, lson1, T2, rson2);
		else
			return false;
	}
	else if (lson1 == -1 && rson1 != -1 && lson2 != -1 && rson2 == -1)
	{
		if (T1[rson1].info == T2[lson2].info)
			return isSimilar(T1, rson1, T2, lson2);
		else
			return false;
	}
	else
	{
		// 如果根的左右两子相同
		if (T1[lson1].info == T2[lson2].info && T1[rson1].info == T2[rson2].info)
		{
			bool mk1, mk2;
			// 比较左子的同构
			mk1 = isSimilar(T1, lson1, T2, lson2);
			// 比较右子的同构
			mk2 = isSimilar(T1, rson1, T2, rson2);
			if (mk1 && mk2)
				return true;
		}
		// 如果根的左右两子交换后相同
		else if (T1[lson1].info == T2[rson2].info && T1[rson1].info == T2[lson2].info)
		{
			bool mk1, mk2;
			// 比较左子的同构
			mk1 = isSimilar(T1, rson1, T2, lson2);
			// 比较右子的同构
			mk2 = isSimilar(T1, lson1, T2, rson2);
			if (mk1 && mk2)
				return true;
		}
		else
			return false;
	}
}
