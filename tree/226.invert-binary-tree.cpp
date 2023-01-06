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
#include <queue>
using namespace std;
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return nullptr;

        invertTree(root->left);
        invertTree(root->right);

        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        return root;
    }
};

class Solution2
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return root;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            TreeNode *tmp = node->left;
            node->left = node->right;
            node->right = tmp;

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        return root;
    }
};
