struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};
#include <iostream>
using namespace std;
class Solution {
 public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;

    int len = 0;
    ListNode *curr = head;
    while (curr != nullptr) {
      curr = curr->next;
      len++;
    }

    ListNode *prev = dummy;
    curr = dummy;
    for (int i = 1; i * k <= len; i++) {
      prev = curr;
      curr = curr->next;
      for (int j = 0; j < k - 1; j++) {
        ListNode *removed = curr->next;
        curr->next = removed->next;

        removed->next = prev->next;
        prev->next = removed;
      }
    }

    return dummy->next;
  }
};

class Solution2 {
 public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;

    // 区间的前驱和最后一个节点
    ListNode *prev = dummy, *end = dummy;

    while (end->next != nullptr) {
      for (int i = 0; i < k && end != nullptr; i++) {
        end = end->next;
      }

      if (end == nullptr) {
        break;
      }

      // 区间的第一和后继节点
      ListNode *start = prev->next, *next = end->next;
      // 重新连接翻转后的区间
      end->next = nullptr;
      prev->next = reverseList(start);
      start->next = next;

      prev = start;
      end = start;
    }

    return dummy->next;
  }

  ListNode *reverseList(ListNode *head) {
    ListNode *prev = nullptr, *curr = head;
    while (curr != nullptr) {
      ListNode *next = curr->next;
      curr->next = prev;

      prev = curr;
      curr = next;
    }

    return prev;
  }
};

int main() {
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
  auto print_list = [](ListNode *node) -> void {
    auto curr = node;
    while (curr) {
      cout << curr->val << " ";
      curr = curr->next;
    }
    cout << "\n";
  };

  ListNode *head = init_list({1, 2, 3, 4, 5});
  Solution2 s;
  ListNode *rev = s.reverseKGroup(head, 2);
  print_list(rev);

  return 0;
}
