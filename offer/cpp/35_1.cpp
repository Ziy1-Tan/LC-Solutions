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
    Node *dummy = new Node(-1);
    Node *dst, *prev = dummy;
    Node *src = head;
    //正常复制过程中复制random
    while (src) {
      dst = new Node(src->val);
      prev->next = dst;
      // prev->random=???
      prev = dst;
      src = src->next;
    }
    return dummy->next;
  }
};