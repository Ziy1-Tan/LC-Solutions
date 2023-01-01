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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p || !q)
            return p == q;

        return p->val == q->val &&
               isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
