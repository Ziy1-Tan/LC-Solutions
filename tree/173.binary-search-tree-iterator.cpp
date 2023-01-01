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
#include <vector>
#include <stack>
using namespace std;
class BSTIterator
{
public:
    BSTIterator(TreeNode *root) : curr(root)
    {
    }

    int next()
    {
        while (curr)
        {
            stack.push(curr);
            curr = curr->left;
        }
        curr = stack.top();
        stack.pop();
        int x = curr->val;
        curr = curr->right;
        return x;
    }

    bool hasNext()
    {
        return curr || !stack.empty();
    }

private:
    stack<TreeNode *> stack;
    TreeNode *curr;
};

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(15);
    BSTIterator itr(root);
    while (itr.hasNext())
    {
        cout << itr.next() << " ";
    }
    cout << "\n";

    return 0;
}
