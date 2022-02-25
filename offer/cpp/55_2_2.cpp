// 后序遍历方式
// 时间复杂度O(N) 最差情况需要遍历全部节点
// 空间复杂度O(N) 退化成链表时，递归深度为N
#include <algorithm>
#include <cmath>
#include <cstdlib>
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
  bool isBalanced(TreeNode *root) {
    if (!root)
      return true;

    return recur(root) != -1;
  }

private:
  // 后序遍历
  int recur(TreeNode *root) {
    if (!root)
      return 0;

    int lHeight = recur(root->left);
    // 若左子树不平衡则剪枝
    if (lHeight == -1)
      return -1;
    int rHeight = recur(root->right);
    if (rHeight == -1)
      return -1;
    
    if (abs(lHeight - rHeight) < 2)
      return max(lHeight, rHeight) + 1;
    return -1;
  }
};