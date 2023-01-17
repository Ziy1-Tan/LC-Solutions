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
#include <queue>
#include <deque>
using namespace std;
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.push(root);
        bool isReverse = false;
        while (!q.empty())
        {
            deque<int> tmp;
            int size = q.size();
            while (size-- > 0)
            {
                TreeNode *node = q.front();
                q.pop();
                if (isReverse)
                    tmp.push_front(node->val);
                else
                    tmp.push_back(node->val);

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            isReverse = !isReverse;
            res.emplace_back(tmp.begin(), tmp.end());
        }
        return res;
    }
};
