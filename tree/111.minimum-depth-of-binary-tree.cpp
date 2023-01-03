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

int main(int argc, char const *argv[])
{
    auto r = new TreeNode(1);
    r->left = new TreeNode(2);
    r->right = new TreeNode(3);
    r->right->right = new TreeNode(4);
    cout << (new Solution)->minDepth(r) << endl;
    return 0;
}
