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
#include <string>
using namespace std;
class Solution
{
public:
    string smallestFromLeaf(TreeNode *root)
    {
        if (!root)
            return "";

        dfs(root, "");
        return res;
    }

private:
    string res = "zzz";
    void dfs(TreeNode *root, string str)
    {
        if (!root)
            return;

        str = (char)('a' + root->val) + str;
        if (!root->left && !root->right && str < res)
            res = str;

        dfs(root->left, str);
        dfs(root->right, str);
    }
};

int main(int argc, char const *argv[])
{
    auto r = new TreeNode(0);
    r->left = new TreeNode(1);
    r->right = new TreeNode(0);
    r->right->right = new TreeNode(1);
    auto res = (new Solution)->smallestFromLeaf(r);
    cout << res << endl;
    return 0;
}
