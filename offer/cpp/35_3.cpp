// 复制新节点拼接在旧节点之后，之后遍历链表重构random关系，最后将链表一分为二
// 时间复杂度O(N) 三次遍历链表
// 空间负责度O(N) 保存新旧链表节点需要2N空间
#include <iostream>
using namespace std;

class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
public:
  Node *copyRandomList(Node *head) {
    if (!head)
      return nullptr;
    // 遍历链表，复制节点
    Node *curr = head;
    while (curr) {
      Node *tmp = new Node(curr->val);
      tmp->next = curr->next;
      curr->next = tmp;
      curr = tmp->next;
    }
    // 遍历链表，重构random关系
    curr = head;
    while (curr) {
      if (curr->random) {
        curr->next->random = curr->random->next;
      }
      curr = curr->next->next;
    }
    // 遍历链表，将链表一分为二
    Node *src = head, *dst = head->next;
    Node *copyHead = head->next;

    while (dst->next) {
      src->next = src->next->next;
      dst->next = dst->next->next;
      src = src->next;
      dst = dst->next;
    }
    // 单独处理原链表尾节点
    src->next = nullptr;

    return copyHead;
  }
};