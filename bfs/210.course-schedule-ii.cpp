#include <queue>
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> res;
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> adj(numCourses, vector<int>());
        for (auto &&pre : prerequisites)
        {
            inDegree[pre[0]]++;
            adj[pre[1]].push_back(pre[0]);
        }

        queue<int> q;
        for (int i = 0; i < inDegree.size(); i++)
            if (inDegree[i] == 0)
                q.push(i);

        while (!q.empty())
        {
            numCourses--;
            int selected = q.front();
            q.pop();

            res.push_back(selected);

            if (adj[selected].empty())
                continue;

            const auto &tmp = adj[selected];
            for (const auto &i : tmp)
                if (--inDegree[i] == 0)
                    q.push(i);
        }

        if (numCourses != 0)
            return {};

        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> pre = {{1, 0}};
    auto res = (new Solution)->findOrder(2, pre);
    auto pv = [](const auto res)
    {
        for (auto &&i : res)
            cout << i << " ";
        cout << '\n';
    };
    pv(res);
    return 0;
}
