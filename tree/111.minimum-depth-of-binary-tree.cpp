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
using namespace std;
class Solution {
 public:
  int minDepth(TreeNode *root) {
    if (!root) {
      return 0;
    }

    int l = minDepth(root->left);
    int r = minDepth(root->right);
    // null节点不参与比较
    if (l == 0) {
      return 1 + r;
    }
    if (r == 0) {
      return 1 + l;
    }

    return 1 + min(l, r);
  }
};

class Solution2 {
 public:
  int minDepth(TreeNode *root) {
    if (!root) {
      return 0;
    }
    queue<TreeNode *> q;
    q.push(root);
    int res = 1;
    while (!q.empty()) {
      int sz = q.size();
      while (sz-- > 0) {
        auto p = q.front();
        q.pop();

        if (!p->left && !p->right) {
          return res;
        }

        if (p->left) {
          q.push(p->left);
        }
        if (p->right) {
          q.push(p->right);
        }
      }
      res++;
    }

    return res;
  }
};

int main(int argc, char const *argv[]) {
  auto r = new TreeNode(1);
  r->left = new TreeNode(2);
  r->right = new TreeNode(3);
  r->right->right = new TreeNode(4);
  cout << (new Solution2)->minDepth(r) << endl;
  return 0;
}
