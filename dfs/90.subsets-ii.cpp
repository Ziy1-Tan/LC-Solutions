#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(const vector<int> &nums, int idx)
    {
        res.push_back(path);
        for (int i = idx; i < nums.size(); i++)
        {
            if (i > idx && nums[i] == nums[i - 1])
                continue;
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }
};

class Solution2
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> path;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int mask = 0; mask < (1 << n); mask++)
        {
            path.clear();
            bool flag = true;
            for (int i = 0; i < n; i++)
            {
                if (mask & (1 << i))
                {
                    if (i > 0 && nums[i] == nums[i - 1] && (mask & (1 << (i - 1))) == 0)
                    {
                        flag = false;
                        break;
                    }
                    path.push_back(nums[i]);
                }
            }
            if (flag)
                res.push_back(path);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{1, 2, 2};
    auto res = (new Solution2)->subsetsWithDup(v);
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
