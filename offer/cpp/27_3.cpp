// 自上而下递归
// 时间复杂度O(N)
// 空间复杂度O(N)
#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode *mirrorTree(TreeNode *root) {
    if (root == nullptr)
      return nullptr;
    swap(root);
    swap(root->left);
    swap(root->right);
    return root;
  }

  void swap(TreeNode *root) {
    if (root == nullptr)
      return;
    auto tmp = root->left;
    root->left = root->right;
    root->right = tmp;
  }
};