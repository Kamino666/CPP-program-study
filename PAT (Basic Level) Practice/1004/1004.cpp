// 1004.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

using namespace std;

struct student
{
    string name;
    string id;
    int grade;
};
int main()
{
    // input
    int num;
    cin >> num;
    student* stus = new student[num];
    for (int i = 0; i < num; i++)
    {
        student tmp;
        cin >> tmp.name >> tmp.id >> tmp.grade;
        stus[i] = tmp;
    }
    // bubbleSort
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - i - 1; j++)
        {
            if (stus[j].grade < stus[j + 1].grade)
            {
                student tmp = stus[j];
                stus[j] = stus[j + 1];
                stus[j + 1] = tmp;
            }

        }
    }
    // output
    cout << stus[0].name << " " << stus[0].id << endl;
    cout << stus[num - 1].name << " " << stus[num - 1].id;
}

