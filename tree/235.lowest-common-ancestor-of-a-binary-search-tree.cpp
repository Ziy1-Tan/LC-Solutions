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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        while ((long)(root->val - p->val) * (long)(root->val - q->val) > 0)
            root = p->val < root->val ? root->left : root->right;
        return root;
    }
};

class Solution2
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if ((long)(root->val - p->val) * (long)(root->val - q->val) <= 0)
            return root;

        return lowestCommonAncestor(p->val < root->val ? root->left : root->right, p, q);
    }
};

class Solution3
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root || root == p || root == q)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        // 说明p、q均在右子树
        if (!left)
            return right;

        if (!right)
            return left;

        return root;
    }
};
