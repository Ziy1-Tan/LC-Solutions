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
using namespace std;
class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        return isValidBST(root, numeric_limits<long>().max(),
                          numeric_limits<long>().min());
    }

    bool isValidBST(TreeNode *root, long upper, long lower)
    {
        if (root == nullptr)
        {
            return true;
        }

        if (root->val >= upper || root->val <= lower)
        {
            return false;
        }

        return isValidBST(root->left, root->val, lower) &&
               isValidBST(root->right, upper, root->val);
    }
};

class Solution2
{
public:
    bool isValidBST(TreeNode *root)
    {
        if (!root)
            return true;

        if (!isValidBST(root->left))
            return false;

        if (root->val <= prev)
            return false;
        prev = root->val;

        return isValidBST(root->right);
    }

private:
    long prev = numeric_limits<long>().min();
};

int main(int argc, char const *argv[])
{
    auto tn = [](int val)
    { return new TreeNode(val); };
    auto r = tn(5);
    r->left = tn(4);
    r->right = tn(6);
    r->right->left = tn(3);
    r->right->right = tn(7);
    Solution s;
    cout << s.isValidBST(r) << endl;
    return 0;
}
