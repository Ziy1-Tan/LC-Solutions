struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        dfs(root, targetSum);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(TreeNode *root, int sum)
    {
        if (!root)
            return;

        sum -= root->val;
        path.push_back(root->val);

        if (!root->left && !root->right && sum == 0)
            res.push_back(path);

        dfs(root->left, sum);
        dfs(root->right, sum);

        path.pop_back();
    }
};

int main(int argc, char const *argv[])
{
    auto r = new TreeNode(1);
    r->left = new TreeNode(2);
    r->left->right = new TreeNode(2);
    r->right = new TreeNode(4);
    // r->right->left = new TreeNode(1);
    Solution s;
    auto res = s.pathSum(r, 5);
    auto pv = [](const vector<int> res)
    {
        for (auto &&i : res)
        {
            cout << i << " ";
        }
        cout << '\n';
    };
    for (auto &&v : res)
    {
        pv(v);
    }

    return 0;
}
