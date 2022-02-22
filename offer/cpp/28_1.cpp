// 递归做法，先比较节点值是否相同，再比较p的左子树和q的右子树、p的右子树和左子树是否相等
// 时间复杂度O(N) 左右子树都退化成链表时最差，
// 空间复杂度O(N) 左右子树退化成链表时递归栈占用N的空间
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
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr)
      return true;
    return isSymetric(root->left, root->right);
  }

private:
  bool isSymetric(TreeNode *p, TreeNode *q) {
    if (p == nullptr && q == nullptr)
      return true;
    if (p == nullptr || q == nullptr)
      return false;

    return p->val == q->val &&
           (isSymetric(p->left, q->right) && isSymetric(p->right, q->left));
  }
};