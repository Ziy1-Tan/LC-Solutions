#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
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
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }
};

class Solution2
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        res.push_back({});
        for (auto &&num : nums)
        {
            int size = res.size();
            for (int i = 0; i < size; i++)
            {
                vector<int> tmp{res[i]};
                tmp.push_back(num);
                res.push_back(tmp);
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{1, 2, 3};
    auto v = (new Solution2)->subsets(nums);
    auto pv = [](const auto res)
    {
        for (auto &&i : res)
            cout << i << " ";
        cout << '\n';
    };
    for (auto &&i : v)
        pv(i);
    return 0;
}
