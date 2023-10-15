struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};
#include <iostream>
using namespace std;

class Solution {
 public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode dummy(-1);
    dummy.next = head;
    ListNode *pre = &dummy;
    ListNode *curr = head;
    while (n-- != 0) {
      curr = curr->next;
    }

    while (curr) {
      curr = curr->next;
      pre = pre->next;
    }

    ListNode *next = pre->next;
    pre->next = pre->next->next;
    delete next;

    return dummy.next;
  }
};

int main(int argc, char const *argv[]) {
  auto init_list = [](initializer_list<int> l) -> ListNode * {
    if (l.size() == 0) return nullptr;
    ListNode *head = nullptr;
    ListNode *curr = nullptr;
    for (const auto i : l) {
      if (head == nullptr) {
        head = new ListNode(i);
        curr = head;
      } else {
        curr->next = new ListNode(i);
        curr = curr->next;
      }
    }
    return head;
  };
  ListNode *head = init_list({1, 2});
  Solution s;
  ListNode *ret = s.removeNthFromEnd(head, 1);
  auto print_list = [](ListNode *node) -> void {
    auto curr = node;
    while (curr) {
      cout << curr->val << " ";
      curr = curr->next;
    }
    cout << "\n";
  };
  print_list(ret);
  return 0;
}
