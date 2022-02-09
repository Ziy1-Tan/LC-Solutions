// 返回值：数组preoder、inorder构成的二叉树根结点
// 操作： 构建根结点，查找根结点值在inorder中的位置，划分为左右子树后继续构建
// 结束条件： 只剩一个节点时返回
#include <algorithm>
#include <iostream>
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

    return buildTree(preorder, 0, inorder, 0, inorder.size() - 1);
  }

  TreeNode *buildTree(const vector<int> &pre, int index, const vector<int> &in,
                      int left, int right) {
    if (index >= pre.size() || left > right)
      return nullptr;
    if (index == pre.size() - 1 || left == right)
      return new TreeNode(pre[index]);

    int rootVal = pre[index];
    int rootIndex = -1;
    for (int i = left; i <= right; i++) {
      if (in[i] == rootVal) {
        rootIndex = i;
      }
    }

    if (rootIndex == -1)
      return nullptr;

    TreeNode *root = new TreeNode(rootVal);
    root->left = buildTree(pre, index + 1, in, left, rootIndex - 1);
    root->right = buildTree(pre, index + (rootIndex - left + 1), in,
                            rootIndex + 1, right);
    return root;
  }
};

int main(int argc, const char *argv[]) {
  vector<int> pre{1, 2};
  vector<int> in{1, 2};
  auto node = (new Solution)->buildTree(pre, in);
  cout << node->val << endl;
  cout << node->left->val << endl;
  //   cout << node->right->val << endl;
  //   cout << node->right->left->val << endl;
  //   cout << node->right->right->val << endl;
  return 0;
}