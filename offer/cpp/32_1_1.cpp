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
  vector<int> levelOrder(TreeNode *root) {
    vector<int> res;
    if (!root)
      return res;

    queue<TreeNode *> queue;
    queue.push(root);

    while (!queue.empty()) {
      TreeNode *node = queue.front();
      queue.pop();
      res.push_back(node->val);
      if (node->left)
        queue.push(node->left);
      if (node->right)
        queue.push(node->right);
    }

    return res;
  }
};