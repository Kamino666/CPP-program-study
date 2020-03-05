#include <iostream>
#include <vector>
#include <stack>
#define DE -1

using namespace std;

struct TreeNode
{
	TreeNode() :dad(DE), lson(DE), rson(DE),count(0) {}
	int dad;
	int lson;
	int rson;
	int count;
};
using Tree = vector<TreeNode>;
using NodeIter = unsigned;
void traversalTree(const Tree& T, int root, bool& flag);

int main()
{
	// input
	int N;
	Tree T;
	NodeIter iter = 0;
	cin >> N;
	for (int i = 0; i <= N; i++)
	{
		TreeNode tmp;
		T.push_back(tmp);
	}
	// construct tree
	stack<int> S;
	int count = 0;
	while (count != N)
	{
		string cmd;
		cin >> cmd;
		if (cmd == "Push")  // push 
		{
			int next; cin >> next;
			S.push(next);  //in stack
			T[next].dad = iter;  // 设置父
			if (T[iter].lson == DE)  // 增加子
				T[iter].lson = next;
			else
				T[iter].rson = next;
			iter = next;  // 移动指针
		}
		else  // pop
		{
			S.pop();  // out stack
			count++;
			if (T[iter].lson != DE && T[iter].rson == DE)  // 1 son
			{
				// do nothing
				if(T[iter].count==0)
					T[iter].count++;
				else 
					iter = T[iter].dad;
			}
			else  // 0 or 2 son
			{
				// back to dad
				iter = T[iter].dad;
			}
		}
	}
	// output
	bool flag = false;
	traversalTree(T, 1, flag);
	return 0;
}

void traversalTree(const Tree& T,int root, bool& flag)
{

	//if (T[root].lson != DE)
	//	traversalTree(T, T[root].lson, false);
	//if (T[root].rson != DE)
	//	traversalTree(T, T[root].rson, false);
	if (root != DE)
	{
		traversalTree(T, T[root].lson, flag);
		traversalTree(T, T[root].rson, flag);
		if (!flag)
			flag = true;
		else
			cout << " ";
		cout << root;
	}

}