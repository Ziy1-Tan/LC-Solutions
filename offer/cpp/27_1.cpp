// 自下而上递归
// 时间复杂度O(M) M为树的节点数
// 空间复杂度O(M) 需要新建M个tmp节点，退化为链表时需要M大小栈空间
#include <iostream>
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

    TreeNode *tmp = mirrorTree(root->left);
    root->left = mirrorTree(root->right);
    root->right = tmp;

    return root;
  }
};