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
#include <numeric>
#include <stack>
using namespace std;
class Solution
{
public:
    void recoverTree(TreeNode *root)
    {
        TreeNode *x = nullptr, *y = nullptr;
        TreeNode *prev = new TreeNode(numeric_limits<int>().min());
        TreeNode *curr = root;
        stack<TreeNode *> stack;
        while (curr || !stack.empty())
        {
            while (curr)
            {
                stack.push(curr);
                curr = curr->left;
            }

            curr = stack.top();
            stack.pop();
            if (!x && prev->val > curr->val)
                x = prev;
            if (x && prev->val > curr->val)
                y = curr;
            prev = curr;
            curr = curr->right;
        }

        int tmp = x->val;
        x->val = y->val;
        y->val = tmp;
    }
};
