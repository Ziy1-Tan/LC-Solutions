struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};
#include <iostream>
using namespace std;

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    int carry = 0;
    while (l1 || l2 || carry != 0) {
      int x = l1 ? l1->val : 0;
      int y = l2 ? l2->val : 0;
      int sum = x + y + carry;

      carry = sum / 10;
      sum = sum % 10;
      curr->next = new ListNode(sum);
      curr = curr->next;
      if (l1) l1 = l1->next;
      if (l2) l2 = l2->next;
    }

    return dummy->next;
  }
};
