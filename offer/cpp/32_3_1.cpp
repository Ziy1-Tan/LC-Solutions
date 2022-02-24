// BFS+倒序
// 时间复杂度O(N)
// 空间复杂度O(N)
#include <algorithm>
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
    if (root == nullptr) {
      return res;
    }

    queue<TreeNode *> queue;
    queue.push(root);

    while (!queue.empty()) {
      vector<int> tmp;

      for (size_t i = queue.size(); i > 0; i--) {
        TreeNode *node = queue.front();
        queue.pop();
        tmp.push_back(node->val);
        if (node->left != nullptr)
          queue.push(node->left);
        if (node->right != nullptr)
          queue.push(node->right);
      }

      // if (depth % 2 != 0) {
      //   reverse(tmp.begin(), tmp.end());
      // }

      if (res.size() % 2 == 0)
        res.emplace_back(vector<int>(tmp.rbegin(), tmp.rend()));
      else
        res.emplace_back(tmp);
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