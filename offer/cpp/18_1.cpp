#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *deleteNode(ListNode *head, int val) {
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *curr = dummy;

    while (curr->next) {
      if (curr->next->val == val) {
        curr->next = curr->next->next;
        break;
      }
      curr = curr->next;
    }

    return dummy->next;
  }
};