// stack+中序遍历，中序遍历的过程中生成链表
// 时间复杂度O(N) 需要遍历所有节点
// 空间复杂度O(N)
#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
  int val;
  Node *left;
  Node *right;

  Node() {}

  Node(int _val) {
    val = _val;
    left = NULL;
    right = NULL;
  }

  Node(int _val, Node *_left, Node *_right) {
    val = _val;
    left = _left;
    right = _right;
  }
};
class Solution {
public:
  Node *treeToDoublyList(Node *root) {
    if (!root)
      return nullptr;
    Node *pre = nullptr;
    Node *first = nullptr;
    stack<Node *> stk;

    while (!stk.empty() || root) {
      while (root) {
        stk.push(root);
        root = root->left;
      }

      root = stk.top();
      stk.pop();

      // 若遍历到第一个节点，则保存头节点指针
      if (pre == nullptr) {
        first = root;
        pre = root;
        // 否则生成双向链表
      } else {
        pre->right = root;
        root->left = pre;
        pre = root;
      }

      if (root->right) {
        root = root->right;
      } else {
        root = nullptr;
      }
    }
    // 处理首尾节点
    first->left = pre;
    pre->right = first;
    return first;
  }
};