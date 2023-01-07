#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        dfs(candidates, target, 0);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(const vector<int> &candidates, int rest, int idx)
    {
        if (rest <= 0)
        {
            res.push_back(path);
            return;
        }

        for (int i = idx; i < candidates.size(); i++)
        {
            if (rest - candidates[i] >= 0)
            {
                path.push_back(candidates[i]);
                dfs(candidates, rest - candidates[i], i);
                path.pop_back();
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> r = {2, 3, 6, 7};
    auto res = (new Solution)->combinationSum(r, 7);

    auto pv = [](const vector<int> res)
    {
        for (auto &&i : res)
        {
            cout << i << " ";
        }
        cout << '\n';
    };
    for (auto &&v : res)
        pv(v);

    return 0;
}
