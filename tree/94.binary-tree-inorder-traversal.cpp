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
#include <stack>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    stack<TreeNode *> stack;
    while (root || !stack.empty()) {
      while (root) {
        stack.push(root);
        root = root->left;
      }

      root = stack.top();
      stack.pop();
      res.push_back(root->val);
      root = root->right;
    }

    return res;
  }
};

int main(int argc, char const *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);
  Solution s;
  auto res = s.inorderTraversal(root);
  auto pv = [](const vector<int> res) {
    for (auto &&i : res) {
      cout << i << " ";
    }
    cout << '\n';
  };
  pv(res);
  return 0;
}
