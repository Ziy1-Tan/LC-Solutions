// 迭代法，遍历二叉树所有节点，遍历时交换
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
    stack<TreeNode *> stack;
    stack.push(root);

    while (!stack.empty()) {
      TreeNode *node = stack.top();
      stack.pop();

      if (node->left != nullptr)
        stack.push(node->left);
      if (node->right != nullptr)
        stack.push(node->right);

      TreeNode *tmp = node->left;
      node->left = node->right;
      node->right = tmp;
    }
    return root;
  }
};