// 递归、也可使用层序遍历
// 时间复杂度O(N) 退化为链表
// 空间复杂度O(N)
#include <algorithm>
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
  int maxDepth(TreeNode *root) {
    if (!root)
      return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
  }
};

int main(int argc, const char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  cout << (new Solution())->maxDepth(root) << endl;
  return 0;
}