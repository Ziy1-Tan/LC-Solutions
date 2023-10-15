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
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 public:
  int pathSum(TreeNode *root, int targetSum) {
    if (!root) {
      return 0;
    }

    int res = rootSum(root, targetSum);
    res += pathSum(root->left, targetSum);
    res += pathSum(root->right, targetSum);
    return res;
  }

 private:
  int rootSum(TreeNode *root, long sum) {
    if (!root) return 0;

    int cnt = 0;
    sum -= root->val;
    if (sum == 0) {
      cnt++;
    }

    cnt += rootSum(root->left, sum);
    cnt += rootSum(root->right, sum);
    return cnt;
  }
};

class Solution2 {
 public:
  int cnt = 0;
  int k = 0;
  // key = 节点的前缀和, val = 前缀和出现的次数
  unordered_map<long, int> prefix{{0L, 1}};
  int pathSum(TreeNode *root, int targetSum) {
    if (!root) {
      return 0;
    }

    this->k = targetSum;
    dfs(root, 0L);
    return cnt;
  }

  void dfs(TreeNode *root, long curr) {
    if (!root) {
      return;
    }

    curr += root->val;
    cnt += prefix[curr - k];
    prefix[curr]++;

    dfs(root->left, curr);
    dfs(root->right, curr);
    prefix[curr]--;
  }
};

int main(int argc, char const *argv[]) {
  auto r = new TreeNode(8);
  r->left = new TreeNode(9);
  r->left->right = new TreeNode(-1);
  auto res = (new Solution2)->pathSum(r, 8);
  cout << res << endl;
  return 0;
}
