#include <iostream>
#include <vector>

using namespace std;
struct Node
{
	Node(int a, int b, int c)
	{
		this->address = a;
		this->num = b;
		this->next = c;
	}
	Node()
	{
		this->address = 0;
		this->num = 0;
		this->next = 0;
	}
	int address;
	int num;
	int next;
};

void reverseList(Node* beg, Node* end);

int main()
{
	// input
	int addr, N, K;
	cin >> addr >> N >> K;
	vector<Node> list;
	for (int i = 0; i < N; i++)
	{
		int address, num, next;
		cin >> address >> num >> next;
		list.emplace_back(address, num, next);
	}
	// process
	//Node* ordered_list = new Node[N];
	vector<Node> ordered_list;
	for (int i = 0; i < N; i++)
	{
		for (auto j : list)
		{
			if (addr == j.address)
			{
				addr = j.next;
				//ordered_list[i] = j;
				ordered_list.push_back(j);
				break;
			}
		}
	}
	// reverse
	Node* beg=&ordered_list[0];
	Node* end = beg + K - 1;
	while (true)
	{
		reverseList(beg, end);
		if (end + K - &ordered_list[0] + 1 <= ordered_list.size())
		{
			beg += K;
			end += K;
		}
		else break;
	}
	// list it
	for (int i = 0; i < ordered_list.size(); i++)
	{
		if (i == ordered_list.size() - 1)
			ordered_list[i].next = -1;
		else
			ordered_list[i].next = ordered_list[i + 1].address;
	}
	// output
	for (int j = 0; j < ordered_list.size() -1; j++)
		printf("%05d %d %05d\n", ordered_list[j].address, ordered_list[j].num, ordered_list[j].next);
	printf("%05d %d -1\n", ordered_list[ordered_list.size() - 1].address, ordered_list[ordered_list.size() - 1].num);
}

void reverseList(Node* beg, Node* end)
{
	/*auto tmpPtr = end;
	(*beg).next = (*end).next;
	while (tmpPtr!=beg)
	{
		(*tmpPtr).next = (*(tmpPtr - 1)).address;
		tmpPtr--;
	}*/
	while (beg < end)
	{
		swap(*beg, *end);
		beg++; end--;
	}
}