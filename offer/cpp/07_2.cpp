// 返回值：数组preoder、inorder构成的二叉树根结点
// 操作： 构建根结点，查找根结点值在inorder中的位置，划分为左右子树后继续构建
// 结束条件： 只剩一个节点时返回
#include <iostream>
#include <unordered_map>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
using namespace std;
class Solution {
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.size() == 0)
      return nullptr;
    this->preorder = preorder;
    for (int i = 0; i < inorder.size(); i++) {
      dict[inorder[i]] = i;
    }

    return buildTree(0, 0, inorder.size() - 1);
  }

private:
  unordered_map<int, int> dict;
  vector<int> preorder;

  TreeNode *buildTree(int root, int left, int right) {
    if (left > right)
      return nullptr;

    TreeNode *node = new TreeNode(preorder[root]);
    int i = dict[preorder[root]];
    node->left = buildTree(root + 1, left, i - 1);
    node->right = buildTree(root + (i - left + 1), i + 1, right);
    return node;
  }
};

int main(int argc, const char *argv[]) {
  vector<int> pre{1, 2};
  vector<int> in{1, 2};
  auto node = (new Solution)->buildTree(pre, in);
  cout << node->val << endl;
  // cout << node->left->val << endl;
  cout << node->right->val << endl;
  //   cout << node->right->left->val << endl;
  //   cout << node->right->right->val << endl;
  return 0;
}