// 递归+BST
// 返回值：以root为根结点，p、q的最近公共祖先
// 递归深度root=null  root==p || root==q
// 当root的值均小于p和q的值时，说明最近公共祖先在右子树；若均大于p和q时，在左子树
// 当root的值大于p且小于q时，说明当前root就是最近公共祖先
// 时间O(N) 退化为链表时最差
// 空间O(1)
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
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root)
      return root;

    if (root == p || root == q)
      return root;

    // 分别在左右子树中寻找
    auto left = lowestCommonAncestor(root->left, p, q);
    auto right = lowestCommonAncestor(root->right, p, q);

    // p、q分别在左右子树中
    if (left && right) {
      return root;
    }

    // p、q都在右子树
    if (!left)
      return right;
    // p、q都在左子树
    if (!right)
      return left;
    
    return root;
  }
};