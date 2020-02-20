// 1005.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

struct Term
{
    int num;
    bool isKey;
};

int main()
{
    // input
    int K;
    cin >> K;
    auto seq = new Term[K];
    for (int i = 0; i < K; i++)
    {
        Term tmp;
        tmp.isKey = true;
        cin >> tmp.num;
        seq[i] = tmp;
    }
    // bubbleSort
    for(int i=0;i<K;i++)
        for (int j = 0; j < K - i - 1; j++)
        {
            if (seq[j].num < seq[j + 1].num)
            {
                Term tmp = seq[j];
                seq[j] = seq[j + 1];
                seq[j + 1] = tmp;
            }
        }
    // process
    int count = K;
    for (int i = 0; i < K; i++)
    {
        int pcNum = seq[i].num;
        while (pcNum!=1)
        {
            if (pcNum % 2 == 0)  // is not odd
            {
                pcNum /= 2;
            }
            else  // is odd
            {
                pcNum = (3 * pcNum + 1) / 2;
            }
            // find if there is repeated number
            for (int j = 0; j < K; j++)
                if (seq[j].isKey)  // if may be Key
                    if (seq[j].num == pcNum)
                    {
                        seq[j].isKey = false;
                        count--;
                    }

        }
    }
    // output
    for (int i = 0; i < K; i++)
    {
        if (seq[i].isKey)
        {
            cout << seq[i].num;
            count--;
            if (count != 0)
                cout << " ";
        }
    }
}
