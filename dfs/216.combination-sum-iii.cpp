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

int main(int argc, char const *argv[])
{
    auto res = (new Solution)->combinationSum3(3, 9);
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
