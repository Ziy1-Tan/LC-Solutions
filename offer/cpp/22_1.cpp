// 快慢指针，
#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
  ListNode *getKthFromEnd(ListNode *head, int k) {
    ListNode *p = head, *q = head;
    while (k-- > 0) {
      if (q == nullptr)
        return nullptr;
      q = q->next;
    }

    while (q) {
      q = q->next;
      p = p->next;
    }

    return p;
  }
};

int main(int argc, const char *argv[]) {
  ListNode *root = new ListNode(1);
  root->next = new ListNode(2);
  root->next->next = new ListNode(3);
  auto res = (new Solution())->getKthFromEnd(root, 3);
  cout << res->val << endl;
  return 0;
}