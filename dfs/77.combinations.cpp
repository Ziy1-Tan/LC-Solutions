#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        dfs(n, k, 1);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(int n, int k, int idx)
    {
        if (path.size() == k)
        {
            res.push_back(path);
            return;
        }

        // n=7, k=4, 若此时path大小为0，即已经选了0个数，则最大选到[4,5,6,7], i最大为4
        // n=7, k=4, 若此时path大小为1，即已经选了1个数，则最大选到  [5,6,7], i最大为5
        // n=7, k=4, 若此时path大小为2，即已经选了2个数，则最大选到    [6,7], i最大为6
        for (int i = idx; i <= n - (k - path.size()) + 1; i++)
        {
            path.push_back(i);
            dfs(n, k, i + 1);
            path.pop_back();
        }
    }
};

int main(int argc, char const *argv[])
{
    auto res = (new Solution)->combine(4, 2);
    auto pv = [](const auto res)
    {
        for (auto &&i : res)
            cout << i << " ";
        cout << '\n';
    };
    for (auto &&i : res)
    {
        pv(i);
    }

    return 0;
}
