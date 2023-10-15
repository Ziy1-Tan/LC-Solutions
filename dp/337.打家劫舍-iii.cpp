/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
 public:
  int rob(TreeNode *root) {
    auto arr = dfs(root);
    return max(arr[0], arr[1]);
  }

  vector<int> dfs(TreeNode *root) {
    if (!root) {
      return {0, 0};
    }
    auto left = dfs(root->left);
    auto right = dfs(root->right);

    // 以root为根节点的树，res[0]当前节点不偷，res[1]当前节点偷取
    vector<int> res(2);
    res[0] = max(left[0], left[1]) + max(right[0], right[1]);
    res[1] = left[0] + root->val + right[0];
    return res;
  }
};
// @lc code=end
