/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
 */

// @lc code=start
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
class Solution {
 public:
  TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
    if (!root1) {
      return root2;
    }
    if (!root2) {
      return root1;
    }

    root1->val += root2->val;
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);
    return root1;
  }
};

class Solution2 {
 public:
  TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
    if (!root1) {
      return root2;
    }

    if (!root2) {
      return root1;
    }

    queue<TreeNode *> q;
    q.push(root1);
    q.push(root2);
    while (!q.empty()) {
      auto t1 = q.front();
      q.pop();
      auto t2 = q.front();
      q.pop();
      t1->val += t2->val;

      if (t1->left && t2->left) {
        q.push(t1->left);
        q.push(t2->left);
      } else if (!t1->left) {
        t1->left = t2->left;
      }

      if (t1->right && t2->right) {
        q.push(t1->right);
        q.push(t2->right);
      } else if (!t1->right) {
        t1->right = t2->right;
      }
    }
    return root1;
  }
};
// @lc code=end
