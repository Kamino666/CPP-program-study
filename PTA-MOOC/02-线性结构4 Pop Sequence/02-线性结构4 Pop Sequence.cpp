#include <iostream>
#include <array>
#include <stack>
#include <vector>

using namespace std;
bool canItPopRightly(int* seq, int M, int N);

int main()
{
	// input 
	//M:length of the stack
	//N:length of the numbers
	//K:the number of sequences to be checked
	int M, N, K;  
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int* seq = new int[N];
		for (int j = 0; j < N; j++)
			cin >> seq[j];
		if (canItPopRightly(seq, M, N))
			cout << "YES";
		else
			cout << "NO";
		if (i != K - 1)
			cout << endl;
	}
	return 0;
}

bool canItPopRightly(int* seq, int M, int N)
{
	stack<int> s;
	vector<int> rslt;
	for (int indexS = 0,leftNum = 1 ; indexS < N; indexS++)
	{
		// supply stack
		while (leftNum<=seq[indexS])
		{
			if (s.size() < M)
			{
				s.push(leftNum);
				leftNum++;
			}
			else return false;
		}
		// out stack
		if (seq[indexS] == s.top())
		{
			rslt.push_back(s.top());
			s.pop();
		}
		else
			return false;
	}
	return true;
}

