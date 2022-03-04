// 双指针，设链表A、B长度分别为a,b,相交部分长度为c
// 当链表遍历完链表A后，开始遍历链表B到相交节点时，走的节点数a+(b-c)
// 当链表遍历完链表B后，开始遍历链表A到相交节点时，走的节点数b+(a-c)
// a+b-c=b+a-c
// 时间复杂度O(a+b)
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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

    ListNode *curA = headA, *curB = headB;

    while (curA != curB) {
      curA = (curA != nullptr ? curA->next : headB);
      curB = (curB != nullptr ? curB->next : headA);
    }

    return curA;
  }
};