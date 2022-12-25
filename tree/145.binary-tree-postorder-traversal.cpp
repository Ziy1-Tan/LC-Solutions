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
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode *> stack;
        while (root != nullptr || !stack.empty())
        {
            while (root != nullptr)
            {
                res.push_back(root->val);
                stack.push(root);
                root = root->right;
            }

            root = stack.top();
            stack.pop();
            root = root->left;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution s;
    auto res = s.preorderTraversal(root);
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
