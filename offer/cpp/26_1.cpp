// 双层递归，若B是A的子结构，则B中的根结点则可能为A的任意节点
// 先序遍历A，判断以A的节点为根结点的子树是否包含B
// 若B为null,则匹配完成，包含子结构B
// 若A为null或A、B两节点值不相等，则表示A先匹配结束，不包含子结构
// 时间复杂度O(MN)
// 空间复杂度O(M)
// 退化为链表时算法效率最差，M<=N时A的深度和递归深度为M，M>N时遍历到A的叶子节点，递归深度也为M
#include <ios>
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
  bool isSubStructure(TreeNode *A, TreeNode *B) {
    if (A == nullptr || B == nullptr)
      return false;
    return dfs(A, B) || isSubStructure(A->left, B) ||
           isSubStructure(A->right, B);
  }

private:
  bool dfs(TreeNode *A, TreeNode *B) {
    if (B == nullptr)
      return true;
    if (A == nullptr || A->val != B->val)
      return false;

    return A->val == B->val && dfs(A->left, B->left) && dfs(A->right, B->right);
  }
};