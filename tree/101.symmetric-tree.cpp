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
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;

        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode *p, TreeNode *q)
    {
        if (!p || !q)
            return p == q;

        return p->val == q->val &&
               isMirror(p->left, q->right) && isMirror(p->right, q->left);
    }
};

class Solution2
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;

        queue<TreeNode *> queue;
        queue.push(root);
        queue.push(root);
        while (!queue.empty())
        {
            auto p = queue.front();
            queue.pop();
            auto q = queue.front();
            queue.pop();

            if (!p && !q)
                continue;

            if ((!p || !q) || (p->val != q->val))
                return false;

            queue.push(p->left);
            queue.push(q->right);

            queue.push(p->right);
            queue.push(q->left);
        }
        return true;
    }
};
