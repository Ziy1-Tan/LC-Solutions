// 递归写法，返回值：以head为头节点的链表的翻转后的头节点
// 结束条件：只剩1或0个节点，直接返回
// 常规操作：递归获得翻转后的头节点，然后head的下一个节点指向head（反转），head的下一个节点为null防止循环
// 时间复杂度O(N) 遍历链表需要线性复杂度时间
// 空间复杂度O(N) 递归深度为N
#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return nullptr;

    // 获取以next节点为原头节点的链表翻转后的头节点
    ListNode *next = reverseList(head->next);
    // head的next节点的next指向head
    head->next->next = head;
    // 防止死循环
    head->next = nullptr;

    return next;
  }
};