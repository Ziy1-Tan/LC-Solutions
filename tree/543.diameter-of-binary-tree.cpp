struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
#include <iostream>
using namespace std;
class Solution {
 public:
  int diameterOfBinaryTree(TreeNode *root) {
    dfs(root);
    return res;
  }

 private:
  int res = 0;
  int dfs(TreeNode *root) {
    if (!root) return 0;

    int left = root->left ? dfs(root->left) + 1 : 0;
    int right = root->right ? dfs(root->right) + 1 : 0;
    res = max(res, left + right);

    return max(left, right);
  }
};

int main(int argc, char const *argv[]) {
  auto r = new TreeNode(1);
  r->left = new TreeNode(2);
  r->right = new TreeNode(3);
  r->left->right = new TreeNode(4);
  r->left->left = new TreeNode(5);
  cout << (new Solution)->diameterOfBinaryTree(r) << endl;
  return 0;
}
