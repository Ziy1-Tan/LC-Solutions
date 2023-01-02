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
using namespace std;
class Solution
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

private:
    /**
     * post = [[left], [right], rootIdx]
     * in   = [[left], rootIdx, [right]]
     */
    TreeNode *buildTree(const vector<int> &in, int inStart, int inEnd, const vector<int> &post, int postStart, int postEnd)
    {
        if (postStart > postEnd)
            return nullptr;
        TreeNode *root = new TreeNode(post[postEnd]);
        if (postStart == postEnd)
            return root;

        int rootIdx = inStart;
        while (in[rootIdx] != root->val)
            rootIdx++;
        // 切割中序数组
        int lInStart = inStart, lInEnd = rootIdx - 1;
        int rInStart = rootIdx + 1, rInEnd = inEnd;
        // 切割后序数组
        int lPostStart = postStart, lPostEnd = postStart + (rootIdx - inStart - 1);
        int rPostStart = lPostEnd + 1, rPostEnd = postEnd - 1;

        root->left = buildTree(in, lInStart, lInEnd, post, lPostStart, lPostEnd);
        root->right = buildTree(in, rInStart, rInEnd, post, rPostStart, rPostEnd);

        return root;
    }
};
