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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int cnt = q.size();
            res.push_back({});
            while (cnt-- > 0)
            {
                TreeNode *node = q.front();
                q.pop();
                res.back().push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->right = new TreeNode(1);
    Solution s;
    auto res = s.levelOrderBottom(root);
    auto pv = [](const vector<int> res)
    {
        for (auto &&i : res)
        {
            cout << i << " ";
        }
        cout << '\n';
    };
    for (auto &&v : res)
        pv(v);

    return 0;
}
