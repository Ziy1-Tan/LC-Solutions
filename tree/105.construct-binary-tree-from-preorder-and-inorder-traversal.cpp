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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

private:
    /**
     * pre = [rootIdx, [left], [right]]
     * in  = [[left], rootIdx, [right]]
     */
    TreeNode *buildTree(const vector<int> &pre, int preStart, int preEnd, const vector<int> &in, int inStart, int inEnd)
    {
        if (preStart > preEnd)
            return nullptr;
        TreeNode *root = new TreeNode(pre[preStart]);
        if (preStart == preEnd)
            return root;

        int rootIdx = inStart;
        while (in[rootIdx] != root->val)
            rootIdx++;
        // 切割中序数组
        int lInStart = inStart, lInEnd = rootIdx - 1;
        int rInStart = rootIdx + 1, rInEnd = inEnd;
        // 切割前序数组
        int lPreStart = preStart + 1, lPreEnd = preStart + (lInEnd - lInStart + 1);
        int rPreStart = lPreEnd + 1, rPreEnd = preEnd;

        root->left = buildTree(pre, lPreStart, lPreEnd, in, lInStart, lInEnd);
        root->right = buildTree(pre, rPreStart, rPreEnd, in, rInStart, rInEnd);

        return root;
    }
};
