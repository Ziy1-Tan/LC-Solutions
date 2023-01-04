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
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

class Solution2
{
public:
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int leftHeight = countHeight(root->left);
        int rightHeight = countHeight(root->right);
        // 左子树深度等于右子树深度, 则左子树是满二叉树
        if (leftHeight == rightHeight)
            return countNodes(root->right) + (1 << leftHeight);
        else
            return countNodes(root->left) + (1 << rightHeight);
    }

private:
    int countHeight(TreeNode *root)
    {
        int height = 0;
        while (root)
        {
            root = root->left;
            height++;
        }
        return height;
    }
};

int main(int argc, char const *argv[])
{
    auto r = new TreeNode(1);
    r->left = new TreeNode(2);
    r->right = new TreeNode(3);
    r->left->left = new TreeNode(4);
    r->left->right = new TreeNode(5);
    cout << (new Solution2)->countNodes(r) << endl;
    return 0;
}
