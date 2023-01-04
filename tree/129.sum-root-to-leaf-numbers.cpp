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
#include <tuple>
using namespace std;
class Solution
{
public:
    int sumNumbers(TreeNode *root)
    {
        dfs(root, 0);
        return sum;
    }

private:
    int sum = 0;
    void dfs(TreeNode *root, int num)
    {
        if (!root)
            return;

        int tmp = num * 10 + root->val;
        if (!root->left && !root->right)
            sum += tmp;

        dfs(root->left, tmp);
        dfs(root->right, tmp);
    }
};

class Solution2
{
public:
    int sumNumbers(TreeNode *root)
    {
        if (!root)
            return 0;
        queue<tuple<TreeNode *, int>> q;
        q.push({root, root->val});
        int sum = 0;
        while (!q.empty())
        {
            auto [node, val] = q.front();
            q.pop();
            if (!node->left && !node->right)
                sum += val;
            if (node->left)
                q.push({node->left, val * 10 + node->left->val});
            if (node->right)
                q.push({node->right, val * 10 + node->right->val});
        }
        return sum;
    }
};

int main(int argc, char const *argv[])
{
    auto r = new TreeNode(1);
    r->left = new TreeNode(2);
    r->right = new TreeNode(3);
    cout << (new Solution2)->sumNumbers(r) << endl;
    return 0;
}
