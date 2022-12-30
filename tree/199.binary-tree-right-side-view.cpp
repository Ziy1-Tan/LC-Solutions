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
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        if (!root)
            return {};
        vector<int> res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int cnt = q.size();
            while (cnt-- > 0)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                if (cnt == 0)
                    res.push_back(node->val);
            }
        }
        return res;
    }
};

class Solution2
{
private:
    vector<int> res;
    void dfs(TreeNode *root, int depth)
    {
        if (!root)
            return;

        if (res.size() == depth)
            res.push_back(root->val);

        dfs(root->right, depth + 1);
        dfs(root->left, depth + 1);
    }

public:
    vector<int> rightSideView(TreeNode *root)
    {
        dfs(root, 0);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    auto r = new TreeNode(1);
    r->left = new TreeNode(2);
    r->left->left = new TreeNode(3);
    r->right = new TreeNode(4);
    r->right->right = new TreeNode(5);
    Solution2 s;
    auto res = s.rightSideView(r);
    auto pv = [](const vector<int> res)
    {
        for (auto &&i : res)
        {
            cout << i << " ";
        }
        cout << '\n';
    };
    pv(res);
    return 0;
}
