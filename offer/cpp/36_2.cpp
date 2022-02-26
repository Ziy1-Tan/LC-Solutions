// 中序遍历递归，用两个指针分别指向头节点和当前节点的前驱节点
// 递归深度，当前节点为null时，说明已经遍历到叶子节点
// 递归过程，先遍历左子树，前驱节点的后继指向当前节点，然后遍历右子树
// 时间复杂度O(N) 需要遍历所有节点
// 空间复杂度O(N) 退化为链表时，递归深度为N
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

    dfs(root);

    head->left = pre;
    pre->right = head;

    return head;
  }

private:
  Node *head, *pre;
  void dfs(Node *cur) {
    if (!cur)
      return;

    //先遍历左子树
    dfs(cur->left);
    //判断是否是第一个遍历到的节点
    if (!pre)
      head = cur;
    //链表新增节点
    else
      pre->right = cur;
      
    cur->left = pre;
    pre = cur;
    //遍历右子树
    dfs(cur->right);
  }
};