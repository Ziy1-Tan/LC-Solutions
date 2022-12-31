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
#include <algorithm>
using namespace std;
class Solution
{
public:
    int maxPathSum(TreeNode *root)
    {
        dfs(root);
        return res;
    }

private:
    int res = INT_MIN;
    // 计算以root为根节点的树对路径的贡献值
    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;

        // 若贡献值为负则无贡献
        int left = max(dfs(root->left), 0);
        int right = max(dfs(root->right), 0);

        // 更新结果
        int val = root->val + left + right;
        res = max(res, val);

        return root->val + max(left, right);
    }
};

int main(int argc, char const *argv[])
{
    auto r = new TreeNode(3);
    r->left = new TreeNode(-1);
    r->right = new TreeNode(3);
    auto res = (new Solution)->maxPathSum(r);
    cout << res << endl;
    return 0;
}
