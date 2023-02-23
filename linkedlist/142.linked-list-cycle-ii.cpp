struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};
#include <iostream>
using namespace std;
class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head, *slow = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) {
        ListNode *tmp = head;
        while (tmp != slow) {
          tmp = tmp->next;
          slow = slow->next;
        }
        return tmp;
      }
    }
    return nullptr;
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
  ListNode *head = init_list({1, 2, 3});
  head->next->next->next = head;
  Solution s;
  ListNode *ret = s.detectCycle(head);
  cout << (ret ? to_string(ret->val) : "nullptr") << endl;
  return 0;
}
