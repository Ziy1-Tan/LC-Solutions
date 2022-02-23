// 迭代写法
// 时间复杂度O(N)
// 空间复杂度O(N) 平衡二叉树最多有N/2个节点在队列中
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (root == nullptr)
      return res;
    queue<TreeNode *> queue;
    queue.push(root);
    while (!queue.empty()) {
      vector<int> tmp;
      // 遍历每一层的节点个数
      for (size_t i = queue.size(); i > 0; i--) {
        TreeNode *node = queue.front();
        queue.pop();
        tmp.push_back(node->val);
        if (node->left != nullptr)
          queue.push(node->left);
        if (node->right != nullptr)
          queue.push(node->right);
      }
      res.push_back(tmp);
    }
    return res;
  }
};

int main(int argc, const char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  Solution s;
  auto res = s.levelOrder(root);
  for (auto v : res) {
    for (auto e : v) {
      cout << e << " ";
    }
    cout << '\n';
  }
  return 0;
}