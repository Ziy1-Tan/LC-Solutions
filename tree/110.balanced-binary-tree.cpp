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
    bool isBalanced(TreeNode *root)
    {
        if (!root)
            return true;

        if (abs(depth(root->left) - depth(root->right)) > 1)
            return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }

private:
    int depth(TreeNode *root)
    {
        if (!root)
            return 0;

        return 1 + max(depth(root->left), depth(root->right));
    }
};

class Solution2
{
public:
    bool isBalanced(TreeNode *root)
    {
        return depth(root) != -1;
    }

private:
    int depth(TreeNode *root)
    {
        if (!root)
            return 0;

        int left = depth(root->left);
        if (left == -1)
            return -1;
        int right = depth(root->right);
        if (right == -1)
            return -1;
        return abs(left - right) <= 1 ? 1 + max(left, right) : -1;
    }
};
