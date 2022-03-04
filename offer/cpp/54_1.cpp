// 按right->root->left的顺序遍历，得到降序序列
// 时间复杂度O(K)
// 空间复杂度O(N) 退化为链表时占用N空间
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
  int kthLargest(TreeNode *root, int k) {
    stack<TreeNode *> stack;
    auto curr = root;
    while (!stack.empty() || curr) {
      while (curr) {
        stack.push(curr);
        curr = curr->right;
      }

      curr = stack.top();
      stack.pop();

      if (--k == 0)
        return curr->val;

      curr = curr->left;
    }

    return -1;
  }
};

int main(int argc, const char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->right = new TreeNode(3);
  cout << Solution().kthLargest(root, 1) << endl;
  return 0;
}