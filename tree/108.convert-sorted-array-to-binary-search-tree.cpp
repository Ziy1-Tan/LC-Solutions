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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return buildTree(nums, 0, nums.size() - 1);
    }

private:
    TreeNode *buildTree(const vector<int> &nums, int begin, int end)
    {
        if (begin > end)
            return nullptr;

        if (begin == end)
            return new TreeNode(nums[begin]);

        int mid = (begin + end) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = buildTree(nums, begin, mid - 1);
        root->right = buildTree(nums, mid + 1, end);
        return root;
    }
};
