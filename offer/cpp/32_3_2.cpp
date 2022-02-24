// 双端队列+BFS，奇数层从尾加入，偶数层从头加入
// 时间复杂度O(N)
// 空间复杂度O(N)
#include <algorithm>
#include <deque>
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
      deque<int> tmp;

      for (size_t i = queue.size(); i > 0; i--) {
        TreeNode *node = queue.front();
        queue.pop();

        if (res.size() % 2 == 0)
          tmp.push_back(node->val);
        else
          tmp.push_front(node->val);

        if (node->left != nullptr)
          queue.push(node->left);
        if (node->right != nullptr)
          queue.push(node->right);
      }

      res.emplace_back(vector<int>(tmp.begin(), tmp.end()));
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