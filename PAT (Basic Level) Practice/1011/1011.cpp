// 1011.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string add(string a, string b);  // 任意大数字相加
string _minus(string a, string b);  // 自然数相减 a是被减数
string _plus(string a, string b);  // 自然数相加
int _compare(string ab, string c);  // 任意数字的比较

int main()
{
    //DEBUG
    /*while (true)
    {
        string x, y;
        cin >> x >> y;
        cout << add(x, y) << endl;
    }*/
    // input
    vector<string> A, B, C, AB;
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        string tmpA, tmpB, tmpC;
        cin >> tmpA >> tmpB >> tmpC;
        A.push_back(tmpA);
        B.push_back(tmpB);
        C.push_back(tmpC);
    }
    // process
    for (int i = 0; i < T; i++)
    {
        string tmpAB;
        tmpAB = add(A[i], B[i]);
        AB.push_back(tmpAB);
        // output
        if (_compare(AB[i], C[i])==1)
        {
            cout << "Case #" << (i + 1) << ": " << "true";
        }
        else
        {
            cout << "Case #" << (i + 1) << ": " << "false";
        }
        if (i != T - 1)
            cout << endl;
    }
}



string add(string a, string b)  // 任意大数字相加
{
    if (a[0] == '-' && b[0] == '-')  // 如果同负号 则删符号自然数相加
    {
        a.erase(a.begin());
        b.erase(b.begin());
        return "-" + _plus(a, b);
    }
    else if (a[0] != '-' && b[0] != '-')  // 如果同正号 则自然数相加
    {
        return _plus(a, b);
    }
    else if (a[0] != '-' && b[0] == '-')  // 如果a正b负
    {
        b.erase(b.begin());
        return _minus(a, b);
    }
    else  // 如果b正a负
    {
        a.erase(a.begin());
        return _minus(b, a);
    }
}

string _plus(string a, string b)  // 自然数相加
{
    int carry = 0;
    string rslt = "", m, n;
    if (a.size() > b.size())
    {
        m = a; n = b;
    }
    else
    {
        m = b; n = a;
    }
    auto nPtr = n.rbegin(), mPtr = m.rbegin();
    while (mPtr!=m.rend())
    {
        int nNum, mNum;
        if (nPtr == n.rend())
        {
            nNum = 0;
            mNum = (*mPtr) - '0';
        }
        else
        {
            nNum = (*nPtr) - '0';
            mNum = (*mPtr) - '0';
        }
        string tmp = "a";  // tmp是本位数字
        tmp[0] = (char)((nNum + mNum + carry) % 10 + '0');
        carry = (nNum + mNum + carry) / 10;  // carry是进位

        rslt += tmp;
        if(nPtr != n.rend())
            nPtr++;
        mPtr++;
    }
    // 加入可能存在的最后一个进位
    if (carry != 0)
    {
        string tmp = "a";  // tmp是本位数字
        tmp[0] = (char)(carry + '0');
        rslt += tmp;
    }

    reverse(rslt.begin(), rslt.end());
    return rslt;
}
string _minus(string a, string b)  // 自然数相减 a是被减数
{
    bool negative = false;  // 结果是负数
    string rslt;
    if (_compare(a, b) == -1)  // a<b
    {
        negative = true;
        swap(a, b);
    }
    else if (_compare(a, b) == 0)
        return "0";
    int borrow = 0;
    auto aPtr = a.rbegin(), bPtr = b.rbegin();
    while (aPtr != a.rend())
    {
        int aNum, bNum;  // 定义并且确认加的两个数字
        if (bPtr == b.rend())
        {
            aNum = (*aPtr) - '0';
            bNum = 0;
        }
        else
        {
            aNum = (*aPtr) - '0';
            bNum = (*bPtr) - '0';
        }
        string tmp = "a";  // tmp是本位数字
        if (aNum - bNum - borrow < 0)
        {
            tmp[0] = (10 + aNum - bNum - borrow) + '0';  // 减去上位的借位
            borrow = 1;  // 借位
        }
        else
        {
            tmp[0] = (aNum - bNum - borrow) + '0';  // 减去上位的借位
        }
        rslt += tmp;
        if (bPtr != b.rend())
            bPtr++;
        aPtr++;
    }

    reverse(rslt.begin(), rslt.end());
    // 去零
    for (auto i = rslt.begin(); *i == '0';)
    {
        i = rslt.erase(i);
    }
    if (negative)  // 负数要加负号
        rslt.insert(rslt.begin(), '-');
    return rslt;
}

int _compare(string ab, string c)  // ab大回1 c大回-1 相等回0
{
    bool negative = false;  // 要不要反转
    if (ab[0] == '-' && c[0] != '-')
        return -1;
    if (ab[0] != '-' && c[0] == '-')
        return 1;
    if (ab[0] == '-' && c[0] == '-')
        negative = true;
    // 以下确认是同号
    if (ab.size() > c.size())
    {
        if (negative)
            return -1;
        else
            return 1;
    }
    else if (ab.size() < c.size())
    {
        if (negative)
            return 1;
        else
            return -1;
    }
    // 以下确认是同位数
    for (int i = 0; i < ab.size(); i++)
    {
        if (ab[i] > c[i])
            if (negative)
                return -1;
            else
                return 1;
        else if (ab[i] < c[i])
            if (negative)
                return 1;
            else
                return -1;
    }
    return 0;
}
