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
#include <queue>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (!root) {
      return res;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int cnt = q.size();
      res.push_back({});
      while (cnt-- > 0) {
        TreeNode *node = q.front();
        q.pop();
        res.back().push_back(node->val);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
    }
    return res;
  }
};

class Solution2 {
 public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    bfs(root, 0);
    return res;
  }

 private:
  vector<vector<int>> res;
  void bfs(TreeNode *root, int level) {
    if (!root) return;
    if (level >= res.size()) res.push_back({});
    res[level].push_back(root->val);
    bfs(root->left, level + 1);
    bfs(root->right, level + 1);
  }
};

int main(int argc, char const *argv[]) {
  TreeNode *root = new TreeNode(2);
  root->left = new TreeNode(3);
  root->right = new TreeNode(1);
  Solution2 s;
  auto res = s.levelOrder(root);
  auto pv = [](const vector<int> res) {
    for (auto &&i : res) {
      cout << i << " ";
    }
    cout << '\n';
  };
  for (auto &&v : res) pv(v);

  return 0;
}
