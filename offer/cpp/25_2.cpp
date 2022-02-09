// 递归解法
// 时间复杂度O(M+N)
// 空间复杂度O(M+N)
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
    if (!l1)
      return l2;
    else if (!l2)
      return l1;
    if (l1->val >= l2->val) {
      l2->next = mergeTwoLists(l1, l2->next);
      return l2;
    } else {
      l1->next = mergeTwoLists(l1->next, l2);
      return l1;
    }
  }
};

int main(int argc, const char *argv[]) { return 0; }