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
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

class Solution2
{
public:
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;

        int depth = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int cnt = q.size();
            while (cnt-- > 0)
            {
                TreeNode *root = q.front();
                q.pop();
                if (root->left)
                    q.push(root->left);
                if (root->right)
                    q.push(root->right);
            }
            depth++;
        }
        return depth;
    }
};
