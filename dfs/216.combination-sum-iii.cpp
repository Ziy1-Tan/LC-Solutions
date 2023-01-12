#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        dfs(k, n, 1);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(int k, int n, int idx)
    {
        if (k == 0)
        {
            if (n == 0)
                res.push_back(path);
            return;
        }

        for (int i = idx; i <= 9; i++)
        {
            if (n - i < 0)
                break;
            path.push_back(i);
            dfs(k - 1, n - i, i + 1);
            path.pop_back();
        }
    }
};

class Solution2
{
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> res;
        vector<int> path;
        path.reserve(9);
        for (int mask = 0; mask < (1 << 9); mask++)
        {
            path.clear();
            int rest = n;
            for (int i = 0; i < 9; i++)
            {
                if (mask & (1 << i))
                {
                    rest -= i + 1;
                    path.push_back(i + 1);
                }
            }
            if (path.size() == k && rest == 0)
                res.push_back(path);
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
    auto res = (new Solution2)->combinationSum3(3, 9);
    auto pv = [](const auto res)
    {
        for (auto &&i : res)
            cout << i << " ";
        cout << '\n';
    };
    for (auto &&i : res)
        pv(i);

    return 0;
}
