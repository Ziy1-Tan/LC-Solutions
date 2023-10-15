struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};
#include <iostream>
using namespace std;
class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) {
      return nullptr;
    }
    ListNode *currA = headA;
    ListNode *currB = headB;
    while (currA != currB) {
      currA = !currA ? headB : currA->next;
      currB = !currB ? headA : currB->next;
    }
    return currA;
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
  ListNode *list1 = init_list({1, 2});
  ListNode *list2 = init_list({1});
  ListNode *ret = new ListNode(3);
  list1->next->next = ret;
  list2->next = ret;
  Solution s;
  cout << (ret == s.getIntersectionNode(list1, list2)) << endl;
  return 0;
}
