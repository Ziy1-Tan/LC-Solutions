// 翻转链表后按序打印
// 时间复杂度O(N)
// 空间复杂度O(N)
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  vector<int> reversePrint(ListNode *head) {
    vector<int> res;
    ListNode *curr = reverseList(head);
    while (curr != nullptr) {
      res.push_back(curr->val);
      curr = curr->next;
    }

    return res;
  }

  ListNode *reverseList(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return head;

    ListNode *next = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return next;
  }
};