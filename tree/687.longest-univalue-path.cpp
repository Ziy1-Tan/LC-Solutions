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
using namespace std;
class Solution
{
public:
    int longestUnivaluePath(TreeNode *root)
    {
        dfs(root);
        return res;
    }

private:
    int res = 0;
    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        // 根节点与左孩子同值，更新左最长路径，否则置为0
        if (root->left && root->val == root->left->val)
            left++;
        else
            left = 0;

        if (root->right && root->val == root->right->val)
            right++;
        else
            right = 0;

        res = max(res, left + right);

        return max(left, right);
    }
};

int main(int argc, char const *argv[])
{
    auto r = new TreeNode(1);
    r->left = new TreeNode(2);
    r->left->left = new TreeNode(2);
    r->left->right = new TreeNode(2);
    r->right = new TreeNode(1);
    r->right->right = new TreeNode(1);
    auto cnt = (new Solution)->longestUnivaluePath(r);
    cout << cnt << endl;
    return 0;
}
