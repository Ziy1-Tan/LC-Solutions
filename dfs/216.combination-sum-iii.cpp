#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        dfs(k, n, 0);
        return res;
    }

private:
    const vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
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

        for (int i = idx; i < nums.size(); i++)
        {
            if (n - nums[i] < 0)
                break;
            path.push_back(nums[i]);
            dfs(k - 1, n - nums[i], i + 1);
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
