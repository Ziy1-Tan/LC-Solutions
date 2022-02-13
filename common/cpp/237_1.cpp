#include <cstdlib>
#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  void deleteNode(ListNode *node) {
    // 复制node的next节点的next和val值，
    ListNode *newNext = node->next->next;
    int newVal = node->next->val;
    delete node->next;

    //让当前节点变成next节点
    node->next = newNext;
    node->val = newVal;
  }
};