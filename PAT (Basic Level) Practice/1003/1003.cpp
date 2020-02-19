// 1003.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>


using namespace std;

int main()
{
    // Input
    int num;
    cin >> num;
    string* patL = new string[num];
    bool* judgeRslt = new bool[num];
    for (int i = 0; i < num; i++)
        judgeRslt[i] = true;
    for (int i = 0; i < num; i++)
    {
        cin >> patL[i];
        for (auto j : patL[i])  // 1-judge
        {
            if (j != 'P' && j != 'A' && j != 'T')
            {
                judgeRslt[i] = false;
                break;
            }
        }
        int P = patL[i].find("P"), T = patL[i].find("T");  // 2,3-judge
        int c1, c2, c3;
        if (P != patL[i].npos && T  != patL[i].npos)
        {
            c1 = P;
            c2 = T - P - 1;
            c3 = (int)(patL[i].length()) - T - 1;
            if (c2 == 0)  // c2 cannot be 0
                judgeRslt[i] = false;
            if (c3 - c1 * (c2 - 1) != c1)  // 3-judege
            {
                judgeRslt[i] = false;
            }
        }
        else  // if no P or T
        {
            judgeRslt[i] = false;
        }
    }

    // Output
    for (int i = 0; i < num; i++)
    {
        if (judgeRslt[i])
            cout << "YES";
        else
            cout << "NO";
        if (i != num - 1)
            cout << endl;
    }

}
