// 非递归解法，依次比较两链表节点值
// 时间复杂度O(M+N)需要遍历两链表
// 空间复杂度O(1)
#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode(-1);
    ListNode *curr = dummy;
    while (l1 && l2) {
      if (l1->val >= l2->val) {
        curr->next = l2;
        l2 = l2->next;
      } else {
        curr->next = l1;
        l1 = l1->next;
      }
      curr = curr->next;
    }
    curr->next = l1 ? l1 : l2;
    return dummy->next;
  }
};

int main(int argc, const char *argv[]) { return 0; }