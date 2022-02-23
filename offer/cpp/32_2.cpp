// 递归写法
// 时间复杂度O(N)
// 空间复杂度O(N)
#include <functional>
#include <iostream>
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

    function<void(TreeNode *, int)> recur = [&](TreeNode *head, int k) {
      if (head != nullptr) {
        // 结果集中未达到当前遍历到的深度
        if (res.size() <= k) {
          vector<int> tmp;
          res.push_back(tmp);
        }
        res[k].push_back(head->val);
        recur(head->left, k + 1);
        recur(head->right, k + 1);
      }
    };

    recur(root, 0);

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