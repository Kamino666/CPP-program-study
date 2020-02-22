// 1012.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;


int main()
{
    vector<int> A1vct, A2vct, A3vct, A4vct, A5vct;
    // input
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        switch (tmp%5)
        {
        case 0:
            if (tmp % 2 == 0)
                A1vct.push_back(tmp);
            break;
        case 1:
            A2vct.push_back(tmp); break;
        case 2:
            A3vct.push_back(tmp); break;
        case 3:
            A4vct.push_back(tmp); break;
        case 4:
            A5vct.push_back(tmp); break;
        default:
            break;
        }
    }
    // process
    //A1
    if (A1vct.size() == 0)
        cout << "N ";
    else
    {
        int sum = 0;
        for (auto i : A1vct)
            sum += i;
        cout << sum << " ";
    }
    //A2
    if (A2vct.size() == 0)
        cout << "N ";
    else
    {
        int sum = 0;
        for (int i = 0; i < A2vct.size(); i++)
        {
            if (i % 2 == 0)
                sum += A2vct[i];
            else
                sum -= A2vct[i];
        }
        cout << sum << " ";
    }
    //A3
    if (A3vct.size() == 0)
        cout << "N ";
    else
        cout << A3vct.size() << " ";
    //A4
    if (A4vct.size() == 0)
        cout << "N ";
    else
    {
        double ave = 0;
        for (auto i : A4vct)
            ave += i;
        ave /= A4vct.size();
        printf("%.1lf ", ave);
    }
    //A5
    if (A5vct.size() == 0)
        cout << "N";
    else
    {
        int max = A5vct[0];
        for (auto i : A5vct)
            if (i > max)
                max = i;
        cout << max;
    }
}

