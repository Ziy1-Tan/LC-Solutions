// 用hash表保存新旧节点的映射关系
// 然后遍历hash表，重构映射关系
// 时间复杂度O(N) 两次遍历链表
// 空间负责度O(N) 保存新旧链表节点需要2N空间
#include <iostream>
#include <unordered_map>
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
    unordered_map<Node *, Node *> dict;
    // 建立新旧节点的拷贝
    Node *curr = head;
    while (curr) {
      Node *node = new Node(curr->val);
      dict[curr] = node;
      curr = curr->next;
    }
    // 重建next和random指向
    curr = head;
    while (curr) {
      dict[curr]->next = dict[curr->next];
      dict[curr]->random = dict[curr->random];
      curr = curr->next;
    }

    return dict[head];
  }
};