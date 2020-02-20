// 1010.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

struct Term
{
    int coef;
    int exp;
};
using Polynomial = vector<Term>;

int main()
{
    // input
    Polynomial poly;
    while (true)
    {
        Term tmp = { 0,0 };
        if (!(cin >> tmp.coef))
            break;
        cin >> tmp.exp;
        poly.push_back(tmp);
    }
    // process
    for (auto& term : poly)
    {
        term.coef *= term.exp;
        term.exp--;  // exp may appear -1
    }
    // output
    if (poly[0].exp == -1)
    {
        cout << "0 0";
        return 0;
    }
    for (int i = 0; i < poly.size(); i++)
    {
        if (poly[i].exp == -1)
            continue;
        if (i != 0)
            cout << " ";
        cout << poly[i].coef << " " << poly[i].exp;
    }
}

