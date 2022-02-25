// 回溯法，需要注意是根结点到叶子节点的路径
// 时间复杂度 O(N) 退化成链表时需要遍历整棵树
// 空间负责度 O(N) 退化成链表时递归深度为N
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
  vector<vector<int>> pathSum(TreeNode *root, int target) {
    this->target = target;
    recur(root, 0);
    return res;
  }

private:
  int target;
  vector<int> path;
  vector<vector<int>> res;
  void recur(TreeNode *curr, int sum) {
    if (!curr)
      return;

    path.push_back(curr->val);

    // 保证叶子节点（注意）
    if (sum + curr->val == target && !curr->left && !curr->right) {
      res.push_back(path);
    }

    recur(curr->left, sum + curr->val);
    recur(curr->right, sum + curr->val);

    // 回溯
    path.pop_back();
  }
};

int main(int argc, const char *argv[]) { return 0; }