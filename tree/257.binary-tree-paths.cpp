struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <vector>
#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        dfs(root, "");
        return res;
    }

private:
    vector<string> res;
    void dfs(TreeNode *root, string path)
    {
        path += to_string(root->val);

        if (!root->left && !root->right)
        {
            res.push_back(path);
            return;
        }

        if (root->left)
            dfs(root->left, path + "->");
        if (root->right)
            dfs(root->right, path + "->");
    }
};

int main(int argc, char const *argv[])
{
    auto r = new TreeNode(1);
    r->left = new TreeNode(2);
    r->right = new TreeNode(3);
    r->right->left = new TreeNode(4);
    Solution s;
    auto res = s.binaryTreePaths(r);
    auto pv = [](const vector<string> res)
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
