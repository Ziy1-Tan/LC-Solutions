// 递归写法
// 返回值，以head为头节点的删除val节点后的链表
// 递归深度，head为NULL时
// 递归操作，判断head的val是否等于目标值，若等于，返回head的next节点，若不等于继续递归
// 时间复杂度O(N)
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
  ListNode *deleteNode(ListNode *head, int val) {
    if (!head)
      return nullptr;

    if (head->val == val) {
      head = head->next;
    } else {
      head->next = deleteNode(head->next, val);
    }

    return head;
  }
};