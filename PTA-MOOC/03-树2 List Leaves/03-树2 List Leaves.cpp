#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#define DE -1

using namespace std;

struct TreeNode
{
    TreeNode() :lson(DE), rson(DE) {}
    int lson;
    int rson;
};
using Tree = vector<TreeNode>;

int main()
{
    // input
    int N, head = 0;
    set<unsigned> sonNodes;
    Tree T;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        char l, r;
        TreeNode tmpNode;
        cin >> l >> r;
        if (isdigit(l)) {
            tmpNode.lson = l - '0';
            sonNodes.insert(l-'0');
        }
        if (isdigit(r)) {
            tmpNode.rson = r - '0';
            sonNodes.insert(r-'0');
        }
        T.push_back(tmpNode);
    }
    // find head
    int count = 0;
    bool havehead = false;
    for (auto i=sonNodes.begin();i!=sonNodes.end();count++,i++)
    {
        if ((*i) != count)
        {
            head = count;
            havehead = true;
            break;
        }
    }
    if (!sonNodes.empty() && !havehead)
        head = N - 1;
    // traverse
    queue<unsigned> q;
    vector<int> rslt;
    q.push(head);
    while (!q.empty())
    {
        auto tmpNode = T[q.front()];
        if (tmpNode.lson == DE && tmpNode.rson == DE)
        {
            rslt.push_back(q.front());
        }
        else
        {
            if (tmpNode.lson != DE)
                q.push(tmpNode.lson);
            if (tmpNode.rson != DE)
                q.push(tmpNode.rson);
        }
        q.pop();
    }
    // output
    cout << rslt[0];
    for (int i = 1; i < rslt.size(); i++)
        cout << " " << rslt[i];
    return 0;
}
