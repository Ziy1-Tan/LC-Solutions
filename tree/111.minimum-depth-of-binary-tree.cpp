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
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;

        int left = minDepth(root->left);
        int right = minDepth(root->right);

        if (!root->left || !root->right)
            return 1 + left + right;

        return 1 + min(left, right);
    }
};

class Solution2
{
public:
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;

        int depth = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int cnt = q.size();
            depth++;
            while (cnt-- > 0)
            {
                TreeNode *node = q.front();
                q.pop();
                if (!node->left && !node->right)
                    return depth;

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return depth;
    }
};

int main(int argc, char const *argv[])
{
    auto r = new TreeNode(1);
    r->left = new TreeNode(2);
    r->right = new TreeNode(3);
    r->right->right = new TreeNode(4);
    cout << (new Solution2)->minDepth(r) << endl;
    return 0;
}
